//
// Created by bruce on 27/04/22.
//
#include <iostream>

#include "../inc/SoftPhysics.h"

using namespace mfem;
using namespace std;

void deformation_sim( const char *mesh_file, int order , bool static_cond ,bool visualization ){

    Mesh* mesh = new Mesh(mesh_file, 1, 1);
    int dim = mesh->Dimension();

    if (mesh->attributes.Max() < 2 || mesh->bdr_attributes.Max() < 2)
    {
        cerr << "\nInput mesh should have at least two materials and "
             << "two boundary attributes! (See schematic in ex2.cpp)\n"
             << endl;
        //return 3;
    }

    if (mesh->NURBSext)
    {
        mesh->DegreeElevate(order, order);
    }


    {
        int ref_levels = 5;
        //(int)floor(log(5000. / mesh->GetNE()) / log(2.) / dim);

        for (int l = 0; l < ref_levels; l++)
        {
            mesh->UniformRefinement();
        }
    }

    FiniteElementCollection* fec;
    FiniteElementSpace* fespace;
    if (mesh->NURBSext)
    {
        fec = NULL;
        fespace = mesh->GetNodes()->FESpace();
    }
    else
    {
        fec = new H1_FECollection(order, dim);
        fespace = new FiniteElementSpace(mesh, fec, dim);
    }
    cout << "Number of finite element unknowns: " << fespace->GetTrueVSize()
         << endl << "Assembling: " << flush;


    Array<int> ess_tdof_list, ess_bdr(mesh->bdr_attributes.Max());
    ess_bdr = 0;
    ess_bdr[0] = 1;
    fespace->GetEssentialTrueDofs(ess_bdr, ess_tdof_list);

    VectorArrayCoefficient f(dim);
    for (int i = 0; i < dim - 1; i++)
    {
        f.Set(i, new ConstantCoefficient(0.0));
    }
    {
        Vector pull_force(mesh->bdr_attributes.Max());
        pull_force = 0.0;
        pull_force(1) = -100000.0;
        f.Set(dim - 1, new PWConstCoefficient(pull_force));
    }

    LinearForm* b = new LinearForm(fespace);
    b->AddBoundaryIntegrator(new VectorBoundaryLFIntegrator(f));
    cout << "r.h.s. ... " << flush;
    b->Assemble();


    GridFunction x(fespace);
    x = 0.0;


    double Young = 1.0e+8;
    double Poisson = 0.4;

    double Lambda = Young * Poisson / (1 + Poisson) / (1 - 2 * Poisson);
    double Mu = 0.5 * Young / (1 + Poisson);

    Vector lambda(mesh->attributes.Max());
    lambda = 1.0 * Lambda;
    //lambda(1) = lambda(0) * Lambda;
    PWConstCoefficient lambda_func(lambda);
    Vector mu(mesh->attributes.Max());
    mu = 1.0 * Mu;
    PWConstCoefficient mu_func(mu);

    BilinearForm* a = new BilinearForm(fespace);
    a->AddDomainIntegrator(new ElasticityIntegrator(lambda_func, mu_func));


    cout << "matrix ... " << flush;
    //if (static_cond) { a->EnableStaticCondensation(); }
    a->Assemble();

    SparseMatrix A;
    Vector B, X;
    //cout << "B dimention: " << B.Size() << endl;
    //A.Print();
    cout << "B dimention: " << B.Size() << endl;
    //ess_tdof_list.DeleteAll();
    a->FormLinearSystem(ess_tdof_list, x, *b, A, X, B);
    //A.Print();
    cout << "B dimention: " << B.Size() << endl;

    cout << "done." << endl;

    cout << "Size of linear system: " << A.Height() / 3 << endl;
    cout << "number of dofs is " << ess_tdof_list.Size() / 3 << endl;

    //for
/*    Eigen::SparseMatrix<double, Eigen::RowMajor> Ae(A.Height(), A.Width());
    for (int r = 0; r < A.Height(); r++)
    {
        const int* col = A.GetRowColumns(r);
        const double* val = A.GetRowEntries(r);

        for (int cj = 0; cj < A.RowSize(r); cj++)
        {
            auto tmp = val[cj];
            //B(r, col[cj]) = tmp;
            Ae.insert(r, col[cj]) = tmp;
            //cout << r << endl;
        }
    }

    //Eigen::SparseMatrix<double, Eigen::RowMajor> Ae(A.Height(), A.Width());
    Ae.makeCompressed();

    //============= diect solver ================

    Vector _B = B;
    //_B.SetSize(B.Size() - ess_tdof_list.Size());
    //int j = 0;

    ////ess_tdof_list.Print();
    //for (int i = 0; i < _B.Size(); i++) {
    //    if (i + j == ess_tdof_list[j]) {
    //        j++;
    //    }
    //    _B[i] = B[i + j];
    //}

    //reducing A to _A
     A.GetData();
     DenseMatrix _A = *A.ToDenseMatrix();
    //DenseMatrix _A = DenseMatrix(A.Size() - ess_tdof_list.Size());

    *//*int m = 0;
    int n = 0;

    for (int i = 0; i < _A.Size(); i++) {
        for (int k = 0; k < _A.Size(); k++) {
            if (i + m == ess_tdof_list[m] && k + n == ess_tdof_list[n]) {
                m++;
                n++;
            }
            else if (i + m == ess_tdof_list[m] && k + n != ess_tdof_list[n]) {
                m++;
            }
            else if (i + m != ess_tdof_list[m] && k + n == ess_tdof_list[n]) {
                n++;
            }

            _A.Elem(i, k) = A_d.Elem(i + m, k + n);
        }
        n = 0;
    }*//*
    Vector _X;
    _X.SetSize(_B.Size());

    Eigen::VectorXd Be(_B.Size()), Xe(_B.Size());
    //Eigen::MatrixXd Ae(_A.Size(), _A.Size());
    //cout << "hello1" << endl;
    //for (int i = 0; i < _A.Size(); i++) {
    //    for (int k = 0; k < _A.Size(); k++) {
    //        Ae(i, k) = _A.Elem(i, k);
    //    }
    //}
    //Eigen::SparseMatrix<double> As;
    //As = Ae.sparseView();
    //As.makeCompressed();
    *//*Eigen::JacobiSVD<Eigen::MatrixXd> svd(Ae);
    double cond = svd.singularValues()(0) / svd.singularValues()(svd.singularValues().size() - 1);
    cout << "Condition number is " << cond << endl;*//*

    //cout << "hello2" << endl;
    for (int i = 0; i < _B.Size(); i++) {
        Be(i) = _B.Elem(i);
    }


    // fill A and b;
    // Compute the ordering permutation vector from the structural pattern of A

    //Eigen::SparseQR<Eigen::SparseMatrix<double>, Eigen::COLAMDOrdering<int> >   solver;
    Eigen::SparseLU<Eigen::SparseMatrix<double>, Eigen::COLAMDOrdering<int> >   solver;
    // fill A and b;
    // Compute the ordering permutation vector from the structural pattern of A


    //Eigen::ConjugateGradient<Eigen::SparseMatrix<double>, Eigen::Lower> cg;
    //cg.compute(As);
    //Xe = cg.solve(Be);
    //std::cout << "#iterations:     " << cg.iterations() << std::endl;
    //std::cout << "estimated error: " << cg.error() << std::endl;
    //// update b, and solve again
    //Xe = cg.solve(Be);

    cout << "Solving start: " << endl;
    clock_t begin = clock();
    solver.analyzePattern(Ae);
    // Compute the numerical factorization
    solver.factorize(Ae);
    //Use the factors to solve the linear system
    Xe = solver.solve(Be);
    //cg.compute(As);
    //do{
    //    Xe = cg.solve(Be);
    //    std::cout << "#iterations:     " << cg.iterations() << std::endl;
    //    std::cout << "estimated error: " << cg.error() << std::endl;
    //    // update b, and solve again
    //
    //} while (cg.error() > 1e-8);

    clock_t end = clock();
    float elapsed_secs = float(end - begin) / CLOCKS_PER_SEC;
    cout << endl << "+++++++++++++++++++++++++++++" << endl;
    std::cout << "direct solver time taken: " << elapsed_secs << std::endl;
    cout << "+++++++++++++++++++++++++++++" << endl;


    //cout << "hello4" << endl;
    for (int i = 0; i < _X.Size(); i++) {
        _X[i] = Xe(i);
    }

    //Vector __X;
    //__X.SetSize(_X.Size() + ess_tdof_list.Size());
    //j = 0;
    //for (int i = 0; i < __X.Size(); i++) {
    //    if (i != ess_tdof_list[j]) {
    //        __X[i] = _X[i - j];

    //    }
    //    else {
    //        j++;
    //        __X[i] = 0.0;
    //    }
    //}

    ////=========== end of direct solver ==========*/




#ifndef MFEM_USE_SUITESPARSE
    // 11. Define a simple symmetric Gauss-Seidel preconditioner and use it to
    //     solve the system Ax=b with PCG.
    GSSmoother M(A);
    //cout << "B dimention: " << B.Size() << endl;
    PCG(A, M, B, X, 1, 500, 1e-8, 0.0);
    //cout << "B dimention: " << B.Size() << endl;
#else
    // 11. If MFEM was compiled with SuiteSparse, use UMFPACK to solve the system.
    UMFPackSolver umf_solver;
    umf_solver.Control[UMFPACK_ORDERING] = UMFPACK_ORDERING_METIS;
    umf_solver.SetOperator(A);
    umf_solver.Mult(B, X);
#endif

    // 12. Recover the solution as a finite element grid function.
    a->RecoverFEMSolution(X, *b, x);

    // 13. For non-NURBS meshes, make the mesh curved based on the finite element
    //     space. This means that we define the mesh elements through a fespace
    //     based transformation of the reference element. This allows us to save
    //     the displaced mesh as a curved mesh when using high-order finite
    //     element displacement field. We assume that the initial mesh (read from
    //     the file) is not higher order curved mesh compared to the chosen FE
    //     space.
    if (!mesh->NURBSext)
    {
        mesh->SetNodalFESpace(fespace);
    }
/*    if (true) {
        for (int i = 0; i < x.Size(); i++) {
            x(i) = _X(i);
        }
    }*/

    // 14. Save the displaced mesh and the inverted solution (which gives the
    //     backward displacements to the original grid). This output can be
    //     viewed later using GLVis: "glvis -m displaced.mesh -g sol.gf".
    {
        GridFunction* nodes = mesh->GetNodes();
        *nodes += x;
        x *= -1;
        ofstream mesh_ofs("displaced.mesh");
        mesh_ofs.precision(8);
        mesh->Print(mesh_ofs);
        ofstream sol_ofs("sol.gf");
        sol_ofs.precision(8);
        x.Save(sol_ofs);
    }

    // 15. Send the above data by socket to a GLVis server. Use the "n" and "b"
    //     keys in GLVis to visualize the displacements.
    if (visualization)
    {
        char vishost[] = "localhost";
        int  visport = 19916;
        socketstream sol_sock(vishost, visport);
        sol_sock.precision(8);
        sol_sock << "solution\n" << *mesh << x << flush;
    }

    // 16. Free the used memory.
    delete a;
    delete b;
    if (fec)
    {
        delete fespace;
        delete fec;
    }
    delete mesh;
}
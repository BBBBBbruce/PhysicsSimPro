//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Copyright (c) 2008-2021 NVIDIA Corporation. All rights reserved.

#ifndef RENDERER_MESH_CONTEXT_H
#define RENDERER_MESH_CONTEXT_H

#include <RendererConfig.h>

namespace SampleRenderer
{

	class Renderer;
	class RendererMesh;
	class RendererMaterial;
	class RendererMaterialInstance;

	class RendererMeshContext
	{
		friend class Renderer;
	public:
		const RendererMesh       *mesh;
		RendererMaterial         *material;
		RendererMaterialInstance *materialInstance;
		const physx::PxMat44	 *transform;
		const physx::PxF32		 *shaderData;

		bool					 negativeScale;

		// TODO: this is kind of hacky, would prefer a more generalized
		//       solution via RendererMatrialInstance.
		const physx::PxMat44	 *boneMatrices;
		PxU32                     numBones;

		enum CullMode
		{
			CLOCKWISE = 0,
			COUNTER_CLOCKWISE,
			NONE
		};

		CullMode				cullMode;
		bool					screenSpace;		//TODO: I am not sure if this is needed!

		enum FillMode
		{
			SOLID,
			LINE,
			POINT,
		};
		FillMode				fillMode;

	public:
		RendererMeshContext(void);
		~RendererMeshContext(void);

		bool isValid(void) const;
	};

} // namespace SampleRenderer

#endif

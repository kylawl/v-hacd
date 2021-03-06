#ifndef TEST_HACD_H
#define TEST_HACD_H

#include <stdint.h>
#include "VHACD.h"

namespace RENDER_DEBUG
{
	class RenderDebug;
}

namespace NV_PHYSX_FRAMEWORK
{
	class PhysXFramework;
	enum ConstraintType;
}

class TestHACD
{
public:

	static TestHACD *create(RENDER_DEBUG::RenderDebug *renderDebug,NV_PHYSX_FRAMEWORK::PhysXFramework *physxFramework);

	virtual void toggleSimulation(bool simulateAsRagdoll,
								NV_PHYSX_FRAMEWORK::ConstraintType ctype,
								float limitDistance,
								uint32_t twistLimit,			// Twist limit in degrees (if used)
								uint32_t swing1Limit,			// Swing 1 limit in degrees (if used)
								uint32_t swing2Limit) = 0;		// Swing 2 limit in degrees (if used)

	virtual void decompose(
		const double* const points,
		const uint32_t countPoints,
		const uint32_t* const triangles,
		const uint32_t countTriangles,
		VHACD::IVHACD::Parameters &desc) = 0;

	virtual void render(float explodeViewScale,
						const float center[3],
						bool wireframe,
						bool showConstraints,
						bool showSkeleton,
						bool showCollisionPairs) = 0;

	virtual void getTransform(float xform[16]) = 0;

	virtual uint32_t getHullCount(void) const = 0;
	virtual uint32_t getConstraintCount(void) const = 0;
	virtual uint32_t getCollisionFilterCount(void) const = 0;

	virtual void saveConvexDecomposition(const char *fname,const char *sourceMeshName) = 0;

	virtual bool isSimulating(void) const = 0;

	virtual void cancel(void) = 0;

	virtual void setRenderMesh(uint32_t vcount,
		const float *vertices,
		uint32_t tcount,
		const uint32_t *indices) = 0;

	virtual void release(void) = 0;
protected:
	virtual ~TestHACD(void)
	{
	}
};

#endif

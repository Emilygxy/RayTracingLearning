#pragma once

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{
public:
	sphere() = default;
	~sphere() = default;

	sphere(const point3& center, float radius) : center(center), radius(float(std::fmax(0, radius))) {}
	bool hit(const ray& r, float ray_tmin, float ray_tmax, hit_record& rec) const override;

private:
	point3 center;
	float radius;
};
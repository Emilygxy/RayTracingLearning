#pragma once

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{
public:
	sphere() = default;
	~sphere() = default;

	sphere(const point3& center, float radius, std::shared_ptr<material> mat)
		: center(center), radius(std::fmax(0.0f, radius)), mat(mat) {
	}

	bool hit(const ray& r, interval ray_t, hit_record& rec) const override;

private:
	point3 center;
	float radius;
	std::shared_ptr<material> mat;
};
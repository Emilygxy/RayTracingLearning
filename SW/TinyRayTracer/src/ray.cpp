#include "ray.h"

const point3& ray::origin() const { return orig; }
const vec3& ray::direction() const { return dir; }

point3 ray::at(float t) const {
    return orig + t * dir;
}
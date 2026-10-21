#pragma once

#include "vec3.h"

#include <iostream>


void write_color(std::ostream& out, const color& pixel_color);

float linear_to_gamma(float linear_component);

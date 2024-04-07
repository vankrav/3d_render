#ifndef VECTOR_FUNC_H
#define VECTOR_FUNC_H

#include <math.h>

#include "vector.h"

double clamp(double value, double min, double max) { return fmax(fmin(value, max), min); }
double lenght(v3 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
double lenght(v2 v) { return sqrt(v.x * v.x + v.y * v.y); }
v3 norm(v3 v) { return v / lenght(v); }
double dot(v3 const& a, v3 const& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

v2 sphere(v3 camera, v3 ray, double r) {
    double b = dot(camera, ray);
    double c = dot(camera, camera) - r * r;
    double h = b * b - c;
    if (h < 0.0) return v2(-1.0);
    h = sqrt(h);
    return v2(-b - h, -b + h);
}

#endif
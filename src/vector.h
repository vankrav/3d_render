#ifndef VECTOR_H
#define VECTOR_H

struct v2 {
    double x;
    double y;
    v2(double _value) : x(_value), y(_value) {}
    v2(double _x, double _y) : x(_x), y(_y) {}
    v2 operator+(v2 const& other) { return v2(x + other.x, y + other.y); }
    v2 operator-(v2 const& other) { return v2(x - other.x, y - other.y); }
    v2 operator*(v2 const& other) { return v2(x * other.x, y * other.y); }
    v2 operator/(v2 const& other) { return v2(x / other.x, y / other.y); }
    v2 operator-() { return v2(-x, -y); }
};

struct v3 {
    double x;
    double y;
    double z;
    v3(double _value) : x(_value), y(_value), z(_value) {}
    v3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    v3(double _x, v2 const& v) : x(_x), y(v.x), z(v.y) {}
    v3 operator+(v3 const& other) { return v3(x + other.x, y + other.y, z + other.z); }
    v3 operator-(v3 const& other) { return v3(x - other.x, y - other.y, z - other.z); }
    v3 operator*(v3 const& other) { return v3(x * other.x, y * other.y, z * other.z); }
    v3 operator/(v3 const& other) { return v3(x / other.x, y / other.y, z / other.z); }
    v3 operator/(double value) { return v3(x / value, y / value, z / value); }
    v3 operator-() { return v3(-x, -y, -z); }
};

#endif

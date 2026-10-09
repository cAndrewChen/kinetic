// Your implementation goes here. Read the contract, predict a result, then write it yourself.
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace kinetic {
    struct Vec3 {
        double x;
        double y;
        double z;

        Vec3 operator+(const Vec3& other) const {
            return Vec3{x + other.x, y + other.y, z + other.z};
        }
        
        Vec3& operator+=(const Vec3& other) {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        Vec3 operator-() const {
            return Vec3{-x, -y, -z};
        }

        Vec3 operator-(const Vec3& other) const {
            return Vec3{x - other.x, y - other.y, z - other.z};
        }

        Vec3& operator-=(const Vec3& other) {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        Vec3 operator*(double other) const {
            return Vec3{x * other, y * other, z * other};
        }

        Vec3& operator*=(const double coeff) {
            x *= coeff;
            y *= coeff;
            z *= coeff;
            return *this;
        }

        Vec3 operator/(double other) const {
            if (other == 0.0) {
                throw std::invalid_argument("Cannot divide by zero");
            }
            return Vec3{x / other, y / other, z / other};
        }
        
        bool operator==(const Vec3& origin) const {
            return origin.x == x && origin.y == y && origin.z == z;
        }

        double dot(const Vec3& other) const {
            return x * other.x + y * other.y + z * other.z;
        }

        Vec3 cross(const Vec3& other) const {
            return Vec3{(y * other.z) - (z * other.y), 
                        -((x * other.z) - (z * other.x)), 
                        (x * other.y) - (y * other.x)};
        }

        double length_squared() const {
            return dot(*this);
        }

        double length() const {
            return std::sqrt(length_squared());
        }

        Vec3 normalized() const {
            const double len = length();
            if (length() <= 1e-12) {
                return Vec3{};
            }
            return Vec3{x / len, y / len, z / len};
        }

        void normalize() {
            *this = normalized();
        }

        bool finite() const {
            return std::isfinite(x) && std::isfinite(y) && std::isfinite(z);
        }
    };
    
    inline Vec3 operator*(double scalar, const Vec3& vector) {
        return vector * scalar;
    }

    inline double dot(const Vec3& origin, const Vec3& other) {
        return origin.dot(other);
    }

    inline Vec3 cross(const Vec3& origin, const Vec3& other) {
        return origin.cross(other);
    }
    
    inline Vec3 normalize(const Vec3& origin) {
        return origin.normalized();
    }
    
    inline double length(const Vec3& origin) {
        return origin.length();
    }

    inline Vec3 min(const Vec3& one, const Vec3& two) {
        return Vec3{std::min(one.x, two.x), std::min(one.y, two.y), std::min(one.z, two.z)};
    }

    inline Vec3 max(const Vec3& one, const Vec3& two) {
        return Vec3{std::max(one.x, two.x), std::max(one.y, two.y), std::max(one.z, two.z)};
    }

    inline double component(const Vec3& origin, int ref) {
        switch (ref) {
            case 0:
                return origin.x;
            case 1:
                return origin.y;
            case 2:
                return origin.z;
            default:
                throw std::invalid_argument("Invalid argument");
        }
    }

    inline Vec3 axis(int dim) {
        switch (dim) {
            case 0:
                return Vec3{1,0,0};
            case 1:
                return Vec3{0,1,0};
            case 2:
                return Vec3{0,0,1};
            default:
                throw std::invalid_argument("Invalid argument");
        }
    }
}
#include <xmmintrin.h>
#include <smmintrin.h>
#include <iostream>
#include <cmath>

//task1: create structure with name vector4 which hold 4 elements of type float and operate through SSE instructions
struct vector4 {
private:
    union {
        __m128 vec;
        float f[4];
    };

public:
    vector4(float x, float y, float z) {
        vec = _mm_set_ps(0.0f, z, y, x);
    }

    vector4(float x, float y, float z, float w) {
        vec = _mm_set_ps(w, z, y, x);
    }

    float x() const { return f[0]; }
    float y() const { return f[1]; }
    float z() const { return f[2]; }
    float w() const { return f[3]; }

//task2:Extend the interface of the structure with methods add and sub which perform addition and subtraction of vectors
    vector4& add(const vector4 &other) {
        vec = _mm_add_ps(vec, other.vec);
        return *this;
    }

    vector4& add(float x, float y, float z) {
        vec = _mm_add_ps(vec, _mm_set_ps(0.0f, z, y, x));
        return *this;
    }

    vector4& sub(const vector4 &other) {
        vec = _mm_sub_ps(vec, other.vec);
        return *this;
    }

    vector4& sub(float x, float y, float z) {
        vec = _mm_sub_ps(vec, _mm_set_ps(0.0f, z, y, x));
        return *this;
    }

//task3:Extend the interface of the structure with methods mul and div which perform scale and inverse scale of vector by some scalar
    vector4& mul(float scale) {
        __m128 s = _mm_set_ps(1.0f, scale, scale, scale);
        vec = _mm_mul_ps(vec, s);
        return *this;
    }

    vector4& mul(float scale, float w_scale) {
        __m128 s = _mm_set_ps(w_scale, scale, scale, scale);
        vec = _mm_mul_ps(vec, s);
        return *this;
    }

    vector4& div(float scale) {
        __m128 d = _mm_set_ps(1.0f, scale, scale, scale);
        vec = _mm_div_ps(vec, d);
        return *this;
    }

    vector4& div(float scale, float w_scale) {
        __m128 d = _mm_set_ps(w_scale, scale, scale, scale);
        vec = _mm_div_ps(vec, d);
        return *this;
    }

//task4:Extend the interface of the structure with methods dot which perform dot product of vectors
    vector4& dot(const vector4 &other) {
        __m128 dp = _mm_dp_ps(vec, other.vec, 0xF7);
        vec = _mm_shuffle_ps(dp, dp, 0x00);
        return *this;
    }

    vector4& dot(float x, float y, float z) {
        __m128 other = _mm_set_ps(0.0f, z, y, x);
        __m128 dp = _mm_dp_ps(vec, other, 0xF7);
        vec = _mm_shuffle_ps(dp, dp, 0x00);
        return *this;
    }

//task5:Extend the interface of the structure with methods magnitude and magnitude_square which returns magnitude of vector, and square of magnitude of vector
    float magnitude_square() const {
        __m128 dp = _mm_dp_ps(vec, vec, 0xF7);
        return _mm_cvtss_f32(dp);
    }

    float magnitude() const {
        return std::sqrt(magnitude_square());
    }

//task6:Extend the interface of the structure with methods normalize which normalize current vector
    vector4& normalize() {
        float mag = magnitude();
        if (mag != 0.0f) {
            __m128 scale = _mm_set_ps(1.0f, 1.0f / mag, 1.0f / mag, 1.0f / mag);
            vec = _mm_mul_ps(vec, scale);
        }
        return *this;
    }
};

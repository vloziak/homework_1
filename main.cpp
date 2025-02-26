#include <iostream>
#include <cstdint>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

//task 1
uint32_t to_bytes_float(float value) {
    return *reinterpret_cast<uint32_t*>(&value);
}

float to_float(uint32_t value) {
    return *reinterpret_cast<float*>(&value);
}

uint64_t to_bytes_double(double value) {
    return *reinterpret_cast<uint64_t*>(&value);
}

double to_double(uint64_t value) {
    return *reinterpret_cast<double*>(&value);
}

//task 2
// a) Check if floating-point value is finite value. Refer to isfinite function in C++ language.
bool is_finite_float(float value) { return std::isfinite(value); }
bool is_finite_double(double value) { return std::isfinite(value); }

// b) Check if floating-point value is any infinity value. Refer to isinf function in C++ language.
bool is_infinite_float(float value) { return std::isinf(value); }
bool is_infinite_double(double value) { return std::isinf(value); }

// c) Check if floating-point value is positive infinity value.
bool is_positive_infinity_float(float value) { return std::isinf(value) && value > 0; }
bool is_positive_infinity_double(double value) { return std::isinf(value) && value > 0; }

// d) Check if floating-point value is negative infinity value.
bool is_negative_infinity_float(float value) { return std::isinf(value) && value < 0; }
bool is_negative_infinity_double(double value) { return std::isinf(value) && value < 0; }

// e) Check if floating-point value is any zero value.
bool is_zero_float(float value) { return value == 0.0f; }
bool is_zero_double(double value) { return value == 0.0; }

// f) Check if floating-point value is positive zero value.
bool is_positive_zero_float(float value) { return value == 0.0f && !std::signbit(value); }
bool is_positive_zero_double(double value) { return value == 0.0 && !std::signbit(value); }

// g) Check if floating-point value is negative zero value.
bool is_negative_zero_float(float value) { return value == 0.0f && std::signbit(value); }
bool is_negative_zero_double(double value) { return value == 0.0 && std::signbit(value); }

// h) Check if floating-point value is not a number value.
bool is_nan_float(float value) { return std::isnan(value); }
bool is_nan_double(double value) { return std::isnan(value); }

// i) Check if floating-point value is normal value.
bool is_normal_float(float value) { return std::isnormal(value); }
bool is_normal_double(double value) { return std::isnormal(value); }

// j) Check if floating-point value is subnormal value.
bool is_subnormal_float(float value) { return std::fpclassify(value) == FP_SUBNORMAL; }
bool is_subnormal_double(double value) { return std::fpclassify(value) == FP_SUBNORMAL; }

// k) Check if floating-point value is signed. Refer to signbit function in C++ language.
bool is_signed_float(float value) { return std::signbit(value); }
bool is_signed_double(double value) { return std::signbit(value); }

// l) Classify floating-point value. See fpclassify function in C++ language.
const char* classify_float(float value) {
    switch (std::fpclassify(value)) {
        case FP_INFINITE:  return "infinite";
        case FP_NAN:       return "NaN";
        case FP_NORMAL:    return "normal";
        case FP_SUBNORMAL: return "subnormal";
        case FP_ZERO:      return "zero";
        default:           return "unknown";
    }
}

const char* classify_double(double value) {
    switch (std::fpclassify(value)) {
        case FP_INFINITE:  return "infinite";
        case FP_NAN:       return "NaN";
        case FP_NORMAL:    return "normal";
        case FP_SUBNORMAL: return "subnormal";
        case FP_ZERO:      return "zero";
        default:           return "unknown";
    }
}

//task 3
// a) To get an absolute value of floating-point value. Refer to abs function in C++ language.
float absolute_float(float value) { return std::fabs(value); }
double absolute_double(double value) { return std::fabs(value); }

// b) To get min of two values of floating-point value. Refer to min function in C++ language.
float minimum_float(float a, float b) { return std::min(a, b); }
double minimum_double(double a, double b) { return std::min(a, b); }

// c) To get max of two values of floating-point value. Refer to max function in C++ language.
float maximum_float(float a, float b) { return std::max(a, b); }
double maximum_double(double a, double b) { return std::max(a, b); }

// d) To clamp between two floating-point values. Refer to clamp function in C++ language.
float clamp_value_float(float value, float min_val, float max_val) { return std::clamp(value, min_val, max_val); }
double clamp_value_double(double value, double min_val, double max_val) { return std::clamp(value, min_val, max_val); }

//task 4
// a) Compare two floating-point values for equality with specified precision.
bool is_equal_float(float a, float b, float epsilon) {
    return std::fabs(a - b) < epsilon;
}

bool is_equal_double(double a, double b, double epsilon) {
    return std::fabs(a - b) < epsilon;
}

// b) Compare two arbitrary floating-point values for equality.
bool is_equal_arbitrary_float(float a, float b) {
    return std::fabs(a - b) < std::numeric_limits<float>::epsilon();
}

bool is_equal_arbitrary_double(double a, double b) {
    return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}

// c) Compare two floating-point values for through less operator with specified precision.
bool is_less_float(float a, float b, float epsilon) {
    return (b - a) > epsilon;
}

bool is_less_double(double a, double b, double epsilon) {
    return (b - a) > epsilon;
}

// d) Compare two arbitrary floating-point values through less operator.
bool is_less_arbitrary_float(float a, float b) {
    return a < b;
}

bool is_less_arbitrary_double(double a, double b) {
    return a < b;
}

// e) Compare two floating-point values for greater operator with specified precision.
bool is_greater_float(float a, float b, float epsilon) {
    return (a - b) > epsilon;
}

bool is_greater_double(double a, double b, double epsilon) {
    return (a - b) > epsilon;
}

// f) Compare two arbitrary floating-point values through greater operator.
bool is_greater_arbitrary_float(float a, float b) {
    return a > b;
}

bool is_greater_arbitrary_double(double a, double b) {
    return a > b;
}

int main() {
    return 0;
}
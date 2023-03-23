#pragma once
#ifdef AF_MATH_EXPORTS
#define AF_MATH_API __declspec(dllexport)
#else
#define AF_MATH_API __declspec(dllimport)
#endif

class AF_MATH_API AF_Math {
    public:
        static double reciprocal(double d);
};


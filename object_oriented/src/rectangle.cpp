/**
 *
 *
 *
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>

#include <logging.h>
LOG_TAG(RECT);

#include "rectangle.hpp"

namespace obj {

/**
 * @brief
 * @param width_m
 * @param height_m
 */
obj::rectangle::rectangle(uint64_t width_m, uint64_t height_m) : _w_m(width_m), _h_m(height_m)
{
    LOG_INFO("Rectangle Width = %ld m Height = %ld m", _w_m, _h_m);
    _a_sq_m = area();
    _p_m = perimeter();
    return;
}

/**
 * @brief calculcate area of rectangle
 * @param
 * @return
 */
uint64_t obj::rectangle::area(void)
{
    if (_a_sq_m) {
        return _a_sq_m;
    }

    return _w_m * _h_m;
}

/**
 * @brief calculate perimeter of rectangle
 * @param
 * @return
 */
uint64_t obj::rectangle::perimeter(void)
{
    if (_p_m) {
        return _p_m;
    }

    return (2u * (_w_m + _h_m));
}

} // namespace obj

int main()
{
    obj::rectangle rect(2000u, 4000u);
    LOG_INFO("Area = %ld sq m , Perimeter = %ld m", rect.area(), rect.perimeter());

    rect = obj::rectangle(100u, 100u);
    LOG_INFO("Area = %ld sq m , Perimeter = %ld m", rect.area(), rect.perimeter());

    rect = obj::rectangle(0u, 0u);
    LOG_INFO("Area = %ld sq m , Perimeter = %ld m", rect.area(), rect.perimeter());

    return 0;
}
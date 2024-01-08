/**
 *
 *
 *
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>

namespace obj {

/**
 * @brief
 */
class rectangle {
  private:
    uint64_t _w_m{};
    uint64_t _h_m{};
    uint64_t _a_sq_m{};
    uint64_t _p_m{};

  public:
    /**
     * @brief calculate perimeter of rectangle
     * @param
     * @return
     */
    rectangle(uint64_t width_m, uint64_t height_m);

    /**
     * @brief calculcate area of rectangle
     * @param
     * @return
     */
    uint64_t area(void);

    /**
     * @brief calculate perimeter of rectangle
     * @param
     * @return
     */
    uint64_t perimeter(void);
};

}
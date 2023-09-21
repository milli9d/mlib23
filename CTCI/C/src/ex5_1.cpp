
#include <iostream>
#include <sstream>
#include <cstdint>
#include <bitset>

#include "logging.h"
LOG_TAG(EX5_1);

namespace bit_manip {

class bitset {
  private:
    uint8_t* _data;
    size_t sz;
    size_t num_bytes;

  public:
    bitset(size_t size) : sz(size) {
        /* allocate memory */
        num_bytes = size / 8u;
        if (size % 8u) {
            num_bytes++;
        }
        _data = (uint8_t*) calloc(sizeof(uint8_t), num_bytes);

        LOG_INFO("%s : Size = %d , Num_bytes = %d", __func__, sz, num_bytes);
    }

    ~bitset() {
        free(_data);
    }

    void set(size_t idx, bool val) {
        /* sanity check */
        if (idx > sz) {
            LOG_ERR("Invalid index");
            return;
        }

        size_t byte_idx = idx / 8u;
        size_t bit_offset = idx % 8u;

        if (val) {
            /* set bit */
            _data[byte_idx] |= (1u << bit_offset);
        } else {
            _data[byte_idx] &= ~(1u << bit_offset);
        }
    }

    void set_byte_mask(size_t byte_idx, uint8_t mask) {
        if (byte_idx >= sz) {
            LOG_ERR("Index out of range");
            return;
        }

        /* clear byte */
        _data[byte_idx] &= 0b0000'0000;
        _data[byte_idx] |= mask;
    }

    void print() {
        std::stringstream ss{};
        for (ssize_t i = num_bytes - 1u; i >= 0u; i--) {
            std::bitset<8u> temp(_data[i]);
            ss << temp << " ";
        }
        std::cout << ss.str() << std::endl;
    }
};

} // namespace bit_manip

int main(int argc, char** argv) {
    LOG_PASS("BIT MANIPULATION");
    bit_manip::bitset test = bit_manip::bitset(18u);

    test.set(0u, 1u);
    test.set(56u, 1u);
    test.set(12u, 1u);

    test.print();

    return 0;
}

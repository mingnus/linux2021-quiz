#include <assert.h>
#include <stdint.h>

#define __DECLARE_ROTATE(bits, type)                            \
    static inline type rotl##bits(const type v, int c)          \
    {                                                           \
        const int mask = (bits) - (1);                          \
        c &= mask;                                              \
                                                                \
        return (v << c) | (v >> (-c & mask));                   \
    }                                                           \
                                                                \
    static inline type rotr##bits(const type v, int c)          \
    {                                                           \
        const int mask = (bits) - (1);                          \
        c &= mask;                                              \
                                                                \
        return (v >> c) | (v << (-c & mask));                   \
    }                                                           \
                                                                \
    static inline type rotl##bits##_simple(const type v, int c) \
    {                                                           \
        const int mask = (bits) - (1);                          \
        c &= mask;                                              \
                                                                \
        return (v << c) | (v >> (bits - c));                    \
    }                                                           \
                                                                \
    static inline type rotr##bits##_simple(const type v, int c) \
    {                                                           \
        const int mask = (bits) - (1);                          \
        c &= mask;                                              \
                                                                \
        return (v >> c) | (v << (bits - c));                    \
    }

#define DECLARE_ROTATE(bits) __DECLARE_ROTATE(bits, uint##bits##_t)

DECLARE_ROTATE(8);
DECLARE_ROTATE(32);

void test_rot8()
{
    assert(rotr8(150, 2) == 165);
    assert(rotr8_simple(150, 2) == 165);

    assert(rotr8(150, 18) == 165);
    assert(rotr8_simple(150, 18) == 165);

    assert(rotl8(150, 3) == 180);
    assert(rotl8_simple(150, 3) == 180);

    assert(rotr8(150, -3) == 180);
    assert(rotr8_simple(150, -3) == 180);
}

void test_rot32()
{
    assert(rotr32(150, 2) == 2147483685);
    assert(rotr32_simple(150, 2) == 2147483685);

    assert(rotr32(150, 66) == 2147483685);
    assert(rotr32_simple(150, 66) == 2147483685);

    assert(rotl32(150, 3) == 1200);
    assert(rotl32_simple(150, 3) == 1200);

    assert(rotr32(150, -3) == 1200);
    assert(rotr32_simple(150, -3) == 1200);
}

int main(int argc, char *argv[])
{
    test_rot8();
    test_rot32();
    return 0;
}

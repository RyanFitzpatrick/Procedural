#include "Noise.h"

uint16_t Perlin(uint32_t x, uint32_t y)
{
    return (x * y) & UINT16_MAX;
}
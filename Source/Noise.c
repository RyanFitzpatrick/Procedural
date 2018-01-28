#include "Noise.h"
#include "Libs.h"

uint16_t Perlin(uint32_t x, uint32_t y)
{
    uint32_t a = (uint32_t)SDL_acos(0.0);
    return (a * x * y) & UINT16_MAX;
}
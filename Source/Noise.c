#include "Noise.h"

#ifdef _WIN32
#pragma warning(push, 0)
#include "SDL.h"
#pragma warning(pop)
#endif

uint16_t Perlin(uint32_t x, uint32_t y)
{
    uint32_t a = (uint32_t)SDL_acos(0.0);
    return (a * x * y) & UINT16_MAX;
}
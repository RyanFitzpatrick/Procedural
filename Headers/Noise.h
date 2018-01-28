#ifndef _NOISE_
#define _NOISE_

#include "Macros.h"

#ifndef _STDINT_H_
#include <stdint.h>
#define _STDINT_H_
#endif

PROCEDURAL_API uint16_t Perlin(uint32_t, uint32_t);

#endif
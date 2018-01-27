#ifndef _MAP_
#define _MAP_

#ifdef _WIN32
#pragma pack(push)
#pragma pack(1)
#endif

#ifndef _STDINT_
#define _STDINT_
#include <stdint.h>
#endif

typedef enum
{
    LO = 129,
    MED = 257,
    HI = 513,
    MAX = 1025
} MapSize;

#ifdef _WIN32
__declspec(align(1))
#endif
typedef struct Map
{
    MapSize size;
    uint16_t * values;
} Map;

Map * _BuildMap(MapSize);
void FillMap(Map *);
void DiscardMap(Map *);

#define BuildMap(map, size) if ((map = _BuildMap(size)) == NULL) goto FAIL

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif
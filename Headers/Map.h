#ifndef _MAP_
#define _MAP_

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

typedef struct Map
{
    MapSize size;
    uint16_t * values;
} Map;

Map * _BuildMap(MapSize);
void FillMap(Map *);
void DiscardMap(Map *);

#define BuildMap(map, size) if ((map = _BuildMap(size)) == NULL) goto FAIL

#endif
#include "Map.h"
#include "Memory.h"
#include "Noise.h"

Map * _BuildMap(MapSize size)
{
    Map * map = NULL;
    uint32_t len = (uint32_t)(size);

    len *= len;
    NewMem(map, sizeof(Map));
    NewMem(map->values, sizeof(uint16_t) * len);

    map->size = size;
    FillMap(map);

    return map;

    FAIL:
        DiscardMap(map);
        return NULL;
}

void FillMap(Map * map)
{
    uint32_t x, y, index = 0, size = (uint32_t)(map->size);

    for (x = 0; x < size; ++x)
    {
        for (y = 0; y < size; ++y)
            map->values[index++] = Perlin(x, y);
    }
}

void DiscardMap(Map * map)
{
    if (map)
    {
        DiscardMem(map->values);
        DiscardMem(map);
    }
}
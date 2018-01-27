#include "Procedural.h"
#include <stdio.h>

#define Say(word) puts(word); getchar();

int main(void)
{
    TriTree * tree = NULL;
    Map * map = NULL;

    BuildTriTree(tree);
    DiscardTriTree(tree);

    BuildMap(map, MAX);
    DiscardMap(map);
    Say("Hi\n");

    return 0;

    FAIL:
        Say("FAIL\n");
        return 0;
}
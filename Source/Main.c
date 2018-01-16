#include "Map.h"
#include "TriTree.h"
#include <stdio.h>

#define Say(word) printf(word); getchar();

int main()
{
    TriTree * tree = NULL;
    Map * map = NULL;

    BuildTriTree(tree);
    DiscardTriTree(tree);

    BuildMap(map, LO);
    DiscardMap(map);
    Say("Hi\n");

    return 0;

    FAIL:
        Say("FAIL\n");
        return 0;
}
#include "TriTree.h"
#include <stdio.h>

#define Say(word) printf(word); getchar();

int main()
{
    TriTree * tree = NULL;

    BuildTriTree(tree);
    Say("Hi\n")
    DiscardTriTree(tree);

    return 0;

    FAIL:
        Say("FAIL\n");
        return 0;
}
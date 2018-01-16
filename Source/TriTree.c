#include "TriTree.h"
#include "Memory.h"

TriTree * _BuildTriTree()
{
    TriTree * tree = NULL;

    NewMem(tree, sizeof(TriTree));
    tree->sides[BOTTOM] = NULL;
    tree->sides[LEFT] = NULL;
    tree->sides[RIGHT] = NULL;
    tree->left = NULL;
    tree->right = NULL;

    return tree;

    FAIL:
        return NULL;
}

void DiscardTriTree(TriTree * tree)
{
    if (tree == NULL)
        return;

    DiscardTriTree(tree->left);
    DiscardTriTree(tree->right);
    DiscardMem(tree);
}
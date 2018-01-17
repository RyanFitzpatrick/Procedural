/* TriTree.c: Implements various functions defined in TriTree.h */

#include "TriTree.h"
#include "Memory.h"

/* Force splits a binary triangle tree node into 2 triangles */
/* Param1 (TriTree *): A pointer to the binary triangle tree node to be split */
/* Returns (int): 1 if split was successful, 0 otherwise */
static int Force(TriTree *);

/* Initalizes a new binary triangle tree */
/* NOTE: It's recommended to use the BuildTriTree macro instead of calling this directly */
/* Returns (TriTree *): A pointer to a newly allocated binary triangle tree, or NULL on error */
TriTree * _BuildTriTree(void)
{
    TriTree * tree = NULL;

    /* Allocate memory for the binary triangle tree and give it's fields default values */
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

/* Splits a binary triangle tree node into 2 new triangles */
/* NOTE: It's recommended to use the SplitTriTree macro instead of calling this directly */
/* Param (TriTree *) tree: A pointer to the binary triangle tree node to be split */
/* Returns (int): 1 if split was successful, 0 otherwise */
int _SplitTriTree(TriTree * tree)
{
    if (tree->sides[BOTTOM])
    {
        /* Determine if we need to recursively split the bottom triangle to avoid mesh cracks */
        if (tree->sides[BOTTOM]->sides[BOTTOM] != tree)
            SplitTriTree(tree->sides[BOTTOM]);

        /* Split the current node and it's bottom side neighbour */
        if (!Force(tree)) goto FAIL;
        if (!Force(tree->sides[BOTTOM])) goto FAIL;

        /* Update the sides of the new triangles */
        tree->left->sides[RIGHT] = tree->sides[BOTTOM]->right;
        tree->right->sides[LEFT] = tree->sides[BOTTOM]->left;
        tree->sides[BOTTOM]->left->sides[RIGHT] = tree->right;
        tree->sides[BOTTOM]->right->sides[LEFT] = tree->left;
    }
    else
    {
        /* If the current node has no bottom neighbour then a basic forced split will suffice */
        if (!Force(tree)) goto FAIL;
        tree->left->sides[RIGHT] = NULL;
        tree->right->sides[LEFT] = NULL;
    }

    return 1;

    FAIL:
        return 0;
}

/* Force splits a binary triangle tree node into 2 triangles */
/* Param (TriTree *) tree: A pointer to the binary triangle tree node to be split */
/* Returns (int): 1 if split was successful, 0 otherwise */
static int Force(TriTree * tree)
{
    /* Initialize the 2 new triangles */
    BuildTriTree(tree->left);
    BuildTriTree(tree->right);

    /* Update the new triangle sides */
    tree->left->sides[LEFT] = tree->right;
    tree->right->sides[RIGHT] = tree->left;
    tree->left->sides[BOTTOM] = tree->sides[LEFT];
    tree->right->sides[BOTTOM] = tree->sides[RIGHT];

    /* Update the node's left neighbour */
    if (tree->sides[LEFT])
    {
        if (tree->sides[LEFT]->sides[BOTTOM] == tree)
            tree->sides[LEFT]->sides[BOTTOM] = tree->left;
        else if (tree->sides[LEFT]->sides[LEFT] == tree)
            tree->sides[LEFT]->sides[LEFT] = tree->left;
        else
            tree->sides[LEFT]->sides[RIGHT] = tree->left;
    }

    /* Update the node's right neighbour */
    if (tree->sides[RIGHT])
    {
        if (tree->sides[RIGHT]->sides[BOTTOM] == tree)
            tree->sides[RIGHT]->sides[BOTTOM] = tree->right;
        else if (tree->sides[RIGHT]->sides[RIGHT] == tree)
            tree->sides[RIGHT]->sides[RIGHT] = tree->right;
        else
            tree->sides[RIGHT]->sides[LEFT] = tree->right;
    }

    return 1;

    FAIL:
        return 0;
}

/* Frees all memory used by a binary triangle tree */
/* Param (TriTree *) tree: A pointer to the binary triangle tree to be freed */
void DiscardTriTree(TriTree * tree)
{
    /* Recursively traverse the binary triangle tree and free all nodes */
    if (tree)
    {
        DiscardTriTree(tree->left);
        DiscardTriTree(tree->right);
        DiscardMem(tree);
    }
}
#include "TriTree.h"
#include "Memory.h"

static int Force(TriTree *);

TriTree * _BuildTriTree(void)
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

int _SplitTriTree(TriTree * tree)
{
    if (tree->sides[BOTTOM])
    {
        if (tree->sides[BOTTOM]->sides[BOTTOM] != tree)
            _SplitTriTree(tree->sides[BOTTOM]);

        if (!Force(tree)) goto FAIL;
        if (!Force(tree->sides[BOTTOM])) goto FAIL;

        tree->left->sides[RIGHT] = tree->sides[BOTTOM]->right;
        tree->right->sides[LEFT] = tree->sides[BOTTOM]->left;
        tree->sides[BOTTOM]->left->sides[RIGHT] = tree->right;
        tree->sides[BOTTOM]->right->sides[LEFT] = tree->left;
    }
    else
    {
        if (!Force(tree)) goto FAIL;
        tree->left->sides[RIGHT] = NULL;
        tree->right->sides[LEFT] = NULL;
    }

    return 1;

    FAIL:
        return 0;
}

static int Force(TriTree * tree)
{
    BuildTriTree(tree->left);
    BuildTriTree(tree->right);

    tree->left->sides[LEFT] = tree->right;
    tree->right->sides[RIGHT] = tree->left;
    tree->left->sides[BOTTOM] = tree->sides[LEFT];

    if (tree->sides[LEFT])
    {
        if (tree->sides[LEFT]->sides[BOTTOM] == tree)
            tree->sides[LEFT]->sides[BOTTOM] = tree->left;
        else if (tree->sides[LEFT]->sides[LEFT] == tree)
            tree->sides[LEFT]->sides[LEFT] = tree->left;
        else
            tree->sides[LEFT]->sides[RIGHT] = tree->left;
    }

    tree->right->sides[BOTTOM] = tree->sides[RIGHT];

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

void DiscardTriTree(TriTree * tree)
{
    if (tree == NULL)
        return;

    DiscardTriTree(tree->left);
    DiscardTriTree(tree->right);
    DiscardMem(tree);
}
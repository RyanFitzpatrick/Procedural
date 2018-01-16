#ifndef _TRITREE_
#define _TRITREE_

#define BOTTOM 0
#define LEFT 1
#define RIGHT 2

typedef struct TriTree
{
    struct TriTree * sides[3];
    struct TriTree * left;
    struct TriTree * right;
} TriTree;

TriTree * _BuildTriTree();
int _SplitTriTree(TriTree *);
void DiscardTriTree(TriTree *);

#define BuildTriTree(tree) if ((tree = _BuildTriTree()) == NULL) goto FAIL
#define SplitTriTree(tree) if (!_SplitTriTree(tree)) goto FAIL

#endif
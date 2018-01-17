/* TriTree.h: Defines the TriTree type as well various function prototypes and macros to be used with this type */

#ifndef _TRITREE_
#define _TRITREE_

/* A constant rerpresenting the index in a TriTree's sides array that corresponds to the bottom side */
#define BOTTOM 0
/* A constant rerpresenting the index in a TriTree's sides array that corresponds to the left side */
#define LEFT 1
/* A constant rerpresenting the index in a TriTree's sides array that corresponds to the right side */
#define RIGHT 2

/* The structure used to represent a binary triangle tree */
typedef struct TriTree
{
    /* An array containing pointers to a triangle's 3 neighbours */
    struct TriTree * sides[3];
    /* A triangle's left child */
    struct TriTree * left;
    /* A triangle's right child */
    struct TriTree * right;
} TriTree;

/* Initalizes a new binary triangle tree */
/* NOTE: It's recommended to use the BuildTriTree macro instead of calling this directly */
/* Returns (TriTree *): A pointer to a newly allocated binary triangle tree, or NULL on error */
TriTree * _BuildTriTree(void);

/* Splits a binary triangle tree node into 2 new triangles */
/* NOTE: It's recommended to use the SplitTriTree macro instead of calling this directly */
/* Param1 (TriTree *): A pointer to the binary triangle tree node to be split */
/* Returns (int): 1 if split was successful, 0 otherwise */
int _SplitTriTree(TriTree *);

/* Frees all memory used by a binary triangle tree */
/* Param1 (TriTree *): A pointer to the binary triangle tree to be freed */
void DiscardTriTree(TriTree *);

/* Calls _BuildTriTree to initalize a binary triangle tree and handles any errors */
/* NOTE: This macro jumps to the FAIL label on error, so the calling code must have a FAIL label */
/* Param1 (TriTree *) tree: A pointer to the binary triangle tree to be initalized */
#define BuildTriTree(tree) if ((tree = _BuildTriTree()) == NULL) goto FAIL

/* Calls _SplitTriTree to split a binary triangle tree and handles any errors */
/* NOTE: This macro jumps to the FAIL label on error, so the calling code must have a FAIL label */
/* Param1 (TriTree *) tree: A pointer to the binary triangle tree to be split */
#define SplitTriTree(tree) if (!_SplitTriTree(tree)) goto FAIL

#endif
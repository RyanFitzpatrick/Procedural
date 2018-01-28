/* Memory.h: Defines various macros used for memory management */

#ifndef _MEMORY_
#define _MEMORY_

/* Memory.h requires the errno variable and codes defined in errno.h */
#ifndef _ERRNO_H_
#include <errno.h>
#define _ERRNO_H_
#endif

/* Memory.h requires the malloc and free functions defined in stdlib.h */
#ifndef _STDLIB_H_
#include <stdlib.h>
#define _STDLIB_H_
#endif

/* Allocates a new pointer using malloc */
/* NOTE: If malloc fails this macro will jump to the FAIL label, so the calling code must have a FAIL label */
/* Param1 ptr: The pointer to be allocated */
/* Param2 size: The size of the memory to point at, clean up with DiscardMem */
#define NewMem(ptr, size) ptr = malloc(size); if (errno == ENOMEM) goto FAIL

/* Resizes a pointer using realloc */
/* NOTE: If realloc fails this macro will jump to the FAIL label, so the calling code must have a FAIL label */
/* Param1 ptr: The pointer to be reallocated */
/* Param2 size: The size of the memory to point at, clean up with DiscardMem */
#define ResizeMem(ptr, size) \
{ \
    void * __ResizeMem__ = NULL; \
    __ResizeMem__ = realloc(ptr, size); \
    if (errno == ENOMEM) goto FAIL; \
    ptr = __ResizeMem__; \
}

/* Releases a pointer using free */
/* Param1 ptr: The pointer to be released */
#define DiscardMem(ptr) free(ptr)

#endif

#ifndef _MACROS_
#define _MACROS_

#ifdef _WIN32
 #ifdef PROCEDURAL
  #define PROCEDURAL_API __declspec(dllexport)
 #else
  #define PROCEDURAL_API __declspec(dllimport)
 #endif
#else
 #define PROCEDURAL_API
#endif

#endif
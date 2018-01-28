#ifndef _LIBS_
#define _LIBS_

#ifndef SDL_h_
 #ifdef _WIN32
  #pragma warning(push, 0)
  #include "SDL.h"
  #pragma warning(pop)
 #else
  #include "SDL.h"
 #endif
#define SDL_h_
#endif

#endif
/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org>
*/

#pragma once

#include <plcore/pl_filesystem.h>

#ifdef _DEBUG
#   define FSLog(...) PlLogMessage(LOG_LEVEL_FILESYSTEM, __VA_ARGS__)
#else
#   define FSLog(...)
#endif

#if defined(_WIN32)
#   define _pl_mkdir(a) _mkdir((a))
#else
#   define _pl_mkdir(a) mkdir((a), 0777)
#endif

#define _pl_fclose(a)  fclose((a)); (a) = NULL

typedef struct PLFile {
	char		path[ PL_SYSTEM_MAX_PATH ];
	uint8_t		*data;
	uint8_t		*pos;
	size_t		size;
	time_t		timeStamp;
	void		*fptr;
} PLFile;

const char *PlResolveVirtualPath_( const char *path, char *dest, size_t size );

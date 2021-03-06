/*
  Copyright (c) 2019-2020, Andrea Fioraldi


  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __QASAN_H__
#define __QASAN_H__

#include <stdio.h>
#include <unistd.h>

#define QASAN_VERSTR "0.1"

#ifdef DEBUG
#define QASAN_LOG(msg...) do { \
  if (__qasan_debug) { \
    fprintf(stderr, "==%d== ", getpid()); \
    fprintf(stderr, msg); \
  } \
} while (0)
#else
#define QASAN_LOG(msg...) do {} while (0)
#endif

#define QASAN_FAKESYS_NR 0xa2a4

enum {
  QASAN_ACTION_CHECK_LOAD,
  QASAN_ACTION_CHECK_STORE,
  QASAN_ACTION_MALLOC_USABLE_SIZE,
  QASAN_ACTION_MALLOC,
  QASAN_ACTION_CALLOC,
  QASAN_ACTION_REALLOC,
  QASAN_ACTION_POSIX_MEMALIGN,
  QASAN_ACTION_MEMALIGN,
  QASAN_ACTION_ALIGNED_ALLOC,
  QASAN_ACTION_VALLOC,
  QASAN_ACTION_PVALLOC,
  QASAN_ACTION_FREE,
  QASAN_ACTION_MEMCMP,
  QASAN_ACTION_MEMCPY,
  QASAN_ACTION_MEMMOVE,
  QASAN_ACTION_MEMSET,
  QASAN_ACTION_STRCHR,
  QASAN_ACTION_STRCASECMP,
  QASAN_ACTION_STRCAT,
  QASAN_ACTION_STRCMP,
  QASAN_ACTION_STRCPY,
  QASAN_ACTION_STRDUP,
  QASAN_ACTION_STRLEN,
  QASAN_ACTION_STRNCASECMP,
  QASAN_ACTION_STRNCMP,
  QASAN_ACTION_STRNCPY,
  QASAN_ACTION_STRNLEN,
};

extern int __qasan_debug;

#endif

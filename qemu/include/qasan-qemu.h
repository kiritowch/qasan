#ifndef __QASAN_QEMU_H__
#define __QASAN_QEMU_H__

#define _GNU_SOURCE
#include <malloc.h>
#include "../../include/qasan.h"
#include "tcg.h"

#define HEAP_PAD 16

void __asan_poison_memory_region(void const volatile *addr, size_t size);
void __asan_unpoison_memory_region(void const volatile *addr, size_t size);

void __asan_load1(void*);
void __asan_load2(void*);
void __asan_load4(void*);
void __asan_load8(void*);
void __asan_store1(void*);
void __asan_store2(void*);
void __asan_store4(void*);
void __asan_store8(void*);
void __asan_loadN(void*, size_t);
void __asan_storeN(void*, size_t);

void *__asan_memcpy(void *, void *, size_t);
void *__asan_memmove(void *, const void *, size_t);
void *__asan_memset(void *, int, size_t);

size_t __interceptor_malloc_usable_size (void * ptr);
void * __interceptor_malloc(size_t size);
void * __interceptor_calloc(size_t nmemb, size_t size);
void * __interceptor_realloc(void *ptr, size_t size);
int __interceptor_posix_memalign(void **memptr, size_t alignment, size_t size);
void * __interceptor_memalign(size_t alignment, size_t size);
void * __interceptor_aligned_alloc(size_t alignment, size_t size);
void * __interceptor_valloc(size_t size);
void * __interceptor_pvalloc(size_t size);
void __interceptor_free(void * ptr);
int __interceptor_memcmp(const void *s1, const void *s2, size_t n);
void * __interceptor_memmove(void *s1, const void *s2, size_t n);
char * __interceptor_strchr(const char *s, int c);
int __interceptor_strcasecmp(const char *s1, const char *s2);
char * __interceptor_strcat(char *dest, const char *src);
int __interceptor_strcmp(const char *s1, const char *s2);
char * __interceptor_strcpy(char *dest, const char *src);
char * __interceptor_strdup(const char *s);
size_t __interceptor_strlen(const char *s);
int __interceptor_strncasecmp(const char *s1, const char *s2, size_t n);
int __interceptor_strncmp(const char *s1, const char *s2, size_t n);
char * __interceptor_strncpy(char *dest, const char *src, size_t n);
size_t __interceptor_strnlen(const char *s, size_t n);

static abi_long qasan_fake_syscall(abi_long action, abi_long arg1,
                    abi_long arg2, abi_long arg3, abi_long arg4,
                    abi_long arg5, abi_long arg6, abi_long arg7);

extern __thread int cur_block_is_good;

// TODO collapse into a macro

void qasan_gen_load1(TCGv_ptr ptr, int off);
void qasan_gen_load2(TCGv_ptr ptr, int off);
void qasan_gen_load4(TCGv_ptr ptr, int off);
void qasan_gen_load8(TCGv_ptr ptr, int off);
void qasan_gen_store1(TCGv_ptr ptr, int off);
void qasan_gen_store2(TCGv_ptr ptr, int off);
void qasan_gen_store4(TCGv_ptr ptr, int off);
void qasan_gen_store8(TCGv_ptr ptr, int off);

#endif

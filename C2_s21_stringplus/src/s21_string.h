#ifndef S21_STRING_H
#define S21_STRING_H
#include <stdio.h>
#include <stdlib.h>
#if __linux__
#include "s21_linux_errors.h"
#elif __APPLE__
#include "s21_mac_errors.h"
#endif

// Size_t
typedef long unsigned int s21_size_t;

// NULL
#define S21_NULL (void *)0

#define BUFF_SIZE 1024

// Base functions
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c) __attribute__((nonnull(1)));
int s21_strncmp(const char *str1, const char *str2, s21_size_t n)
    __attribute__((nonnull(1, 2)));
char *s21_strncpy(char *dest, const char *src, s21_size_t n)
    __attribute__((nonnull(1, 2)));
s21_size_t s21_strcspn(const char *str1, const char *str2)
    __attribute__((nonnull(1, 2)));
char *s21_strerror(int errnum);

s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

// sprintf Function

int s21_sprintf(char *str, const char *format, ...)
    __attribute__((format(printf, 2, 3)));

// Additional Functions
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif

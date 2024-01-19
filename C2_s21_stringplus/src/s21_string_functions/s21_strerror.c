#include "../s21_string.h"

char *s21_strerror(int errnum) {
  static char result[MAX_ERROR_LEN] = "";
  char strErrnum[512];
  s21_sprintf(strErrnum, "%d", errnum);

  if (errnum < 0 || errnum >= S21_ERROR_COUNT) {
    s21_strncpy(result, UNKNOWN_ERROR_PREFIX, MAX_ERROR_LEN - 1);
    s21_strncat(result, strErrnum,
                MAX_ERROR_LEN - s21_strlen(UNKNOWN_ERROR_PREFIX) - 1);
  } else if (S21_ERROR_LIST[errnum] != S21_NULL) {
    s21_strncpy(result, S21_ERROR_LIST[errnum], MAX_ERROR_LEN - 1);
  }

  result[MAX_ERROR_LEN - 1] = '\0';
  return result;
}

#include "s21_sprintf.h"

int ExtractNumberFromFormat(const char **format) {
  char tmp[BUFFER] = {'\0'};
  int i;
  for (i = 0; **format >= '0' && **format <= '9'; i++, (*format)++) {
    tmp[i] = **format;
  }
  return ConvertStringToNumber(tmp);
}

long long GetFormattedIntValue(va_list arguments, char length) {
  long long value = va_arg(arguments, long long);

  switch (length) {
    case 0:
      value = (int)value;
      break;
    case 'h':
      value = (short)value;
      break;
  }

  return value;
}

unsigned long long GetFormattedUnsignedIntValue(va_list arguments,
                                                char length) {
  unsigned long long value = va_arg(arguments, unsigned long long);

  switch (length) {
    case 0:
      value = (unsigned int)value;
      break;
    case 'h':
      value = (unsigned short)value;
      break;
    case 'l':
      value = (unsigned long long)value;
      break;
  }

  return value;
}

long double GetFormattedFloatValue(va_list arguments, char length) {
  long double value = 0;

  switch (length) {
    case 'L':
      value = va_arg(arguments, long double);
      break;
    default:
      value = va_arg(arguments, double);
      break;
  }

  return value;
}

void ConvertValueToString(long long val, char *ret, int base) {
  char tmp[BUFFER] = {'\0'};
  int idx = BUFFER - 2;

  int neg = val < 0 ? 1 : 0;
  val = neg ? -val : val;

  if (val == 0) tmp[idx] = '0';

  while (val > 0) {
    idx--;
    int digit = val % base;
    tmp[idx] = digit < 10 ? digit + '0' : digit - 10 + 'a';
    val /= base;
  }
  for (int j = 0; tmp[idx]; idx++, j++) {
    if (neg && j == 0) {
      ret[j++] = '-';
    }

    ret[j] = tmp[idx];
  }
}

void ConvertUnsignedNumberToString(unsigned long long val, char *str,
                                   int base) {
  char buf[BUFFER + 1] = {'\0'};
  int leadingZerosIndex = BUFFER - 1;

  if (val == 0) {
    buf[leadingZerosIndex] = '0';
    leadingZerosIndex--;
  }

  for (; val && leadingZerosIndex; --leadingZerosIndex, val /= base) {
    buf[leadingZerosIndex] =
        (char)(val % base + (val % base < 10 ? '0' : 'a' - 10));
  }

  for (int j = 0; buf[leadingZerosIndex + 1]; leadingZerosIndex++, j++) {
    str[j] = buf[leadingZerosIndex + 1];
  }
}

int NumericalSpecifier(int symbol) {
  char specifierChars[] = {'d', 'i', 'o', 'u', 'x', 'X'};
  int res = 0;
  int lengthChar = sizeof(specifierChars) / sizeof(specifierChars[0]);
  for (short i = 0; i < lengthChar && !res; i++) {
    if (specifierChars[i] == symbol) {
      res = 1;
    }
  }
  return res;
}

int IsZeroString(const char *str) {
  int isAllZero = 1;
  for (int i = 0; str[i] && isAllZero; i++)
    if (str[i] != '0') isAllZero = 0;
  return isAllZero;
}

void ChangeToUpperSymbol(char *str) {
  while (*str) {
    if (*str >= 'a' && *str <= 'z') {
      *str = *str - 'a' + 'A';
    }
    str++;
  }
}

void AddPrefixHex(char *str, Specifiers specifiers) {
  if (!IsZeroString(str) || specifiers.specifier == 'p') {
    s21_size_t len = s21_strlen(str);
    for (s21_size_t i = len; i > 0; i--) {
      str[i + 1] = str[i - 1];
    }
    str[0] = '0';
    str[1] = 'x';
  }
}

void ConvertDoubleToString(long double val, char *ret, Specifiers specifiers) {
  char buff[BUFFER] = {'\0'};
  int idx = BUFFER - 2;
  int neg = val < 0 ? 1 : 0;
  val = neg ? val * -1 : val;
  long double l = 0, r = modfl(val, &l);

  if (specifiers.accuracy == 0) {
    l = roundl(val);
    r = 0;
  }
  char fractions[BUFFER] = {'\0'};

  for (int i = 0; i < specifiers.accuracy; i++) {
    r = r * 10;
    fractions[i] = (int)r + '0';
  }
  long long right = roundl(r), left = l;
  if (!right) {
    for (int i = 0; i < specifiers.accuracy; idx--, i++) buff[idx] = '0';
  } else {
    for (int i = s21_strlen(fractions); right || i > 0; right /= 10, idx--, i--)
      buff[idx] = (int)(right % 10 + 0.05) + '0';
  }
  if ((specifiers.accuracyExist && specifiers.accuracy != 0) || (int)r ||
      (!specifiers.accuracyExist && val == 0) || s21_strlen(fractions))
    buff[idx--] = '.';
  if (!left) {
    buff[idx] = '0';
    idx--;
  } else {
    for (; left; left /= 10, idx--) {
      buff[idx] = (int)(left % 10) + '0';
    }
  }
  for (int i = 0; buff[idx + 1]; idx++, i++) {
    if (neg && i == 0) {
      ret[i] = '-';
      i++;
    }
    ret[i] = buff[idx + 1];
  }
}

void RecordOfTheMantiss(char *str, int pow, char sign) {
  int len = s21_strlen(str);
  str[len] = 'e';
  str[len + 1] = sign;
  if (pow < 10) {
    str[len + 2] = '0';
  }
  char buffer[BUFFER] = {'\0'};

  s21_sprintf(buffer, "%d", pow);
  str = s21_strncat(str, buffer, s21_strlen(buffer) + 1);
  str += s21_strlen(buffer);
  str[len + 5] = '\0';
}

void RemoveNonSignificantZeros(char *str) {
  int len = s21_strlen(str);
  char *dot = s21_strchr(str, '.');
  int lenCpy = len;
  if (dot) {
    for (int i = len - 1; str[i] != '.'; i--) {
      if (str[i] == '0') {
        str[i] = '\0';
        lenCpy--;
      }

      else if (lenCpy < 14) {
        break;
      }
    }

    if (dot[1] == '\0') dot[0] = '\0';
  }
}

char *CopyTo(char *dest, const char *src) {
  for (int i = 0; src[i]; i++) {
    dest[i] = src[i];
  }

  dest[s21_strlen(src)] = '\0';

  return dest;
}

int ConvertStringToNumber(const char *str) {
  int resultIntValue = 0;
  int sign = 1;

  while (*str == ' ') {
    str++;
  }
  if (*str == '-') {
    str++;
    sign = -1;
  } else if (*str == '+') {
    str++;
  }

  while (*str && *str >= '0' && *str <= '9') {
    resultIntValue = resultIntValue * 10 + (*str - '0');
    str++;
  }

  return resultIntValue * sign;
}
#include "s21_sprintf.h"

void FormatCalculationAccuracy(char *str, Specifiers specifiers) {
  char buffer[BUFFER] = {'\0'};

  int sign = 0;
  int len = s21_strlen(str);

  if (str[0] == '-') {
    buffer[0] = '-';
    len--;
    sign = 1;
  }

  if (specifiers.accuracy > len) {
    int leadingZerosIndex;
    for (leadingZerosIndex = sign;
         leadingZerosIndex < specifiers.accuracy - len + sign;
         leadingZerosIndex++) {
      buffer[leadingZerosIndex] = '0';
    }

    for (int i = sign; str[i]; i++, leadingZerosIndex++) {
      buffer[leadingZerosIndex] = str[i];
    }

    CopyTo(str, buffer);
  }

  if (specifiers.accuracyExist && specifiers.accuracy == 0 &&
      NumericalSpecifier(specifiers.specifier) && str[0] == '0')
    str[0] = '\0';
}

void FormatOutputStringWithFlags(char *str, Specifiers specifiers) {
  char buffer[BUFFER + 1] = {'\0'};

  if (specifiers.plus && specifiers.specifier != 'u') {
    buffer[0] = str[0] == '-' ? str[0] : '+';
    CopyTo(buffer + 1, (str[0] == '-') ? str + 1 : str);
    CopyTo(str, buffer);
  } else if (specifiers.space && str[0] != '-' && specifiers.specifier != 'u') {
    buffer[0] = ' ';
    CopyTo(buffer + 1, str);
    CopyTo(str, buffer);
  }
  if (specifiers.width > (int)s21_strlen(str)) {
    int leadingZerosIndex = specifiers.width - (int)s21_strlen(str);

    if (!specifiers.minus) {
      if ((str[0] == '-' || str[0] == '+' || str[0] == ' ') &&
          specifiers.zero) {
        buffer[0] = str[0];
        s21_memset(buffer + 1, '0', leadingZerosIndex);
        CopyTo(buffer + 1 + leadingZerosIndex, str + 1);
      } else {
        s21_memset(buffer, specifiers.zero ? '0' : ' ', leadingZerosIndex);
        CopyTo(buffer + leadingZerosIndex, str);
      }

    } else {
      CopyTo(buffer, str);
      s21_memset(buffer + s21_strlen(buffer), ' ', leadingZerosIndex);
    }

    CopyTo(str, buffer);
  }
}

void FormatRoundingUpShortestRep(char *str, int accuracy) {
  int significant_digits = 0;
  s21_size_t len = s21_strlen(str);
  int isZeroExist = 0;
  int isRoundingUp = 0;
  for (s21_size_t i = 0; !isRoundingUp && i < len; i++) {
    if ((str[i] == '0' && !isZeroExist) || str[i] == '.') {
      continue;
    }
    isZeroExist = 1;

    if (str[i] >= '0' && str[i] <= '9') {
      significant_digits++;
    }

    if (significant_digits == accuracy && i + 1 < len) {
      int nextStepDigit = (str[i + 1] == '.') ? 2 : 1;
      char nextDigit = str[i + nextStepDigit];

      if (nextDigit - '0' > 5) {
        str[i] = (char)(str[i] + 1);
      }

      str[i + 1] = '\0';
      isRoundingUp = 1;
    }
  }
}

void FormatBaseChar(Specifiers specifiers, char *buff, char c) {
  int padding = (specifiers.width > 1) ? specifiers.width - 1 : 0;

  if (!specifiers.minus) {
    for (int i = 0; i < padding; i++) {
      buff[i] = ' ';
    }
    buff[padding] = c;
  } else {
    buff[0] = c;
    for (int i = 1; i < specifiers.width; i++) {
      buff[i] = ' ';
    }
  }
}

void FormatBaseString(Specifiers specifiers, char *buff, char *str) {
  char tmp[BUFFER] = {'\0'};
  CopyTo(tmp, str);
  if (specifiers.accuracyExist) tmp[specifiers.accuracy] = '\0';

  int shift = specifiers.width - s21_strlen(tmp);
  int len = s21_strlen(tmp);

  if (specifiers.minus && shift > 0) {
    CopyTo(buff, tmp);
    s21_memset(buff + len, ' ', shift);
  } else if (shift > 0) {
    s21_memset(buff, ' ', shift);
    CopyTo(buff + shift, tmp);
  } else {
    CopyTo(buff, tmp);
  }
}

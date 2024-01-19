#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arguments;
  va_start(arguments, format);
  char *strBeginning = str;

  while (*format) {
    if (*format == '%') {
      format++;
      Specifiers specifiers = {0};
      format = SetFormatSpecifiers(format, &specifiers, arguments);
      specifiers.specifier = *format;

      format++;
      char *supportString = str;
      char buff[BUFFER] = {'\0'};
      ChoosingParserSpecifier(specifiers, buff, strBeginning, supportString,
                              arguments);
      for (int i = 0; buff[i]; i++, str++) {
        *str = buff[i];
      }
    } else {
      *str++ = *format++;
    }
  }

  *str = '\0';
  va_end(arguments);
  return str - strBeginning;
}

void ChoosingParserSpecifier(Specifiers specifiers, char *str,
                             const char *strBeginning,
                             const char *currentPointer, va_list arguments) {
  switch (specifiers.specifier) {
    case 'd':
    case 'i':
      ParsingToIntString(specifiers, str, arguments);
      break;
    case 'u':
      ParsingToUnsignedString(specifiers, str, arguments);
      break;
    case 'o':
      ParsingOctalString(specifiers, str, arguments);
      break;
    case 'x':
    case 'X':
      ParsingHexString(specifiers, str, arguments);
      break;
    case '%':
      str[0] = '%';
      break;
    case 'c':
      ParsingCharString(specifiers, str, arguments);
      break;
    case 'n':
      HandleSpecifierCountSymbols(arguments, currentPointer - strBeginning);
      break;
    case 's':
      ParsingString(specifiers, str, arguments);
      break;
    case 'p':
      ParsingPointerString(specifiers, str, arguments);
      break;
    case 'f':
      ParsingFloatString(specifiers, str, arguments);
      break;
    case 'e':
    case 'E':
      ParsingMantissString(specifiers, str, arguments);
      break;
    case 'g':
    case 'G':
      ParsingShortestRepresentationString(specifiers, str, arguments);
      break;
    default:
      break;
  }

  if (specifiers.specifier == 'G' || specifiers.specifier == 'E' ||
      specifiers.specifier == 'X') {
    ChangeToUpperSymbol(str);
  }
}

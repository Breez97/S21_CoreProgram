#include "s21_sprintf.h"

const char *SetFormatSpecifiers(const char *format, Specifiers *specifiers,
                                va_list arguments) {
  format = SetFormatFlags(format, specifiers);
  format = SetFormatWidth(format, specifiers, arguments);
  format = SetFormatAccuracy(format, specifiers, arguments);
  format = SetFormatLength(format, specifiers);

  return format;
}

const char *SetFormatFlags(const char *format, Specifiers *specifiers) {
  while (s21_strchr("-+ 0#", *format) != NULL) {
    switch (*format) {
      case '0':
        specifiers->zero = 1;
        break;
      case '-':
        specifiers->minus = 1;
        break;
      case '+':
        specifiers->plus = 1;
        break;
      case ' ':
        specifiers->space = 1;
        break;
      case '#':
        specifiers->hash = 1;
        break;
    }
    format++;
  }
  return format;
}

const char *SetFormatWidth(const char *format, Specifiers *specifiers,
                           va_list arguments) {
  if (*format == '*') {
    format++;
    specifiers->width = va_arg(arguments, int);
  } else if (*format >= '0' && *format <= '9') {
    specifiers->width = ExtractNumberFromFormat(&format);
  }
  return format;
}

const char *SetFormatAccuracy(const char *format, Specifiers *specifiers,
                              va_list arguments) {
  if (*format == '.') {
    specifiers->accuracyExist = 1;
    format++;
  }

  if (*format == '*') {
    format++;
    specifiers->accuracy = va_arg(arguments, int);
  } else if (*format >= '0' && *format <= '9') {
    specifiers->accuracy = ExtractNumberFromFormat(&format);
  }
  return format;
}

const char *SetFormatLength(const char *format, Specifiers *specifiers) {
  switch (*format) {
    case 'h':
      specifiers->length = 'h';
      format++;
      break;
    case 'l':
      specifiers->length = 'l';
      format++;
      break;
    case 'L':
      specifiers->length = 'L';
      format++;
      break;
  }
  return format;
}
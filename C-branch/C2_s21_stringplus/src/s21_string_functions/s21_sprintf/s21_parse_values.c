#include "s21_sprintf.h"

void ParsingToIntString(Specifiers specifiers, char *str, va_list arguments) {
  long long value = GetFormattedIntValue(arguments, specifiers.length);
  ConvertValueToString(value, str, 10);
  FormatCalculationAccuracy(str, specifiers);
  FormatOutputStringWithFlags(str, specifiers);
}

void ParsingToUnsignedString(Specifiers specifiers, char *str,
                             va_list arguments) {
  unsigned long long value =
      GetFormattedUnsignedIntValue(arguments, specifiers.length);
  ConvertUnsignedNumberToString(value, str, 10);
  FormatCalculationAccuracy(str, specifiers);
  FormatOutputStringWithFlags(str, specifiers);
}

void ParsingOctalString(Specifiers specifiers, char *str, va_list arguments) {
  str[0] = '0';
  ConvertValueToString(va_arg(arguments, long long), str + specifiers.hash, 8);
  FormatCalculationAccuracy(str, specifiers);
  FormatOutputStringWithFlags(str, specifiers);
}

void ParsingHexString(Specifiers specifiers, char *str, va_list arguments) {
  unsigned long long value =
      GetFormattedUnsignedIntValue(arguments, specifiers.length);
  ConvertUnsignedNumberToString(value, str, 16);
  FormatCalculationAccuracy(str, specifiers);
  if (specifiers.hash) {
    AddPrefixHex(str, specifiers);
  }
  FormatOutputStringWithFlags(str, specifiers);
}

void ParsingCharString(Specifiers specifiers, char *buff, va_list arguments) {
  char c = va_arg(arguments, int);
  FormatBaseChar(specifiers, buff, c);
}

void HandleSpecifierCountSymbols(va_list arguments, int distance) {
  int *ret = va_arg(arguments, int *);
  *ret = distance;
}

void ParsingString(Specifiers specifiers, char *buff, va_list arguments) {
  char *str = va_arg(arguments, char *);
  FormatBaseString(specifiers, buff, str);
}

void ParsingPointerString(Specifiers specifiers, char *buff,
                          va_list arguments) {
  ConvertUnsignedNumberToString(va_arg(arguments, unsigned long long), buff,
                                16);
  FormatCalculationAccuracy(buff, specifiers);
  AddPrefixHex(buff, specifiers);
  FormatOutputStringWithFlags(buff, specifiers);
}

void ParsingFloatString(Specifiers specifiers, char *buff, va_list arguments) {
  long double value = GetFormattedFloatValue(arguments, specifiers.length);

  if (!specifiers.accuracyExist) {
    specifiers.accuracy = 6;
  }

  ConvertDoubleToString(value, buff, specifiers);
  FormatOutputStringWithFlags(buff, specifiers);
}

void ParsingMantissString(Specifiers specifiers, char *buff,
                          va_list arguments) {
  long double value = GetFormattedFloatValue(arguments, specifiers.length);
  int pow = 0;
  char sign = (int)value == 0 ? '-' : '+';

  if ((int)value - value) {
    while ((int)value == 0) {
      pow++;
      value *= 10;
    }
  } else {
    sign = '+';
  }
  while ((int)value / 10 != 0) {
    pow++;
    value /= 10;
  }

  if (!specifiers.accuracyExist) specifiers.accuracy = 6;
  ConvertDoubleToString(value, buff, specifiers);
  RecordOfTheMantiss(buff, pow, sign);
  FormatOutputStringWithFlags(buff, specifiers);
}

void ParsingShortestRepresentationString(Specifiers specifiers, char *str,
                                         va_list arguments) {
  long double value = GetFormattedFloatValue(arguments, specifiers.length);

  if (!specifiers.accuracyExist) {
    specifiers.accuracy = 6;
  }
  if (specifiers.accuracy == 0) specifiers.accuracy = 1;

  int pow = 0;
  long double m_val = value;
  char sign = (int)value == 0 ? '-' : '+';
  if ((int)value - value) {
    while (!(int)value) {
      pow++;
      value *= 10;
    }
  } else {
    sign = '+';
  }

  while ((int)value / 10 != 0) {
    pow++;
    value /= 10;
  }

  if (fabsl(m_val) > 0.0001 && m_val != 0 && pow <= 17) {
    ConvertDoubleToString(m_val, str, specifiers);
  } else {
    ConvertDoubleToString(value, str, specifiers);
  }
  RemoveNonSignificantZeros(str);
  FormatRoundingUpShortestRep(str, specifiers.accuracy);

  if (!(fabsl(m_val) > 0.0001 && m_val != 0 && pow <= 17)) {
    RecordOfTheMantiss(str, pow, sign);
  }

  FormatOutputStringWithFlags(str, specifiers);
}

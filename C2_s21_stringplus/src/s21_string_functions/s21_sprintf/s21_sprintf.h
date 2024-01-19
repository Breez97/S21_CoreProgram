#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_
#include <locale.h>
#include <math.h>
#include <stdarg.h>

#include "../../s21_string.h"

typedef struct {
  int minus;
  int plus;
  int space;
  int zero;
  int hash;
  int accuracy;
  int accuracyExist;
  int width;
  char length;
  char specifier;
} Specifiers;

int s21_sprintf(char *str, const char *format, ...);

// helper functions
int ExtractNumberFromFormat(const char **format);
long long GetFormattedIntValue(va_list arguments, char length);
unsigned long long GetFormattedUnsignedIntValue(va_list arguments, char length);
long double GetFormattedFloatValue(va_list arguments, char length);

void ConvertValueToString(long long val, char *ret, int base);
void ConvertUnsignedNumberToString(unsigned long long val, char *ret, int base);
int NumericalSpecifier(int symbol);
int IsZeroString(const char *str);
void ChangeToUpperSymbol(char *str);
void AddPrefixHex(char *str, Specifiers specifiers);
void ConvertDoubleToString(long double val, char *ret, Specifiers specifiers);
void RecordOfTheMantiss(char *str, int pow, char sign);
void RemoveNonSignificantZeros(char *str);

char *CopyTo(char *dest, const char *src);
int ConvertStringToNumber(const char *str);

// parse format +
const char *SetFormatSpecifiers(const char *format, Specifiers *specifiers,
                                va_list arguments);
const char *SetFormatFlags(const char *format, Specifiers *specifiers);
const char *SetFormatWidth(const char *format, Specifiers *specifiers,
                           va_list arguments);
const char *SetFormatAccuracy(const char *format, Specifiers *specifiers,
                              va_list arguments);
const char *SetFormatLength(const char *format, Specifiers *specifiers);

// parse values
void ChoosingParserSpecifier(Specifiers specifiers, char *str,
                             const char *strBeginning,
                             const char *currentPointer, va_list arguments);
void ParsingToIntString(Specifiers, char *str, va_list arguments);
void ParsingToUnsignedString(Specifiers specifiers, char *str,
                             va_list arguments);
void ParsingOctalString(Specifiers specifiers, char *str, va_list arguments);
void ParsingHexString(Specifiers specifiers, char *str, va_list arguments);
void ParsingCharString(Specifiers specifiers, char *str, va_list arguments);
void HandleSpecifierCountSymbols(va_list arguments, int distance);
void ParsingString(Specifiers specifiers, char *str, va_list arguments);
void ParsingPointerString(Specifiers specifiers, char *str, va_list arguments);
void ParsingFloatString(Specifiers specifiers, char *str, va_list arguments);
void ParsingMantissString(Specifiers specifiers, char *str, va_list arguments);
void ParsingShortestRepresentationString(Specifiers specifiers, char *str,
                                         va_list arguments);

// format values
void FormatCalculationAccuracy(char *str, Specifiers specifiers);
void FormatOutputStringWithFlags(char *str, Specifiers specifiers);
void FormatRoundingUpShortestRep(char *str, int accuracy);
void FormatBaseChar(Specifiers specifiers, char *str, char c);
void FormatBaseString(Specifiers specifiers, char *buff, char *str);

#define BUFFER 1024

#endif  //  SRC_S21_SPRINTF_H_
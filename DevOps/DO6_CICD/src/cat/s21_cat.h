#ifndef S21_CAT
#define S21_CAT

#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct flags {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
};

struct option longOptions[] = {{"number-nonblank", no_argument, NULL, 'b'},
                               {"number", no_argument, NULL, 'n'},
                               {"squeeze-blank", no_argument, NULL, 's'},
                               {NULL, 0, NULL, 0}};

void ProgramStart(int argc, char *argv[]);
void OutputFile(FILE *file, struct flags inputFlags);
void OpenMultipleFiles(int argc, char *argv[], struct flags inputFlags);
void FlagE(struct flags inputFlags, char symbol);
void FlagS(struct flags inputFlags, int countEnter, int *goToNextSymbol);
void NumberStrings(struct flags inputFlags, int lenString, int numberOnString,
                   int *countStrings);
void FlagT(struct flags inputFlags, char *symbol);
void FlagV(struct flags inputFlags, char *symbol);
int FindLongFlagsError(int argc, char *argv[], struct flags *inputFlags);

#endif

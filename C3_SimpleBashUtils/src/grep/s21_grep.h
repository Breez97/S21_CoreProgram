#ifndef S21_GREP
#define S21_GREP

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} flags;

void ProgramStart(int argc, char *argv[]);
int FlagsAndFiles(int argc, char *argv[], flags *inputFlags,
                  char ***patternsArray, int *countPatterns);
void AddPatternIsSingleFlag(int argc, int *isIllegalOption, char *pattern,
                            char ***patternsArray, int *countPatterns);
void FindFiles(flags inputFlags, int argc, char *argv[], char ***files,
               int *countFiles);
void FillPatternsArray(char *pattern, char ***patternsArray,
                       int *countPatterns);
void ConvertRegexes(flags inputFlags, char **patternsArray, int countPatterns,
                    regex_t **regexes, int *countRegexes);
void SearchInFile(flags inputFlags, regex_t *regexes, int countRegexes,
                  char **files, int countFiles);
void OutputFile(char *filename, FILE *file, flags inputFlags, regex_t *regexes,
                int countRegexes, int countFiles);
void GetPatternsFromFile(char *filename, char ***patternsArray,
                         int *countPatterns);
void PrintFlagO(regex_t *regexes, char *line, int countRegexes);
void PrintIsSuitable(int suitable, flags inputFlags, int countFiles,
                     int isLinePrinted, char *filename, char *line,
                     int numberLine, regex_t *regexes, int countRegexes,
                     int *countString, int *isSuitableFile);
void PrintIsNotSuitable(int suitable, flags inputFlags, int countFiles,
                        int isLinePrinted, char *filename, int numberLine,
                        char *line, int *countString, int *isSuitableFile);

#endif

#include "s21_grep.h"

int main(int argc, char *argv[]) {
  ProgramStart(argc, argv);
  return 0;
}

void ProgramStart(int argc, char *argv[]) {
  flags inputFlags = {0};

  char **patternsArray = NULL;
  int countPatterns = 0;

  regex_t *regexes = NULL;
  int countRegexes = 0;

  char **files = NULL;
  int countFiles = 0;

  if (FlagsAndFiles(argc, argv, &inputFlags, &patternsArray, &countPatterns) ==
          1 ||
      argc == 1) {
    fprintf(stderr, "Usage: grep [OPTION]... PATTERN [FILE]...\n");
  } else {
    ConvertRegexes(inputFlags, patternsArray, countPatterns, &regexes,
                   &countRegexes);

    FindFiles(inputFlags, argc, argv, &files, &countFiles);

    SearchInFile(inputFlags, regexes, countRegexes, files, countFiles);
  }

  for (int i = 0; i < countRegexes; i++) regfree(&regexes[i]);
  for (int i = 0; i < countFiles; i++) free(files[i]);
  for (int i = 0; i < countPatterns; i++) free(patternsArray[i]);
  free(patternsArray);
  free(files);
  free(regexes);
}

void ConvertRegexes(flags inputFlags, char **patternsArray, int countPatterns,
                    regex_t **regexes, int *countRegexes) {
  for (int i = 0; i < countPatterns; i++) {
    regex_t *regex = malloc(sizeof(regex_t));
    (*countRegexes) += 1;
    *regexes = realloc(*regexes, sizeof(regex_t) * (*countRegexes));
    if (inputFlags.i == 1)
      regcomp(regex, patternsArray[i], REG_ICASE);
    else
      regcomp(regex, patternsArray[i], REG_EXTENDED);
    (*regexes)[(*countRegexes) - 1] = *regex;
    free(regex);
  }
}

int FlagsAndFiles(int argc, char *argv[], flags *inputFlags,
                  char ***patternsArray, int *countPatterns) {
  int opt;
  int isIllegalOption = 0;
  while (isIllegalOption == 0 &&
         (opt = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) != -1) {
    switch (opt) {
      case 'e':
        inputFlags->e = 1;
        FillPatternsArray(optarg, patternsArray, countPatterns);
        break;
      case 'i':
        inputFlags->i = 1;
        break;
      case 'v':
        inputFlags->v = 1;
        break;
      case 'c':
        inputFlags->c = 1;
        break;
      case 'l':
        inputFlags->l = 1;
        break;
      case 'n':
        inputFlags->n = 1;
        break;
      case 'h':
        inputFlags->h = 1;
        break;
      case 's':
        inputFlags->s = 1;
        break;
      case 'f':
        inputFlags->f = 1;
        GetPatternsFromFile(optarg, patternsArray, countPatterns);
        break;
      case 'o':
        inputFlags->o = 1;
        break;
      default:
        isIllegalOption = 1;
        break;
    }
  }
  if (inputFlags->e == 0 && inputFlags->f == 0) {
    AddPatternIsSingleFlag(argc, &isIllegalOption, argv[optind], patternsArray,
                           countPatterns);
  }
  return isIllegalOption;
}

void AddPatternIsSingleFlag(int argc, int *isIllegalOption, char *pattern,
                            char ***patternsArray, int *countPatterns) {
  if (optind == argc) *isIllegalOption = 1;
  if (optind < argc) FillPatternsArray(pattern, patternsArray, countPatterns);
}

void FindFiles(flags inputFlags, int argc, char *argv[], char ***files,
               int *countFiles) {
  if (inputFlags.e == 0) optind += 1;
  if (inputFlags.f == 1) optind -= 1;
  if (inputFlags.e == 1 && inputFlags.f == 1) optind += 1;
  for (int i = optind; i < argc; i++) {
    (*countFiles) += 1;
    (*files) = realloc(*files, sizeof(char *) * (*countFiles));
    (*files)[(*countFiles) - 1] = malloc(sizeof(char) * (strlen(argv[i]) + 1));
    strcpy((*files)[(*countFiles) - 1], argv[i]);
  }
}

void GetPatternsFromFile(char *filename, char ***patternsArray,
                         int *countPatterns) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    fprintf(stderr, "grep: %s: No such file or directory\n", filename);
  } else {
    char *line = NULL;
    size_t len;
    while (getline(&line, &len, file) != -1) {
      line[strcspn(line, "\n")] = '\0';
      FillPatternsArray(line, patternsArray, countPatterns);
    }
    free(line);
  }
  fclose(file);
}

void FillPatternsArray(char *pattern, char ***patternsArray,
                       int *countPatterns) {
  (*countPatterns) += 1;
  (*patternsArray) = realloc(*patternsArray, sizeof(char *) * (*countPatterns));
  (*patternsArray)[(*countPatterns) - 1] =
      malloc(sizeof(char) * (strlen(pattern) + 1));
  strcpy((*patternsArray)[(*countPatterns) - 1], pattern);
}

void SearchInFile(flags inputFlags, regex_t *regexes, int countRegexes,
                  char **files, int countFiles) {
  FILE *file;
  char *filename = NULL;
  if (countFiles == 0) {
    file = freopen(NULL, "rb", stdin);
    OutputFile(filename, file, inputFlags, regexes, countRegexes, countFiles);
  } else {
    for (int i = 0; i < countFiles; i++) {
      file = fopen(files[i], "rb");
      if (file == NULL) {
        if (inputFlags.s == 0)
          fprintf(stderr, "grep: %s: No such file or directory\n", files[i]);
      } else
        OutputFile(files[i], file, inputFlags, regexes, countRegexes,
                   countFiles);
      if (file != NULL) fclose(file);
    }
  }
}

void OutputFile(char *filename, FILE *file, flags inputFlags, regex_t *regexes,
                int countRegexes, int countFiles) {
  char *line = NULL;
  size_t len = 0;
  int countString = 0, isSuitableFile = 0, numberLine = 1;
  while (getline(&line, &len, file) != -1) {
    int isLinePrinted = 0, suitable = 0;
    line[strcspn(line, "\n")] = '\0';
    for (int i = 0; i < countRegexes; i++) {
      if (regexec(&regexes[i], line, 0, NULL, 0) == 0) suitable = 1;
    }
    if (inputFlags.v == 0) {
      PrintIsSuitable(suitable, inputFlags, countFiles, isLinePrinted, filename,
                      line, numberLine, regexes, countRegexes, &countString,
                      &isSuitableFile);
    } else {
      PrintIsNotSuitable(suitable, inputFlags, countFiles, isLinePrinted,
                         filename, numberLine, line, &countString,
                         &isSuitableFile);
    }
    numberLine++;
  }
  if (inputFlags.c == 1) {
    if (countFiles > 1 && inputFlags.h == 0) printf("%s:", filename);
    if (inputFlags.l == 1 && countString > 0) countString = 1;
    printf("%d\n", countString);
  }
  if (inputFlags.l == 1 && isSuitableFile) printf("%s\n", filename);
  free(line);
}

void PrintIsSuitable(int suitable, flags inputFlags, int countFiles,
                     int isLinePrinted, char *filename, char *line,
                     int numberLine, regex_t *regexes, int countRegexes,
                     int *countString, int *isSuitableFile) {
  if (suitable == 1) {
    if (inputFlags.c == 0 && inputFlags.l == 0) {
      if (countFiles > 1 && inputFlags.h == 0 && isLinePrinted == 0)
        printf("%s:", filename);
      if (inputFlags.n == 1) printf("%d:", numberLine);
      if (inputFlags.o == 1)
        PrintFlagO(regexes, line, countRegexes);
      else
        printf("%s\n", line);
    }
    (*countString)++;
    *isSuitableFile = 1;
  }
}

void PrintIsNotSuitable(int suitable, flags inputFlags, int countFiles,
                        int isLinePrinted, char *filename, int numberLine,
                        char *line, int *countString, int *isSuitableFile) {
  if (suitable == 0) {
    if (inputFlags.c == 0 && inputFlags.l == 0) {
      if (countFiles > 1 && inputFlags.h == 0 && isLinePrinted == 0)
        printf("%s:", filename);
      if (inputFlags.n == 1) printf("%d:", numberLine);
      printf("%s\n", line);
    }
    (*countString)++;
    *isSuitableFile = 1;
  }
}

void PrintFlagO(regex_t *regexes, char *line, int countRegexes) {
  int currentPos = 0;
  for (int i = 0; i < countRegexes; i++) {
    regmatch_t matches[1];
    while (regexec(&regexes[i], line + currentPos, 1, matches, 0) == 0) {
      int start = currentPos + matches[0].rm_so;
      int end = currentPos + matches[0].rm_eo;
      for (int j = start; j < end; j++) printf("%c", line[j]);
      printf("\n");
      currentPos += matches[0].rm_eo;
    }
  }
}

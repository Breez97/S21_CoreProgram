#include "s21_cat.h"

int main(int argc, char *argv[]) {
  ProgramStart(argc, argv);

  return 0;
}

void ProgramStart(int argc, char *argv[]) {
  struct flags inputFlags = {0, 0, 0, 0, 0, 0};

  if (FindLongFlagsError(argc, argv, &inputFlags) == 0) {
    if (optind == argc) {
      OutputFile(freopen(NULL, "rb", stdin), inputFlags);
    } else {
      OpenMultipleFiles(argc, argv, inputFlags);
    }
  }
}

int FindLongFlagsError(int argc, char *argv[], struct flags *inputFlags) {
  int opt, isIllegalOption = 0;
  while (isIllegalOption == 0 && (opt = getopt_long(argc, argv, "+benstvET",
                                                    longOptions, NULL)) != -1) {
    switch (opt) {
      case 'b':
        inputFlags->b = 1;
        break;
      case 'e':
        inputFlags->e = 1;
        inputFlags->v = 1;
        break;
      case 'n':
        inputFlags->n = 1;
        break;
      case 's':
        inputFlags->s = 1;
        break;
      case 't':
        inputFlags->t = 1;
        inputFlags->v = 1;
        break;
      case 'v':
        inputFlags->v = 1;
        break;
      case 'E':
        inputFlags->e = 1;
        break;
      case 'T':
        inputFlags->t = 1;
        break;
      default:
        isIllegalOption = 1;
        break;
    }
  }
  return isIllegalOption;
}

void OpenMultipleFiles(int argc, char *argv[], struct flags inputFlags) {
  FILE *file;
  for (int i = optind; i < argc; i++) {
    if (strcmp(argv[i], "-") == 0) {
      file = freopen(NULL, "rb", stdin);
      OutputFile(file, inputFlags);
    } else {
      file = fopen(argv[i], "rb");
      if (file != NULL)
        OutputFile(file, inputFlags);
      else
        fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
    }
    if (file != stdin && file != NULL) fclose(file);
  }
}

void OutputFile(FILE *file, struct flags inputFlags) {
  char symbol;
  int countEnter = 1, numberOnString = 1, countStrings = 1, lenString = 0;

  while ((symbol = fgetc(file)) != EOF) {
    lenString = (symbol != '\n') ? lenString + 1 : 0;
    int goToNextSymbol = 0;
    countEnter = (symbol == '\n') ? countEnter + 1 : 0;

    FlagS(inputFlags, countEnter, &goToNextSymbol);

    if (goToNextSymbol == 0) {
      NumberStrings(inputFlags, lenString, numberOnString, &countStrings);

      FlagE(inputFlags, symbol);
      FlagV(inputFlags, &symbol);
      FlagT(inputFlags, &symbol);

      printf("%c", symbol);
      numberOnString = (symbol == '\n') ? 1 : 0;
    }
  }
}

void FlagE(struct flags inputFlags, char symbol) {
  if (inputFlags.e == 1 && symbol == '\n') {
    printf("$");
  }
}

void FlagS(struct flags inputFlags, int countEnter, int *goToNextSymbol) {
  if (inputFlags.s == 1) {
    if (countEnter >= 3) {
      *goToNextSymbol = 1;
    }
  }
}

void NumberStrings(struct flags inputFlags, int lenString, int numberOnString,
                   int *countStrings) {
  if (inputFlags.b == 1) {
    if (lenString > 0 && numberOnString == 1) {
      printf("%6d\t", (*countStrings)++);
    }
  } else {
    if (inputFlags.n == 1 && numberOnString == 1) {
      printf("%6d\t", (*countStrings)++);
    }
  }
}

void FlagT(struct flags inputFlags, char *symbol) {
  if (inputFlags.t == 1 && *symbol == '\t') {
    printf("^");
    *symbol = 'I';
  }
}

void FlagV(struct flags inputFlags, char *symbol) {
  if (inputFlags.v == 1) {
    if (*symbol >= 0 && *symbol <= 31 && *symbol != '\n' && *symbol != '\t') {
      printf("^");
      (*symbol) += '@';
    } else {
      if (*symbol == 127) {
        printf("^");
        *symbol = '?';
      }
    }
  }
}
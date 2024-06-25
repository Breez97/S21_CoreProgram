/**
 * @file tetris_backend.c
 * @brief Функции, отвечающие за бэкенд игры.
 *
 * @ingroup Backend
 */

#include "tetris_backend.h"

/**
 * @ingroup Backend
 * @brief Функция, возвращающая указатель на текущее состояние игры.
 *
 * Данная функция возвращает указатель на текущее состояние игры.
 * Состояние игры инициализируется, как статическая переменная, которая
 * сохраняет свое состояние между вызовами.
 *
 * @return Возвращает структуру с текущим состоянием игры.
 */
State_t *CurrentState() {
  static State_t state = GameStart;
  return &state;
}

/**
 * @ingroup Backend
 * @brief Функция, вовзвращающая информацию о текущем состоянии игры.
 *
 * Данная функция возвращает указатель на текущее состояние игры, которое
 * содержит информацию обо всей статистике. Состояние игры инициализируется, как
 * статическая переменная, которая сохраняет свое состояние между вызовами.
 * Создание изначальной переменной и выделение всей необходимой памяти
 * происходит на основе паттерна Singleton, чтобы каждый раз при вызове функции
 * не инициализировалась новая информация, и не выделялась излишняя память.
 *
 * @return Возвращает структуру с текущим состоянием игры со всей статистикой.
 */
GameInfo_t *CurrentGameInfo() {
  static GameInfo_t gameInfo;
  static bool initialized = false;
  if (initialized == false) {
    gameInfo = GameInfoInitialization();
    initialized = true;
  }
  return &gameInfo;
}

/**
 * @ingroup Backend
 * @brief Функция, отвечающая за инициализацию игровых данных.
 *
 * Данная функция отвечает за инициализацию всех игровых данных и заполнение
 * лучшего результата из файла, если таковой имеется.
 *
 * @return Возвращает структуру со всеми игровыми данными.
 */
GameInfo_t GameInfoInitialization() {
  GameInfo_t gameInfo = {0};
  gameInfo.field = CreateGameField();
  gameInfo.next = CreateNextFigure();
  gameInfo.score = 0;
  FILE *file = fopen("./best.txt", "r");
  if (file != NULL) {
    fscanf(file, "%d", &gameInfo.high_score);
    fclose(file);
  } else {
    gameInfo.high_score = 0;
  }
  gameInfo.level = 0;
  gameInfo.speed = 650;
  gameInfo.pause = 0;
  return gameInfo;
}

/**
 * @ingroup Backend
 * @brief Функция, отвечающая за выделение памяти для игрового поля.
 *
 * Данная функция выделяет память для игрового поля тетриса.
 *
 * @return gameField - массив для игрового поля.
 */
int **CreateGameField() {
  int **gameField = malloc((FIELD_X_END + 1) * sizeof(int *));
  for (int i = 0; i < FIELD_X_END + 1; i++) {
    gameField[i] = malloc((FIELD_Y_END + 1) * sizeof(int));
    for (int j = 0; j < FIELD_Y_END + 1; j++) {
      gameField[i][j] = 0;
    }
  }
  return gameField;
}

/**
 * @ingroup Backend
 * @brief Функция, отвечающая за выделение памяти для следующей фигуры.
 *
 * Данная функция выделяет память для следующей фигуры, которая будет заспавнена
 * после присоединения текущей.
 *
 * @return nextFigure - массив для следующей фигуры.
 */
int **CreateNextFigure() {
  int **nextFigure = malloc(4 * sizeof(int *));
  for (int i = 0; i < 4; i++) {
    nextFigure[i] = malloc(4 * sizeof(int));
    for (int j = 0; j < 4; j++) {
      nextFigure[i][j] = 0;
    }
  }
  return nextFigure;
}

/**
 * @ingroup Backend
 * @brief Функция, отвечающая за изменение текущего состояния игры.
 *
 * Данная функция выполняет изменение текущих игровых данных в зависимости от
 * состояния. В случае, если игра только началась, устанавливает значение
 * уровня, равное 1. В случае, если текущий результат превышает лучший
 * результат, то обновляет лучший резлуьтат, присваивая ему значение текущего.
 * В случае, если игрок набирает 600 очков, то уровень повышается на 1, и
 * скорость движения фигур увеличивается, максимальное количество уровней - 10.
 * В случае, если игра стоит на паузе, то изменяет значение переменной паузы на
 * 1, в противном случае на 0. В случае, если игры заврешается, записывает
 * лучший результат в файл, если значение в файле меньше, чем текущий лучший
 * результат. Если же файла нет, то просто записывает данные в файл, если лучший
 * результат больше 0.
 *
 * @return Стурктура с обновленными игровыми данными.
 */
GameInfo_t updateCurrentState() {
  GameInfo_t *gameState = CurrentGameInfo();
  if (gameState->level == 0) {
    gameState->level = 1;
  }
  if (gameState->high_score <= gameState->score) {
    gameState->high_score = gameState->score;
  }
  if (gameState->score - 600 * gameState->level >= 0 && gameState->level < 10) {
    gameState->level += 1;
    gameState->speed -= 60;
  }
  if (*CurrentState() == GamePause) {
    gameState->pause = 1;
  } else {
    gameState->pause = 0;
  }
  if (*CurrentState() == GameOver) {
    FILE *fileRead = fopen("./best.txt", "r");
    if (fileRead != NULL) {
      int highScoreInFile = 0;
      fscanf(fileRead, "%d", &highScoreInFile);
      fclose(fileRead);
      if (highScoreInFile < gameState->high_score) {
        WriteBestScoreInFile(gameState->high_score);
      }
    } else {
      if (gameState->high_score > 0) {
        WriteBestScoreInFile(gameState->high_score);
      }
    }
  }
  return *gameState;
}

/**
 * @ingroup Backend
 * @brief Функция, отвечающая за запись лучшего результат в файл.
 *
 * Данная функция открывает файл с лучшим результатом на чтение, если такового
 * не имеется, то автоматически создает его и записывает лучший результат.
 *
 * @param highScore Лучший результат.
 */
void WriteBestScoreInFile(int highScore) {
  FILE *fileWrite = fopen("./best.txt", "w");
  fprintf(fileWrite, "%d", highScore);
  fclose(fileWrite);
}

/**
 * @ingroup Backend
 * @brief Функция, отвечающая за удаление заполненных строк.
 *
 * Данная функция очищает строки, которые полностью заполнились после
 * присоединения новой фигуры, а также смещает все установленыные блоки (со
 * значением 2), на нужное количество ячеек вниз.
 *
 * @param gameInfo Указатель на текущее состояние игры.
 */
void RemoveLines(GameInfo_t *gameInfo) {
  int linesCleared = 0;
  for (int i = FIELD_Y_END - 1; i > 0; i--) {
    bool rowIsFull = true;
    for (int j = FIELD_X_START + 1; j <= FIELD_X_END / 2 && rowIsFull == true;
         j++) {
      if (gameInfo->field[i][j] != 2) {
        rowIsFull = false;
      }
    }
    if (rowIsFull) {
      for (int k = i; k > 0; k--) {
        for (int j = FIELD_X_START + 1; j <= FIELD_X_END / 2; j++) {
          gameInfo->field[k][j] = gameInfo->field[k - 1][j];
        }
      }
      for (int j = FIELD_X_START + 1; j <= FIELD_X_END / 2; j++) {
        gameInfo->field[0][j] = 0;
      }
      linesCleared++;
      i++;
    }
  }
  if (linesCleared == 1) {
    gameInfo->score += 100;
  } else if (linesCleared == 2) {
    gameInfo->score += 300;
  } else if (linesCleared == 3) {
    gameInfo->score += 700;
  } else if (linesCleared == 4) {
    gameInfo->score += 1500;
  }
}

/**
 * @ingroup Backend
 * @brief Функция, отвечающая за очистку массива игрового поля.
 *
 * Данная функция очищает выделенную память для массива игрового поля.
 *
 * @param gameField Указатель на массив с игровым полем.
 */
void FreeGameField(int **gameField) {
  if (gameField) {
    for (int i = 0; i < 22; i++) {
      if (gameField[i]) {
        free(gameField[i]);
      }
    }
    free(gameField);
  }
}

/**
 * @ingroup Backend
 * @brief Функция, отвечающая за очистку массива следующей фигуры.
 *
 * Данная функция очищает выделенную память для массива следующей фигуры.
 *
 * @param gameField Указатель на массив со следующей фигурой.
 */
void FreeNextFigure(int **nextFigure) {
  if (nextFigure) {
    for (int i = 0; i < 4; i++) {
      if (nextFigure[i]) {
        free(nextFigure[i]);
      }
    }
    free(nextFigure);
  }
}

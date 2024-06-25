/**
 * @file game_functions.c
 * @brief Функции, отвечающие за инициализацию и запуск игры.
 *
 * @ingroup GameTetris
 */

#include "game_functions.h"

/**
 * @ingroup GameTetris
 * @brief Функция для инициализации необходимых параметров при запуске игры.
 *
 * Инициализация текущего состояния игры и создание необходимых переменных для
 * работы программы. Запускает цикл работы игры до тех пор, пока состояние не
 * станет равно Exit. В зависимости от текущего состояния игры запускает
 * соответвующий Handler (бработчик) для того или иного действия.
 */
void GameLoop() {
  InitializeColors();
  TetBlock_t tetBlock = {0};
  GameInfo_t *gameInfo = CurrentGameInfo();
  bool exit = false;
  int lastMoveTime = clock();
  int moveDelay = gameInfo->speed;
  while (exit == false) {
    State_t *state = CurrentState();
    if (*state == GameStart) {
      UpdateUserAction(&tetBlock, gameInfo);
      HandleGameStart(&tetBlock, gameInfo);
    } else if (*state == Spawn) {
      HandleSpawn(&tetBlock, gameInfo);
    } else if (*state == Attaching) {
      HandleAttaching(&tetBlock, gameInfo);
    } else if (*state == Moving) {
      HandleMoving(gameInfo, &lastMoveTime, &moveDelay);
      UpdateUserAction(&tetBlock, gameInfo);
    } else if (*state == Shifting) {
      HandleShifting(&tetBlock, gameInfo);
    } else if (*state == GamePause) {
      *gameInfo = updateCurrentState();
      UpdateUserAction(&tetBlock, gameInfo);
    } else if (*state == GameOver) {
      *gameInfo = updateCurrentState();
      UpdateUserAction(&tetBlock, gameInfo);
    } else if (*state == Exit) {
      exit = true;
    }
    if (exit == false) {
      PrintFrontEnd();
    }
  }
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}

/**
 * @ingroup GameTetris
 * @brief Функция для обработки пользовательского ввода.
 *
 * При нажатии какой-либо кнопки, обрабатывает это нажатие и преобразует в
 * переменную, которая потом передается на backend, посколько нажатия с помощью
 * ncurses не могут быть обработаны без подключения этой библиотеки.
 *
 * @param tetBlock Указатель на текущую фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void UpdateUserAction(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  int input = getch();
  int processedInput = 0;
  switch (input) {
    case KEY_LEFT:
      processedInput = BUTTON_LEFT;
      break;
    case KEY_RIGHT:
      processedInput = BUTTON_RIGHT;
      break;
    case KEY_DOWN:
      processedInput = BUTTON_DOWN;
      break;
    case ' ':
      processedInput = BUTTON_SPACE;
      break;
    case 27:
      processedInput = BUTTON_ESCAPE;
      break;
    case 112:
      processedInput = BUTTON_PAUSE;
      break;
    case '\n':
      processedInput = BUTTON_ENTER;
      break;
    default:
      break;
  }
  ProcessUserAction(processedInput, tetBlock, gameInfo);
}

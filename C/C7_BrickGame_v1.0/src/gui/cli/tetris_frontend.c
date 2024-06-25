/**
 * @file tetris_frontend.c
 * @brief Функции, отвечающие за отрисовку пользовательского интерфейса.
 *
 * @ingroup Frontend
 */

#include "tetris_frontend.h"

/**
 * @ingroup Frontend
 * @brief Функция, возвращающая указатель на булеву переменную.
 *
 * Данная фугкция возвращает указатель на статическую переменную, которая
 * отвечает за то, что финальнэй экран с результатами игры отрисован.
 *
 * @return Возвращает текущий статус отрисовки.
 */
bool *EndScreenPrinted() {
  static bool endScreenIsPrinted = false;
  return &endScreenIsPrinted;
}

/**
 * @ingroup Frontend
 * @brief Функция для инициализации палитры цветов для отрисовки интерфейса.
 *
 * Первый параметр в init_pair() отвечает за индекс пары, второй параметр - цвет
 * текста, третий параметр - цвет фона.
 */
void InitializeColors() {
  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_RED, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
}

/**
 * @ingroup Frontend
 * @brief Функция для отрисовки всего пользовательского интерфейса в данный
 * момент игры.
 *
 * В функции определяется текущее состояние игры, после чего происходит
 * отрисовка необходимых элементов.
 */
void PrintFrontEnd() {
  State_t *state = CurrentState();
  GameInfo_t *gameInfo = CurrentGameInfo();
  refresh();
  if (*state == GameStart) {
    PrintStartMenu();
  } else if (*state == Spawn) {
    clear();
    PrintFigures(*gameInfo);
    PrintField();
    PrintGameControls();
  } else if (*state == GameOver) {
    if (*EndScreenPrinted() == false) {
      clear();
      PrintEndScreen();
      *EndScreenPrinted() = true;
    }
  } else if (*state == GamePause) {
    PrintPause(true);
  } else {
    PrintPause(false);
    PrintStats();
    PrintFigures(*gameInfo);
  }
}

/**
 * @ingroup Frontend
 * @brief Функция для отрисовки стартового меню.
 *
 * Данная функция отрисовывает на экране информацию об игре, о том, как
 * запустить или выйти из нее.
 */
void PrintStartMenu() {
  attron(COLOR_PAIR(1));
  mvprintw(6, 10, "***************************");
  mvprintw(7, 10, "*                         *");
  mvprintw(8, 10, "*  BrickGame by raisinwr  *");
  mvprintw(9, 10, "*                         *");
  mvprintw(10, 10, "*         Tetris          *");
  mvprintw(11, 10, "*                         *");
  mvprintw(12, 10, "* Press <Enter> to start  *");
  mvprintw(13, 10, "* or press <ESC> to quit  *");
  mvprintw(14, 10, "*                         *");
  mvprintw(15, 10, "***************************");
  attroff(COLOR_PAIR(1));
  refresh();
}

/**
 * @ingroup Frontend
 * @brief Функция для отрисовки границ игрового поля и границ для все статистик.
 *
 * Данная функция отрисовывает так называемые прямоугольники, которые являются
 * границами для каждой из статистик игры.
 */
void PrintField() {
  attron(COLOR_PAIR(1));
  PrintRectangle(FIELD_X_START, FIELD_X_END, FIELD_Y_START, FIELD_Y_END);
  mvprintw(1, 30, "NEXT");
  PrintRectangle(24, 41, 2, 8);
  PrintRectangle(24, 41, 10, 12);
  PrintRectangle(24, 41, 13, 15);
  PrintRectangle(24, 41, 16, 18);
  PrintRectangle(24, 41, 19, 21);
  attroff(COLOR_PAIR(1));
}

/**
 * @ingroup Frontend
 * @brief Функция для отрисовки границы в виде прямоугольника с краями,
 * передаваемыми в виде параметров.
 *
 * Данная функция отрисовывает прямоугольники через циклы по заданным
 * параметрам.
 *
 * @param startX Начало прямоугольника по оси X.
 * @param endX Конец прямоугольника по оси X.
 * @param startY Начало прямоугольника по оси Y.
 * @param endY Конец прямоугольника по оси Y.
 */
void PrintRectangle(int startX, int endX, int startY, int endY) {
  for (int y = startY; y <= endY; y++) {
    mvaddch(y, startX, ACS_VLINE | COLOR_PAIR(1));
    mvaddch(y, endX, ACS_VLINE | COLOR_PAIR(1));
  }
  for (int x = startX; x <= endX; x++) {
    mvaddch(startY, x, ACS_HLINE | COLOR_PAIR(1));
    mvaddch(endY, x, ACS_HLINE | COLOR_PAIR(1));
  }
  mvaddch(startY, startX, ACS_ULCORNER | COLOR_PAIR(1));
  mvaddch(startY, endX, ACS_URCORNER | COLOR_PAIR(1));
  mvaddch(endY, startX, ACS_LLCORNER | COLOR_PAIR(1));
  mvaddch(endY, endX, ACS_LRCORNER | COLOR_PAIR(1));
}

/**
 * @ingroup Frontend
 * @brief Функция для отрисовки всех фигур на поле.
 *
 * Данная функция отрисовывает символ части фигуры ([]) на поле в тех местах,
 * где уже установлены какие-либо фигуры, либо же движутся фигуры.
 */
void PrintFigures() {
  GameInfo_t gameInfo = *CurrentGameInfo();
  for (int i = 1; i < FIELD_Y_END; i++) {
    for (int j = 0; j < FIELD_X_END / 2 + 1; j++) {
      if (gameInfo.field[i][j] == 1 || gameInfo.field[i][j] == 2) {
        mvprintw(i, j * 2 - 1, "[]");
      } else if (gameInfo.field[i][j] == 0) {
        mvprintw(i, j * 2 - 1, "  ");
      }
    }
  }
  attroff(COLOR_PAIR(2));
}

/**
 * @ingroup Frontend
 * @brief Функция для отрисовки статистики в текущий момент игры.
 *
 * Данная функция определяет текущий момент игры с помощью функции
 * CurrentGameInfo(), после чего выводит на экран полную информацию о статистике
 * игрока в данный момент времени.
 */
void PrintStats() {
  GameInfo_t gameInfo = *CurrentGameInfo();
  attron(COLOR_PAIR(3));
  mvprintw(11, 25, "RECORD : %d", gameInfo.high_score);
  mvprintw(17, 25, "SCORE  : %d", gameInfo.score);
  mvprintw(14, 25, "LEVEL  : %d", gameInfo.level);
  int speedLevel = (650 - gameInfo.speed) / 60 + 1;
  if (speedLevel == 10) {
    mvprintw(20, 25, "SPEED  : MAX");
  } else {
    mvprintw(20, 25, "SPEED  : %d", speedLevel);
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (gameInfo.next[i][j] == 1) {
        mvprintw(i + 3, 29 + j * 2, "[]");
      } else {
        mvprintw(i + 3, 29 + j * 2, "  ");
      }
    }
  }
  attroff(COLOR_PAIR(3));
}

/**
 * @ingroup Frontend
 * @brief Функция для отрисовки информации об управлении в игре.
 *
 * Данная функция отрисовывает полную информацию о том, какие кнопки
 * используются в игре для того или иного действия.
 */
void PrintGameControls() {
  attron(COLOR_PAIR(1));
  mvprintw(7, 60, "GAME CONTROLS");
  PrintRectangle(48, 85, 8, 15);
  mvprintw(9, 50, "Arrow Down  - Figure fall");
  mvprintw(10, 50, "Arrow Left  - Figure move left");
  mvprintw(11, 50, "Arrow Right - Figure move right");
  mvprintw(12, 50, "Space       - Rotate figure");
  mvprintw(13, 50, "P           - Pause game");
  mvprintw(14, 50, "Esc         - Exit game");
  attroff(COLOR_PAIR(1));
}

/**
 * @ingroup Frontend
 * @brief Функция для отрисовки строки паузы, в случае, если игра
 * приостановлена.
 *
 * Данная функция отображает надпись "Pause", если игра приостановлена и стирает
 * эту надпись, если игра вновь возобновлена.
 */
void PrintPause(bool isPaused) {
  if (isPaused) {
    attron(COLOR_PAIR(3));
    mvprintw(9, 30, "PAUSED");
    attroff(COLOR_PAIR(3));
  } else {
    mvprintw(9, 30, "      ");
  }
}

/**
 * @ingroup Frontend
 * @brief Функция для отрисовки финального экрана с результатами игры.
 *
 * Данная функция отрисоывает результаты игры после ее завершения, а также
 * информацию о том, как выйти из игры.
 */
void PrintEndScreen() {
  GameInfo_t gameInfo = *CurrentGameInfo();
  attron(COLOR_PAIR(4));
  mvprintw(6, 20, "Your Result: %d", gameInfo.score);
  mvprintw(8, 18, "Press <ESC> to quit");
  attroff(COLOR_PAIR(4));
}

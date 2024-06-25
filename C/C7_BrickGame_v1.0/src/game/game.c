/**
 * @file game.c
 * @brief Файл с главной функцией запуска игры.
 *
 * @ingroup GameTetris
 */

#include "game_functions.h"

/**
 * @ingroup GameTetris
 * @brief Главная функция запуска.
 *
 * Данная функция выполняет запуск игры.
 *
 * @return 0 - в случае успеха, -1 - в случае ошибки.
 */
int main() {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(FALSE);
  nodelay(stdscr, TRUE);
  srand(time(NULL));
  GameLoop();
  endwin();
  return 0;
}

#ifndef TETRIS_GUI_H
#define TETRIS_GUI_H

#include <ncurses.h>

#include "../../brick_game/tetris/tetris_backend.h"

/**
 * @file tetris_frontend.h
 * @brief Заголовочный файл, отвечающий за отрисовку frontend'a игры.
 *
 * @defgroup Frontend
 */

void PrintFrontEnd();

void InitializeColors();
void PrintStartMenu();
void PrintField();
void PrintRectangle(int startX, int endX, int startY, int endY);
void PrintFigures();
void PrintStats();
void PrintGameControls();
void PrintPause(bool isPaused);
bool *EndScreenPrinted();
void PrintEndScreen();

#endif

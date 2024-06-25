#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include "../brick_game/tetris/tetris_backend.h"
#include "../gui/cli/tetris_frontend.h"

/**
 * @file game_functions.h
 * @brief Заголовочный файл, отвечающий за логику игры.
 *
 * @defgroup GameTetris
 */

void GameLoop();
void UpdateUserAction(TetBlock_t *tetBlock, GameInfo_t *gameInfo);

#endif

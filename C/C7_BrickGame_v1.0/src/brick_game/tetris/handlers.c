/**
 * @file handlers.c
 * @brief Функции, отвечающие за обработку состояний игры.
 *
 * @ingroup Handlers
 */

#include "tetris_backend.h"

/**
 * @ingroup Handlers
 * @brief Функция, отвечающая за обработку состояния игры при запуске.
 *
 * Данная функция обновляет текущее состояние игры и, если игра становится в
 * состоянии Spawn, то запускает функции для выбора и спавна движущейся и
 * следующей фигур.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void HandleGameStart(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  *gameInfo = updateCurrentState();
  if (*CurrentState() == Spawn) {
    ChooseFigure(tetBlock, gameInfo);
    SpawnFigure(tetBlock, gameInfo);
  }
}

/**
 * @ingroup Handlers
 * @brief Функция, отвечающая за обработку состояния игры при спавне.
 *
 * Данная функция запускает функции для выбора и спавна движущейся и следующей
 * фигур и устанавливает текущее состояние в Moving.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void HandleSpawn(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  SpawnFigure(tetBlock, gameInfo);
  *CurrentState() = Moving;
}

/**
 * @ingroup Handlers
 * @brief Функция, отвечающая за обработку состояния игры при установке фигуры.
 *
 * Данная функция устанавливает движущуюся фигуру на игровом поле, после чего
 * очищает заполенные линии, если таковые имеются, обновляет текущее состояния
 * игры и выбирает следующую фигуру, после чего изменяет состояние на GameOver,
 * если новую фигуру невозможно заспавнить на поле, либо же Spawn, в противном
 * случае.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void HandleAttaching(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  PlantFigure(*tetBlock, gameInfo);
  RemoveLines(gameInfo);
  *gameInfo = updateCurrentState();
  ChooseFigure(tetBlock, gameInfo);
  if (CheckSpawnCollision(*tetBlock, *gameInfo)) {
    *CurrentState() = GameOver;
  } else {
    *CurrentState() = Spawn;
  }
}

/**
 * @ingroup Handlers
 * @brief Функция, отвечающая за обработку состояния игры при падении фигуры.
 *
 * Данная функция просчитывает период, с которым будет падать вниз движущаяся
 * фигура, берет текущее время, скорость и изменяет состояние игры на Shifting,
 * если пришло время для перемещения.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void HandleMoving(GameInfo_t *gameInfo, int *lastMoveTime, int *moveDelay) {
  *moveDelay = gameInfo->speed;
  int currentTime = clock();
  if (((clock() - *lastMoveTime) * 1000 / CLOCKS_PER_SEC) >= *moveDelay) {
    *CurrentState() = Shifting;
    *lastMoveTime = currentTime;
  }
}

/**
 * @ingroup Handlers
 * @brief Функция, отвечающая за обработку состояния игры при сдвиге фигуры.
 *
 * Данная функция изменяет состояние игры на Attaching в случае, если падающая
 * фигура в данный момент столкнулась с краем поля, либо с уже установленными
 * фигурами, в противном случае перемещает фигуру на одну единицу вниз и
 * аналогичным образом изменяет состояние игры.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void HandleShifting(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  if (!CheckCollision(*tetBlock, *gameInfo)) {
    MoveFigureDown(tetBlock, gameInfo);
    if (CheckCollision(*tetBlock, *gameInfo)) {
      *CurrentState() = Attaching;
    } else {
      *CurrentState() = Moving;
    }
  } else {
    *CurrentState() = Attaching;
  }
}

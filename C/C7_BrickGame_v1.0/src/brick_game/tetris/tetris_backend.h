#ifndef TETRIS_H
#define TETRIS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @file tetris_backend.h
 * @brief Заголовочный файл, отвечающий за backend игры
 *
 * @defgroup Backend
 * @defgroup Figures
 * @defgroup FSM
 * @defgroup Handlers
 */

#define FIELD_X_START 0
#define FIELD_X_END 21
#define FIELD_Y_START 0
#define FIELD_Y_END 21

#define BUTTON_LEFT 1
#define BUTTON_RIGHT 2
#define BUTTON_DOWN 3
#define BUTTON_SPACE 4
#define BUTTON_ESCAPE 5
#define BUTTON_PAUSE 6
#define BUTTON_ENTER 7

/**
 * @brief Перечисление действий пользователя в игре Tetris.
 */
typedef enum {
  Start,     /**< Начать игру */
  Pause,     /**< Поставить игру на паузу */
  Terminate, /**< Завершить игру */
  Left,      /**< Движение фигуры влево */
  Right,     /**< Движение фигуры вправо */
  Up,    /**< Движение фигуры вверх (не активно) */
  Down,  /**< Ускорение падения фигуры */
  Action /**< Действие (поворот фигуры) */
} UserAction_t;

/**
 * @brief Структура, содержащая информацию о текущем состоянии игры Tetris.
 */
typedef struct {
  int **field;    /**< Поле игры */
  int **next;     /**< Следующая фигура */
  int score;      /**< Текущий счёт */
  int high_score; /**< Рекордный счёт */
  int level;      /**< Текущий уровень */
  int speed;      /**< Текущая скорость */
  int pause;      /**< Флаг паузы игры */
} GameInfo_t;

/**
 * @brief Перечисление состояний КА игры Tetris.
 */
typedef enum {
  GameStart, /**< Начальное состояние */
  GamePause, /**< Состояние паузы */
  Spawn,     /**< Состояние спавна фигуры */
  Moving,    /**< Состояние движения фигуры */
  Shifting,  /**< Состояние сдвига фигуры вниз */
  Attaching, /**< Состояние присоединения фигуры */
  GameOver,  /**< Состояние завершения игры */
  Exit       /**< Состояние выхода из игры */
} State_t;

/**
 * @brief Структура, содержащая информацию о текущем движущемся блоке.
 */
typedef struct {
  int currentBlock[4][4]; /**< Тип фигуры */
  int positionX;          /**< Позиция фигуры по оси X */
  int positionY;          /**< Позиция фигуры по оси Y */
} TetBlock_t;

// Tetris Backend
State_t *CurrentState();
GameInfo_t *CurrentGameInfo();
GameInfo_t GameInfoInitialization();
int **CreateGameField();
int **CreateNextFigure();
GameInfo_t updateCurrentState();
void WriteBestScoreInFile(int highScore);
void RemoveLines(GameInfo_t *gameInfo);
void FreeGameField(int **gameField);
void FreeNextFigure(int **nextFigure);

// Handlers
void HandleGameStart(TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void HandleSpawn(TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void HandleAttaching(TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void HandleMoving(GameInfo_t *gameInfo, int *lastMoveTime, int *moveDelay);
void HandleShifting(TetBlock_t *tetBlock, GameInfo_t *gameInfo);

// FSM
void ProcessUserAction(int input, TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void userInput(UserAction_t action, bool hold);

// Figures Creation
void ChooseFigure(TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void GenerateFigure(int newFigure[4][4]);
void FillFigureLine(int figure[4][4]);
void FillFigureT(int figure[4][4]);
void FillFigureSquare(int figure[4][4]);
void FillFigureLeftL(int figure[4][4]);
void FillFigureRightL(int figure[4][4]);
void FillFigureLeftZ(int figure[4][4]);
void FillFigureRightZ(int figure[4][4]);

// Figures Movement
bool MovingFigure(int input, TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void SpawnFigure(TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void CleanPreviousPosition(TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void SetNewPosition(TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void MoveFigureDown(TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void MoveFigureLeft(TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void MoveFigureRight(TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void RotateFigure(TetBlock_t *tetBlock, GameInfo_t *gameInfo);
void PlantFigure(TetBlock_t tetBlock, GameInfo_t *gameInfo);
bool CheckCollision(TetBlock_t tetBlock, GameInfo_t gameInfo);
bool CheckLeftRightCollision(TetBlock_t tetBlock, GameInfo_t gameInfo);
bool CheckRotateCollision(int tempBlock[4][4], TetBlock_t tetBlock,
                          GameInfo_t gameInfo);
bool CheckSpawnCollision(TetBlock_t tetBlock, GameInfo_t gameInfo);

#endif

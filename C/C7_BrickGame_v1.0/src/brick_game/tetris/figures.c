/**
 * @file figures.c
 * @brief Функции, отвечающие за взаимодействие с фигурами в игре.
 *
 * @ingroup Figures
 */

#include "tetris_backend.h"

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за передвижение фигур в зависимости от нажатия
 * клавиши игроком.
 *
 * Данная функция отвечает за логику движения фигур в игре.
 * При нажатии какой-либо из кнопок вызывается соответсвующий обработчик для
 * передвижения в ту или иную сторону.
 *
 * @param input Пользовательский ввод.
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
bool MovingFigure(int input, TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  bool movingFigure = false;
  if (input == BUTTON_LEFT) {
    userInput(Left, false);
    MoveFigureLeft(tetBlock, gameInfo);
    movingFigure = true;
  } else if (input == BUTTON_RIGHT) {
    userInput(Right, false);
    MoveFigureRight(tetBlock, gameInfo);
    movingFigure = true;
  } else if (input == BUTTON_DOWN) {
    userInput(Down, true);
    MoveFigureDown(tetBlock, gameInfo);
    movingFigure = true;
  } else if (input == BUTTON_SPACE) {
    userInput(Action, false);
    RotateFigure(tetBlock, gameInfo);
    if (CheckCollision(*tetBlock, *gameInfo)) {
      *CurrentState() = Attaching;
    }
    movingFigure = true;
  } else if (input == BUTTON_ESCAPE) {
    userInput(Terminate, false);
  } else if (input == BUTTON_PAUSE) {
    userInput(Pause, false);
  }
  if (movingFigure && CheckCollision(*tetBlock, *gameInfo)) {
    *CurrentState() = Attaching;
  }
  return movingFigure;
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за спавн фигур на игровом поле.
 *
 * Данная функция заполняет ячейки на игровом поле в зависимости от положения
 * текущей движущейся фигуры.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void SpawnFigure(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tetBlock->currentBlock[i][j] == 1) {
        gameInfo->field[tetBlock->positionY + i][tetBlock->positionX + j] = 1;
      }
    }
  }
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за очистку предыдущей позиции фигуры.
 *
 * Данная функция очищает ячейки на игровом поле (ставит значения 0), когда
 * фигура изменяет свое положение.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void CleanPreviousPosition(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tetBlock->currentBlock[i][j] == 1) {
        gameInfo->field[tetBlock->positionY + i][tetBlock->positionX + j] = 0;
      }
    }
  }
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за установку новой позиции фигуры.
 *
 * Данная функция устанавливает текущую фигуру на игровое поле в завивисимости
 * от ее положения (ставит значения 1).
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void SetNewPosition(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tetBlock->currentBlock[i][j] == 1) {
        gameInfo->field[tetBlock->positionY + i][tetBlock->positionX + j] = 1;
      }
    }
  }
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за передвижение фигуры вниз.
 *
 * Данная функция перемещает фигуру на игровом поле на одну единицу вниз.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void MoveFigureDown(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  CleanPreviousPosition(tetBlock, gameInfo);
  tetBlock->positionY++;
  SetNewPosition(tetBlock, gameInfo);
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за передвижение фигуры влево.
 *
 * Данная функция перемещает фигуру на игровом поле на одну единицу вправо
 * только в том, случае, если она не касается краев поля или других уже
 * установленных фигур.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void MoveFigureLeft(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  CleanPreviousPosition(tetBlock, gameInfo);
  tetBlock->positionX--;
  if (CheckLeftRightCollision(*tetBlock, *gameInfo)) {
    tetBlock->positionX++;
  }
  SetNewPosition(tetBlock, gameInfo);
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за передвижение фигуры вправо.
 *
 * Данная функция перемещает фигуру на игровом поле на одну единицу вправо
 * только в том, случае, если она не касается краев поля или других уже
 * установленных фигур.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void MoveFigureRight(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  CleanPreviousPosition(tetBlock, gameInfo);
  tetBlock->positionX++;
  if (CheckLeftRightCollision(*tetBlock, *gameInfo)) {
    tetBlock->positionX--;
  }
  SetNewPosition(tetBlock, gameInfo);
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за вращение фигуры.
 *
 * Данная функция вращает фигуры по принципу транспонирования матрицы (на 90
 * градусов направо) в том, случае, если она не касается краев поля или других
 * уже установленных фигур.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void RotateFigure(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  int tempBlock[4][4] = {0};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      tempBlock[j][i] = tetBlock->currentBlock[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      int tmp = tempBlock[i][j];
      tempBlock[i][j] = tempBlock[i][3 - j];
      tempBlock[i][3 - j] = tmp;
    }
  }
  CleanPreviousPosition(tetBlock, gameInfo);
  if (CheckRotateCollision(tempBlock, *tetBlock, *gameInfo) == false) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        tetBlock->currentBlock[i][j] = tempBlock[i][j];
      }
    }
  }
  SetNewPosition(tetBlock, gameInfo);
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за установку движущейся фигуры на игровом поле.
 *
 * Данная функция устанавливает движущуюся фигуру на игровом поле, заменяя
 * значения матрицы поля на 2 в тех местах, где ставится фигура.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void PlantFigure(TetBlock_t tetBlock, GameInfo_t *gameInfo) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tetBlock.currentBlock[i][j] == 1) {
        gameInfo->field[tetBlock.positionY + i][tetBlock.positionX + j] = 2;
      }
    }
  }
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за проверку столкновений при движении вниз.
 *
 * Данная функция проверяет сталкивается ли движущаяся фигура с границами поля
 * или уже установленной фигурой на поле при движении вниз.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 *
 * @return result - true, если столкновение произошло, false - в противном
 * случае.
 */
bool CheckCollision(TetBlock_t tetBlock, GameInfo_t gameInfo) {
  bool result = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tetBlock.currentBlock[i][j] == 1) {
        int y = tetBlock.positionY + i;
        int x = tetBlock.positionX + j;
        if (y + 1 >= FIELD_Y_END || x - 1 < FIELD_X_START ||
            x > FIELD_X_END / 2) {
          result = true;
        } else if (y + 1 < FIELD_Y_END && gameInfo.field[y + 1][x] == 2) {
          result = true;
        }
      }
    }
  }
  return result;
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за проверку столкновений при движении влево и
 * вправо.
 *
 * Данная функция проверяет сталкивается ли движущаяся фигура с границами поля
 * или уже установленной фигурой на поле при движении влево или вправо.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 *
 * @return result - true, если столкновение произошло, false - в противном
 * случае.
 */
bool CheckLeftRightCollision(TetBlock_t tetBlock, GameInfo_t gameInfo) {
  bool result = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tetBlock.currentBlock[i][j] == 1) {
        int y = tetBlock.positionY + i;
        int x = tetBlock.positionX + j;
        if (y + 1 >= FIELD_Y_END || x - 1 < FIELD_X_START ||
            x > FIELD_X_END / 2) {
          result = true;
        } else if (gameInfo.field[y][x] == 2) {
          result = true;
        }
      }
    }
  }
  return result;
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за проверку столкновений при повороте фигуры.
 *
 * Данная функция проверяет сталкивается ли движущаяся фигура с границами поля
 * или уже установленной фигурой на поле при ее повороте.
 *
 * @param tempBlock Массив, хранящей в себе потенциальный внешний вид фигуры
 * после вращения.
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 *
 * @return result - true, если столкновение произошло, false - в противном
 * случае.
 */
bool CheckRotateCollision(int tempBlock[4][4], TetBlock_t tetBlock,
                          GameInfo_t gameInfo) {
  bool result = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tempBlock[i][j] == 1) {
        int y = tetBlock.positionY + i;
        int x = tetBlock.positionX + j;
        if (x - 1 < FIELD_X_START || x > FIELD_X_END / 2 ||
            y + 1 >= FIELD_Y_END || gameInfo.field[y][x] == 2) {
          result = true;
        }
      }
    }
  }
  return result;
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за проверку столкновений при спавне новой фигуры
 * на поле.
 *
 * Данная функция проверяет будет ли место на поле для создания новой фигуры.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 *
 * @return result - true, если столкновение произошло, false - в противном
 * случае.
 */
bool CheckSpawnCollision(TetBlock_t tetBlock, GameInfo_t gameInfo) {
  bool result = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tetBlock.currentBlock[i][j] == 1) {
        int y = tetBlock.positionY + i;
        int x = tetBlock.positionX + j;
        if (y >= FIELD_Y_END || x < FIELD_X_START || x > FIELD_X_END / 2 ||
            gameInfo.field[y][x] == 2) {
          result = true;
        }
      }
    }
  }
  return result;
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за выбор фигур.
 *
 * Данная функция заполняет информацию о том, какая фигура будет создана на
 * игровом поле в данный момент времени и какая фигура будет следующей, заполняя
 * соответсвующие поля в tetBlock и gameInfo->next.
 *
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void ChooseFigure(TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  tetBlock->positionX = 4;
  tetBlock->positionY = 0;
  int newFigure[4][4] = {0};
  GenerateFigure(newFigure);
  bool isEmptyNextFigure = true;
  for (int i = 0; i < 4 && isEmptyNextFigure; i++) {
    for (int j = 0; j < 4 && isEmptyNextFigure; j++) {
      if (gameInfo->next[i][j] != 0) {
        isEmptyNextFigure = false;
      }
    }
  }
  if (isEmptyNextFigure) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        tetBlock->currentBlock[i][j] = newFigure[i][j];
      }
    }
  } else {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        tetBlock->currentBlock[i][j] = gameInfo->next[i][j];
      }
    }
  }
  GenerateFigure(newFigure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      gameInfo->next[i][j] = newFigure[i][j];
    }
  }
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за генерацию фигур.
 *
 * Данная функция случайным образом выбирает фигуры из всех возможных в игре.
 *
 * @param newFigure Массив, который соответствует новой фигуре.
 */
void GenerateFigure(int newFigure[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      newFigure[i][j] = 0;
    }
  }
  switch (rand() % 7) {
    case 0:
      FillFigureLine(newFigure);
      break;
    case 1:
      FillFigureSquare(newFigure);
      break;
    case 2:
      FillFigureT(newFigure);
      break;
    case 3:
      FillFigureLeftL(newFigure);
      break;
    case 4:
      FillFigureRightL(newFigure);
      break;
    case 5:
      FillFigureLeftZ(newFigure);
      break;
    case 6:
      FillFigureRightZ(newFigure);
      break;
  }
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за генерацию линии.
 *
 * Данная функция заполняет массив для фигуры в соответствии со значениями для
 * линии.
 *
 * @param figure Массив, который соответствует фигуре.
 */
void FillFigureLine(int figure[4][4]) {
  for (int i = 0; i < 4; i++) {
    figure[1][i] = 1;
  }
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за генерацию квадрата.
 *
 * Данная функция заполняет массив для фигуры в соответствии со значениями для
 * квадрата.
 *
 * @param figure Массив, который соответствует фигуре.
 */
void FillFigureSquare(int figure[4][4]) {
  for (int i = 1; i < 3; i++) {
    for (int j = 1; j < 3; j++) {
      figure[i][j] = 1;
    }
  }
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за генерацию левого уголка.
 *
 * Данная функция заполняет массив для фигуры в соответствии со значениями для
 * левого уголка.
 *
 * @param figure Массив, который соответствует фигуре.
 */
void FillFigureLeftL(int figure[4][4]) {
  figure[1][1] = 1;
  figure[2][1] = 1;
  figure[3][1] = 1;
  figure[3][0] = 1;
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за генерацию правого уголка.
 *
 * Данная функция заполняет массив для фигуры в соответствии со значениями для
 * правого уголка.
 *
 * @param figure Массив, который соответсвует фигуре.
 */
void FillFigureRightL(int figure[4][4]) {
  figure[1][1] = 1;
  figure[2][1] = 1;
  figure[3][1] = 1;
  figure[3][2] = 1;
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за генерацию левого сгиба.
 *
 * Данная функция заполняет массив для фигуры в соответствии со значениями для
 * левого сгиба.
 *
 * @param figure Массив, который соответсвует фигуре.
 */
void FillFigureLeftZ(int figure[4][4]) {
  figure[1][0] = 1;
  figure[1][1] = 1;
  figure[2][1] = 1;
  figure[2][2] = 1;
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за генерацию правого сгиба.
 *
 * Данная функция заполняет массив для фигуры в соответствии со значениями для
 * правого сгиба.
 *
 * @param figure Массив, который соответсвует фигуре.
 */
void FillFigureRightZ(int figure[4][4]) {
  figure[1][1] = 1;
  figure[1][2] = 1;
  figure[2][0] = 1;
  figure[2][1] = 1;
}

/**
 * @ingroup Figures
 * @brief Функция, отвечающая за генерацию T-образной фигуры.
 *
 * Данная функция заполняет массив для фигуры в соответствии со значениями для
 * T-образной фигуры.
 *
 * @param figure Массив, который соответсвует фигуре.
 */
void FillFigureT(int figure[4][4]) {
  figure[1][1] = 1;
  figure[2][0] = 1;
  figure[2][1] = 1;
  figure[2][2] = 1;
}
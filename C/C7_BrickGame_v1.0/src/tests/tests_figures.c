#include "tests.h"

// Проверка заполнения линии
START_TEST(test_fill_line) {
  int figureToFill[4][4] = {0};
  FillFigureLine(figureToFill);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(figureToFill[0][i], 0);
    ck_assert_int_eq(figureToFill[1][i], 1);
    ck_assert_int_eq(figureToFill[2][i], 0);
    ck_assert_int_eq(figureToFill[3][i], 0);
  }
}
END_TEST

// Проверка заполнения квдарата
START_TEST(test_fill_square) {
  int figureToFill[4][4] = {0};
  FillFigureSquare(figureToFill);
  for (int i = 1; i < 3; i++) {
    for (int j = 1; j < 3; j++) {
      ck_assert_int_eq(figureToFill[i][j], 1);
    }
  }
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(figureToFill[i][0], 0);
    ck_assert_int_eq(figureToFill[i][3], 0);
    if (i == 0 || i == 3) {
      ck_assert_int_eq(figureToFill[i][1], 0);
      ck_assert_int_eq(figureToFill[i][2], 0);
    }
  }
}
END_TEST

// Проверка заполнения левого угла
START_TEST(test_fill_left_l) {
  int figureToFill[4][4] = {0};
  FillFigureLeftL(figureToFill);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if ((j == 1 && i >= 1) || (i == 3 && j == 0)) {
        ck_assert_int_eq(figureToFill[i][j], 1);
      } else {
        ck_assert_int_eq(figureToFill[i][j], 0);
      }
    }
  }
}
END_TEST

// Проверка заполнения правого угла
START_TEST(test_fill_right_l) {
  int figureToFill[4][4] = {0};
  FillFigureRightL(figureToFill);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if ((j == 1 && i >= 1) || (i == 3 && j == 2)) {
        ck_assert_int_eq(figureToFill[i][j], 1);
      } else {
        ck_assert_int_eq(figureToFill[i][j], 0);
      }
    }
  }
}
END_TEST

// Проверка заполнения левой Z
START_TEST(test_fill_left_z) {
  int figureToFill[4][4] = {0};
  FillFigureLeftZ(figureToFill);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if ((i == 1 && (j == 0 || j == 1)) || (i == 2 && (j == 1 || j == 2))) {
        ck_assert_int_eq(figureToFill[i][j], 1);
      } else {
        ck_assert_int_eq(figureToFill[i][j], 0);
      }
    }
  }
}
END_TEST

// Проверка заполнения правой Z
START_TEST(test_fill_right_z) {
  int figureToFill[4][4] = {0};
  FillFigureRightZ(figureToFill);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if ((i == 1 && (j == 1 || j == 2)) || (i == 2 && (j == 0 || j == 1))) {
        ck_assert_int_eq(figureToFill[i][j], 1);
      } else {
        ck_assert_int_eq(figureToFill[i][j], 0);
      }
    }
  }
}
END_TEST

// Проверка заполнения T
START_TEST(test_fill_t) {
  int figureToFill[4][4] = {0};
  FillFigureT(figureToFill);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if ((i == 1 && j == 1) || (i == 2 && (j == 0 || j == 1 || j == 2))) {
        ck_assert_int_eq(figureToFill[i][j], 1);
      } else {
        ck_assert_int_eq(figureToFill[i][j], 0);
      }
    }
  }
}
END_TEST

// Проверка генерации фигур
START_TEST(test_generate_1) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  int currentFigureFilled = 0;
  int nextFigureFilled = 0;
  ChooseFigure(&tetBlock, gameInfo);
  ck_assert_int_eq(tetBlock.positionX, 4);
  ck_assert_int_eq(tetBlock.positionY, 0);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tetBlock.currentBlock[i][j] == 1) {
        currentFigureFilled = 1;
      }
      if (gameInfo->next[i][j] == 1) {
        nextFigureFilled = 1;
      }
    }
  }
  ck_assert_int_eq(currentFigureFilled, 1);
  ck_assert_int_eq(nextFigureFilled, 1);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка генерации фигур
START_TEST(test_generate_2) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  int currentFigureFilled = 0;
  int nextFigureFilled = 0;
  for (int i = 1; i < 3; i++) {
    for (int j = 1; j < 3; j++) {
      gameInfo->next[i][j] = 1;
    }
  }
  ChooseFigure(&tetBlock, gameInfo);
  ck_assert_int_eq(tetBlock.positionX, 4);
  ck_assert_int_eq(tetBlock.positionY, 0);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tetBlock.currentBlock[i][j] == 1) {
        currentFigureFilled = 1;
      }
      if (gameInfo->next[i][j] == 1) {
        nextFigureFilled = 1;
      }
    }
  }
  ck_assert_int_eq(currentFigureFilled, 1);
  ck_assert_int_eq(nextFigureFilled, 1);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка на сдвиг влево (можно сдвинуть)
START_TEST(test_moving_left_1) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 4;
  tetBlock.positionY = 6;
  FillFigureSquare(tetBlock.currentBlock);
  int movingFigure = MovingFigure(BUTTON_LEFT, &tetBlock, gameInfo);
  ck_assert_int_eq(movingFigure, 1);
  ck_assert_int_eq(tetBlock.positionX, 3);
  ck_assert_int_eq(tetBlock.positionY, 6);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка на сдвиг влево (нельзя сдвинуть)
START_TEST(test_moving_left_2) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 0;
  tetBlock.positionY = 6;
  FillFigureSquare(tetBlock.currentBlock);
  int movingFigure = MovingFigure(BUTTON_LEFT, &tetBlock, gameInfo);
  ck_assert_int_eq(movingFigure, 1);
  ck_assert_int_eq(tetBlock.positionX, 0);
  ck_assert_int_eq(tetBlock.positionY, 6);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка на сдвиг вправо (можно сдвинуть)
START_TEST(test_moving_right_1) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 5;
  tetBlock.positionY = 8;
  FillFigureSquare(tetBlock.currentBlock);
  int movingFigure = MovingFigure(BUTTON_RIGHT, &tetBlock, gameInfo);
  ck_assert_int_eq(movingFigure, 1);
  ck_assert_int_eq(tetBlock.positionX, 6);
  ck_assert_int_eq(tetBlock.positionY, 8);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка на сдвиг вправо (нельзя сдвинуть)
START_TEST(test_moving_right_2) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 9;
  tetBlock.positionY = 8;
  FillFigureSquare(tetBlock.currentBlock);
  int movingFigure = MovingFigure(BUTTON_RIGHT, &tetBlock, gameInfo);
  ck_assert_int_eq(movingFigure, 1);
  ck_assert_int_eq(tetBlock.positionX, 9);
  ck_assert_int_eq(tetBlock.positionY, 8);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Ускорение падения
START_TEST(test_moving_down) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 4;
  tetBlock.positionY = 8;
  FillFigureSquare(tetBlock.currentBlock);
  int movingFigure = MovingFigure(BUTTON_DOWN, &tetBlock, gameInfo);
  ck_assert_int_eq(movingFigure, 1);
  ck_assert_int_eq(tetBlock.positionX, 4);
  ck_assert_int_eq(tetBlock.positionY, 9);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Вращение фигуры
START_TEST(test_moving_rotating_1) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 4;
  tetBlock.positionY = 8;
  FillFigureLine(tetBlock.currentBlock);
  int movingFigure = MovingFigure(BUTTON_SPACE, &tetBlock, gameInfo);
  int expectedBlock[4][4] = {
      {0, 0, 1, 0},
      {0, 0, 1, 0},
      {0, 0, 1, 0},
      {0, 0, 1, 0},
  };
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(tetBlock.currentBlock[i][j], expectedBlock[i][j]);
    }
  }
  ck_assert_int_eq(movingFigure, 1);
  ck_assert_int_eq(tetBlock.positionX, 4);
  ck_assert_int_eq(tetBlock.positionY, 8);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Вращение фигуры
START_TEST(test_moving_rotating_2) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 9;
  tetBlock.positionY = 5;
  FillFigureLine(tetBlock.currentBlock);
  int movingFigure = MovingFigure(BUTTON_SPACE, &tetBlock, gameInfo);
  int expectedBlock[4][4] = {
      {0, 0, 0, 0},
      {1, 1, 1, 1},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
  };
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(tetBlock.currentBlock[i][j], expectedBlock[i][j]);
    }
  }
  ck_assert_int_eq(movingFigure, 1);
  ck_assert_int_eq(tetBlock.positionX, 9);
  ck_assert_int_eq(tetBlock.positionY, 5);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

START_TEST(test_moving_1) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  *CurrentState() = GameOver;
  int movingFigure = MovingFigure(BUTTON_ESCAPE, &tetBlock, gameInfo);
  ck_assert_int_eq(movingFigure, 0);
  ck_assert_int_eq(*CurrentState(), Exit);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

START_TEST(test_moving_2) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  *CurrentState() = GameStart;
  int movingFigure = MovingFigure(BUTTON_ESCAPE, &tetBlock, gameInfo);
  ck_assert_int_eq(movingFigure, 0);
  ck_assert_int_eq(*CurrentState(), Exit);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

START_TEST(test_moving_3) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  *CurrentState() = Moving;
  int movingFigure = MovingFigure(BUTTON_ESCAPE, &tetBlock, gameInfo);
  ck_assert_int_eq(movingFigure, 0);
  ck_assert_int_eq(*CurrentState(), GameOver);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

START_TEST(test_moving_4) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  *CurrentState() = GamePause;
  int movingFigure = MovingFigure(BUTTON_PAUSE, &tetBlock, gameInfo);
  ck_assert_int_eq(movingFigure, 0);
  ck_assert_int_eq(*CurrentState(), Moving);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

START_TEST(test_moving_5) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  *CurrentState() = Moving;
  int movingFigure = MovingFigure(BUTTON_PAUSE, &tetBlock, gameInfo);
  ck_assert_int_eq(movingFigure, 0);
  ck_assert_int_eq(*CurrentState(), GamePause);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка коллизии с другими блоками и краем поля
START_TEST(test_collision) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 9;
  tetBlock.positionY = 19;
  FillFigureSquare(tetBlock.currentBlock);
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    gameInfo->field[20][i] = 2;
  }
  int collision = CheckCollision(tetBlock, *gameInfo);
  ck_assert_int_eq(collision, 1);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка коллизии с другими блоками и краем поля
START_TEST(test_collision_left_right) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 4;
  tetBlock.positionY = 5;
  FillFigureSquare(tetBlock.currentBlock);
  gameInfo->field[7][6] = 2;
  int collision = CheckLeftRightCollision(tetBlock, *gameInfo);
  ck_assert_int_eq(collision, 1);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

Suite *suite_figures_creation(void) {
  Suite *suite = suite_create("figures_creation_cases");
  TCase *tests = tcase_create("figures_creation_tc");

  tcase_add_test(tests, test_fill_line);
  tcase_add_test(tests, test_fill_square);
  tcase_add_test(tests, test_fill_left_l);
  tcase_add_test(tests, test_fill_right_l);
  tcase_add_test(tests, test_fill_left_z);
  tcase_add_test(tests, test_fill_right_z);
  tcase_add_test(tests, test_fill_t);
  tcase_add_test(tests, test_generate_1);
  tcase_add_test(tests, test_generate_2);
  tcase_add_test(tests, test_moving_left_1);
  tcase_add_test(tests, test_moving_left_2);
  tcase_add_test(tests, test_moving_right_1);
  tcase_add_test(tests, test_moving_right_2);
  tcase_add_test(tests, test_moving_down);
  tcase_add_test(tests, test_moving_rotating_1);
  tcase_add_test(tests, test_moving_rotating_2);
  tcase_add_test(tests, test_moving_1);
  tcase_add_test(tests, test_moving_2);
  tcase_add_test(tests, test_moving_3);
  tcase_add_test(tests, test_moving_4);
  tcase_add_test(tests, test_moving_5);
  tcase_add_test(tests, test_collision);
  tcase_add_test(tests, test_collision_left_right);
  // tcase_add_test(tests, test_collision_left_right_2);

  suite_add_tcase(suite, tests);
  return suite;
}

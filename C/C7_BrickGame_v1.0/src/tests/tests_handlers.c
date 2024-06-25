#include "tests.h"

// Проверка обработчика старта игры
START_TEST(test_game_start_handler) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  int gameInfoFieldIsEmpty = 1;
  int nextFigureIsEmpty = 1;
  *CurrentState() = Spawn;
  HandleGameStart(&tetBlock, gameInfo);
  for (int i = 1; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      if (gameInfo->field[i][j] == 1) {
        gameInfoFieldIsEmpty = 0;
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tetBlock.currentBlock[i][j] == 1) {
        nextFigureIsEmpty = 0;
      }
    }
  }
  ck_assert_int_eq(gameInfoFieldIsEmpty, 0);
  ck_assert_int_eq(nextFigureIsEmpty, 0);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка обработчика спавна
START_TEST(test_game_spawn_handler) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  int gameInfoFieldIsEmpty = 1;
  tetBlock.positionX = 9;
  tetBlock.positionY = 10;
  FillFigureSquare(tetBlock.currentBlock);
  HandleSpawn(&tetBlock, gameInfo);
  for (int i = 1; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      if (gameInfo->field[i][j] == 1) {
        gameInfoFieldIsEmpty = 0;
      }
    }
  }
  ck_assert_int_eq(gameInfoFieldIsEmpty, 0);
  ck_assert_int_eq(*CurrentState(), Moving);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка обработчика присоединения
START_TEST(test_game_attaching_handler_1) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 4;
  tetBlock.positionY = 17;
  FillFigureSquare(tetBlock.currentBlock);
  for (int i = FIELD_X_START + 2; i <= FIELD_X_END / 2; i++) {
    gameInfo->field[20][i] = 2;
  }
  HandleAttaching(&tetBlock, gameInfo);
  ck_assert_int_eq(gameInfo->field[18][5], 2);
  ck_assert_int_eq(gameInfo->field[18][6], 2);
  ck_assert_int_eq(gameInfo->field[19][6], 2);
  ck_assert_int_eq(gameInfo->field[19][6], 2);
  ck_assert_int_eq(*CurrentState(), Spawn);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка обработчика присоединения
START_TEST(test_game_attaching_handler_2) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 0;
  tetBlock.positionY = 18;
  FillFigureSquare(tetBlock.currentBlock);
  for (int i = FIELD_X_START + 3; i <= FIELD_X_END / 2; i++) {
    gameInfo->field[20][i] = 2;
  }
  HandleAttaching(&tetBlock, gameInfo);
  for (int i = FIELD_X_START + 3; i <= FIELD_X_END / 2; i++) {
    ck_assert_int_eq(gameInfo->field[20][i], 0);
  }
  ck_assert_int_eq(*CurrentState(), Spawn);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка обработчика присоединения
START_TEST(test_game_attaching_handler_3) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 0;
  tetBlock.positionY = 18;
  FillFigureSquare(tetBlock.currentBlock);
  for (int i = FIELD_Y_START + 2; i < FIELD_Y_END; i++) {
    for (int j = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
      gameInfo->field[j][i] = 2;
    }
  }
  HandleAttaching(&tetBlock, gameInfo);
  ck_assert_int_eq(*CurrentState(), GameOver);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка обработчика движения
START_TEST(test_game_moving_handler) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  *CurrentState() = Moving;
  int delay = gameInfo->speed;
  int lastMoveTime = clock() - ((delay + 1) * CLOCKS_PER_SEC / 1000);
  HandleMoving(gameInfo, &lastMoveTime, &delay);
  ck_assert_int_eq(*CurrentState(), Shifting);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}

// Проверка обработчика сдвига
START_TEST(test_game_shifting_handler_1) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 0;
  tetBlock.positionY = 18;
  FillFigureSquare(tetBlock.currentBlock);
  HandleShifting(&tetBlock, gameInfo);
  ck_assert_int_eq(*CurrentState(), Attaching);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка обработчика сдвига
START_TEST(test_game_shifting_handler_2) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 0;
  tetBlock.positionY = 15;
  FillFigureSquare(tetBlock.currentBlock);
  HandleShifting(&tetBlock, gameInfo);
  ck_assert_int_eq(*CurrentState(), Moving);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка обработчика сдвига
START_TEST(test_game_shifting_handler_3) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 0;
  tetBlock.positionY = 17;
  FillFigureSquare(tetBlock.currentBlock);
  HandleShifting(&tetBlock, gameInfo);
  ck_assert_int_eq(*CurrentState(), Attaching);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

Suite *suite_handlers(void) {
  Suite *suite = suite_create("handlers_cases");
  TCase *tests = tcase_create("handlers_tc");

  tcase_add_test(tests, test_game_start_handler);
  tcase_add_test(tests, test_game_spawn_handler);
  tcase_add_test(tests, test_game_attaching_handler_1);
  tcase_add_test(tests, test_game_attaching_handler_2);
  tcase_add_test(tests, test_game_attaching_handler_3);
  tcase_add_test(tests, test_game_moving_handler);
  tcase_add_test(tests, test_game_shifting_handler_1);
  tcase_add_test(tests, test_game_shifting_handler_2);
  tcase_add_test(tests, test_game_shifting_handler_3);

  suite_add_tcase(suite, tests);
  return suite;
}

#include "tests.h"

// Проверка пользовательского ввода для запуска игры из начального меню
START_TEST(test_user_input_start_game) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  *CurrentState() = GameStart;
  ProcessUserAction(BUTTON_ENTER, &tetBlock, gameInfo);
  ck_assert_int_eq(*CurrentState(), Spawn);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка пользовательского ввода для выхода из игры в момент начального меню
START_TEST(test_user_input_start_game_exit) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  *CurrentState() = GameStart;
  ProcessUserAction(BUTTON_ESCAPE, &tetBlock, gameInfo);
  ck_assert_int_eq(*CurrentState(), Exit);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка пользовательского ввода для выхода из игры на конечном экране игры
START_TEST(test_user_input_game_over_exit) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  *CurrentState() = GameOver;
  ProcessUserAction(BUTTON_ESCAPE, &tetBlock, gameInfo);
  ck_assert_int_eq(*CurrentState(), Exit);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка пользовательского ввода для паузы игры
START_TEST(test_user_input_game_pause) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  *CurrentState() = Moving;
  ProcessUserAction(BUTTON_PAUSE, &tetBlock, gameInfo);
  ck_assert_int_eq(*CurrentState(), GamePause);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка пользовательского ввода для отключения паузы
START_TEST(test_user_input_game_pause_off) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  *CurrentState() = GamePause;
  ProcessUserAction(BUTTON_PAUSE, &tetBlock, gameInfo);
  ck_assert_int_eq(*CurrentState(), Moving);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка пользовательского ввода для выхода из игры в момент паузы
START_TEST(test_user_input_game_pause_exit) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  *CurrentState() = GamePause;
  ProcessUserAction(BUTTON_ESCAPE, &tetBlock, gameInfo);
  ck_assert_int_eq(*CurrentState(), GameOver);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка пользовательского ввода для установки фигуры
START_TEST(test_user_input_game_put_block) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  TetBlock_t tetBlock = {0};
  tetBlock.positionX = 5;
  tetBlock.positionY = 16;
  FillFigureSquare(tetBlock.currentBlock);
  for (int i = 4; i < 17; i++) {
    gameInfo->field[20][i] = 2;
  }
  *CurrentState() = Moving;
  ProcessUserAction(BUTTON_DOWN, &tetBlock, gameInfo);
  ck_assert_int_eq(*CurrentState(), Attaching);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

Suite *suite_fsm(void) {
  Suite *suite = suite_create("fsm_cases");
  TCase *tests = tcase_create("fsm_tc");

  tcase_add_test(tests, test_user_input_start_game);
  tcase_add_test(tests, test_user_input_start_game_exit);
  tcase_add_test(tests, test_user_input_game_over_exit);
  tcase_add_test(tests, test_user_input_game_pause);
  tcase_add_test(tests, test_user_input_game_pause_off);
  tcase_add_test(tests, test_user_input_game_pause_exit);
  tcase_add_test(tests, test_user_input_game_put_block);

  suite_add_tcase(suite, tests);
  return suite;
}
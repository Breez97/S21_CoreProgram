#include "tests.h"

// Проверка игровой статистики при инициализации
START_TEST(initialization_check_statuses) {
  GameInfo_t gameInfo = GameInfoInitialization();
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 0);
  ck_assert_int_eq(gameInfo.speed, 650);
  ck_assert_int_eq(gameInfo.pause, 0);
  FreeGameField(gameInfo.field);
  FreeNextFigure(gameInfo.next);
}
END_TEST

// Проверка создания игрового поля при запуске
START_TEST(initialization_check_field) {
  GameInfo_t gameInfo = GameInfoInitialization();
  int checkArray[22][22];
  for (int i = 0; i < 22; i++) {
    for (int j = 0; j < 22; j++) {
      checkArray[i][j] = 0;
    }
  }
  for (int i = 0; i < 22; i++) {
    for (int j = 0; j < 22; j++) {
      ck_assert_int_eq(gameInfo.field[i][j], checkArray[i][j]);
    }
  }
  FreeGameField(gameInfo.field);
  FreeNextFigure(gameInfo.next);
}
END_TEST

// Проверка создания поля для следующей фигуры
START_TEST(initialization_check_next) {
  GameInfo_t gameInfo = GameInfoInitialization();
  int checkArray[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      checkArray[i][j] = 0;
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(gameInfo.next[i][j], checkArray[i][j]);
    }
  }
  FreeGameField(gameInfo.field);
  FreeNextFigure(gameInfo.next);
}
END_TEST

// Проверка установки первоначального уровня игры
START_TEST(update_current_state_set_start_level) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  ck_assert_int_eq(gameInfo->level, 0);
  *gameInfo = updateCurrentState();
  ck_assert_int_eq(gameInfo->level, 1);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка изменения лучшего результата в случае, если он меньше текущего
// результата
START_TEST(update_current_state_high_score_changed) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  gameInfo->high_score = 400;
  gameInfo->score = 500;
  *gameInfo = updateCurrentState();
  ck_assert_int_eq(gameInfo->high_score, 500);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка изменения лучшего результата в случае, если он больше текущего
// результата
START_TEST(update_current_state_high_score_not_changed) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  gameInfo->high_score = 800;
  gameInfo->score = 500;
  *gameInfo = updateCurrentState();
  ck_assert_int_eq(gameInfo->high_score, 800);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка изменения уровня при наборе очков
START_TEST(update_current_state_level_1) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = 1; i <= 3; i++) {
    gameInfo->score += 600;
    *gameInfo = updateCurrentState();
  }
  ck_assert_int_eq(gameInfo->level, 4);
  ck_assert_int_eq(gameInfo->speed, 470);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка изменения уровня при наборе очков
START_TEST(update_current_state_level_2) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = 1; i <= 7; i++) {
    gameInfo->score += 600;
    *gameInfo = updateCurrentState();
  }
  ck_assert_int_eq(gameInfo->level, 8);
  ck_assert_int_eq(gameInfo->speed, 230);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка изменения уровня при наборе очков
START_TEST(update_current_state_level_3) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = 1; i <= 11; i++) {
    gameInfo->score += 600;
    *gameInfo = updateCurrentState();
  }
  ck_assert_int_eq(gameInfo->level, 10);
  ck_assert_int_eq(gameInfo->speed, 110);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка изменения статуса паузы
START_TEST(update_current_state_pause) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  *CurrentState() = GamePause;
  *gameInfo = updateCurrentState();
  ck_assert_int_eq(gameInfo->pause, 1);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка изменения статуса паузы
START_TEST(update_current_state_not_pause) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  *CurrentState() = Moving;
  *gameInfo = updateCurrentState();
  ck_assert_int_eq(gameInfo->pause, 0);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка на то, что файл с лучшими результатами не создается в случае, если
// лучший резлуьтат равен 0
START_TEST(update_current_state_game_over_1) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  *CurrentState() = GameOver;
  gameInfo->high_score = 0;
  *gameInfo = updateCurrentState();
  FILE *fileRead = fopen("./best.txt", "r");
  ck_assert_ptr_null(fileRead);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка на создание файла с лучшим результатом
START_TEST(update_current_state_game_over_2) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  *CurrentState() = GameOver;
  gameInfo->high_score = 400;
  *gameInfo = updateCurrentState();
  FILE *fileRead = fopen("./best.txt", "r");
  int highScoreInFile = 0;
  fscanf(fileRead, "%d", &highScoreInFile);
  fclose(fileRead);
  ck_assert_int_eq(highScoreInFile, 400);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка удаления линий
// Удаление одной линии
// Самая нижняя линия заполнена, остальные пустые
START_TEST(remove_lines_1) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    gameInfo->field[20][i] = 2;
  }
  gameInfo->score = 200;
  RemoveLines(gameInfo);
  ck_assert_int_eq(gameInfo->score, 300);
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    ck_assert_int_eq(gameInfo->field[20][i], 0);
  }
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка удаления линий
// Удаление одной линии
// Самая нижняя линия заполнена, предпоследняя частично заполнена, остальные
// пустые
START_TEST(remove_lines_2) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    gameInfo->field[20][i] = 2;
  }
  gameInfo->field[19][5] = 2;
  gameInfo->field[19][8] = 2;
  gameInfo->field[19][13] = 2;
  gameInfo->score = 600;
  RemoveLines(gameInfo);
  ck_assert_int_eq(gameInfo->score, 700);
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    ck_assert_int_eq(gameInfo->field[19][i], 0);
    if (i == 5 || i == 8 || i == 13) {
      ck_assert_int_eq(gameInfo->field[20][i], 2);
    } else {
      ck_assert_int_eq(gameInfo->field[20][i], 0);
    }
  }
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка удаления линий
// На последней линии не заполнена одна точка
START_TEST(remove_lines_3) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2 - 1; i++) {
    gameInfo->field[20][i] = 2;
  }
  gameInfo->score = 1000;
  RemoveLines(gameInfo);
  ck_assert_int_eq(gameInfo->score, 1000);
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2 - 1; i++) {
    ck_assert_int_eq(gameInfo->field[20][i], 2);
  }
  ck_assert_int_eq(gameInfo->field[20][10], 0);
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка удаления линий
// Последние две строки заполнены
// Перед ними строка пустая
START_TEST(remove_lines_4) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    gameInfo->field[20][i] = 2;
    gameInfo->field[19][i] = 2;
  }
  gameInfo->score = 500;
  RemoveLines(gameInfo);
  ck_assert_int_eq(gameInfo->score, 800);
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    ck_assert_int_eq(gameInfo->field[20][i], 0);
    ck_assert_int_eq(gameInfo->field[19][i], 0);
  }
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка удаления линий
// Последние две строки заполнены
// Перед ними строки частично заполнены
START_TEST(remove_lines_5) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    gameInfo->field[20][i] = 2;
    gameInfo->field[19][i] = 2;
  }
  gameInfo->field[18][4] = 2;
  gameInfo->field[17][4] = 2;
  gameInfo->field[18][7] = 2;
  gameInfo->field[18][9] = 2;
  gameInfo->score = 1200;
  RemoveLines(gameInfo);
  ck_assert_int_eq(gameInfo->score, 1500);
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    if (i == 4) {
      ck_assert_int_eq(gameInfo->field[20][i], 2);
      ck_assert_int_eq(gameInfo->field[19][i], 2);
    } else if (i == 7 || i == 9) {
      ck_assert_int_eq(gameInfo->field[20][i], 2);
    } else {
      ck_assert_int_eq(gameInfo->field[20][i], 0);
      ck_assert_int_eq(gameInfo->field[19][i], 0);
    }
  }
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка удаления линий
// Последние три строки заполнены
// Перед ними строки пустые
START_TEST(remove_lines_6) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    gameInfo->field[20][i] = 2;
    gameInfo->field[19][i] = 2;
    gameInfo->field[18][i] = 2;
  }
  gameInfo->score = 1500;
  RemoveLines(gameInfo);
  ck_assert_int_eq(gameInfo->score, 2200);
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    ck_assert_int_eq(gameInfo->field[20][i], 0);
    ck_assert_int_eq(gameInfo->field[19][i], 0);
    ck_assert_int_eq(gameInfo->field[18][i], 0);
  }
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка удаления линий
// Последние три строки заполнены
// Перед ними частично заполнена строка
START_TEST(remove_lines_7) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    gameInfo->field[20][i] = 2;
    gameInfo->field[19][i] = 2;
    gameInfo->field[18][i] = 2;
  }
  gameInfo->field[17][2] = 2;
  gameInfo->field[17][7] = 2;
  gameInfo->field[17][12] = 2;
  gameInfo->field[17][14] = 2;
  gameInfo->field[17][15] = 2;
  gameInfo->score = 1500;
  RemoveLines(gameInfo);
  ck_assert_int_eq(gameInfo->score, 2200);
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    if (i == 2 || i == 7 || i == 12 || i == 14 || i == 15) {
      ck_assert_int_eq(gameInfo->field[20][i], 2);
    } else {
      ck_assert_int_eq(gameInfo->field[20][i], 0);
      ck_assert_int_eq(gameInfo->field[19][i], 0);
      ck_assert_int_eq(gameInfo->field[18][i], 0);
    }
  }
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка удаления линий
// Последние четыре строки заполнены
// Перед ними пустые строки
START_TEST(remove_lines_8) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    gameInfo->field[20][i] = 2;
    gameInfo->field[19][i] = 2;
    gameInfo->field[18][i] = 2;
    gameInfo->field[17][i] = 2;
  }
  gameInfo->score = 300;
  RemoveLines(gameInfo);
  ck_assert_int_eq(gameInfo->score, 1800);
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    ck_assert_int_eq(gameInfo->field[20][i], 0);
    ck_assert_int_eq(gameInfo->field[19][i], 0);
    ck_assert_int_eq(gameInfo->field[18][i], 0);
    ck_assert_int_eq(gameInfo->field[17][i], 0);
  }
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка удаления линий
// Последние четыре строки заполнены
// Перед ними частично заполнена строка
START_TEST(remove_lines_9) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    gameInfo->field[20][i] = 2;
    gameInfo->field[19][i] = 2;
    gameInfo->field[18][i] = 2;
    gameInfo->field[17][i] = 2;
  }
  gameInfo->field[16][3] = 2;
  gameInfo->field[16][5] = 2;
  gameInfo->field[16][8] = 2;
  gameInfo->score = 500;
  RemoveLines(gameInfo);
  ck_assert_int_eq(gameInfo->score, 2000);
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    if (i == 3 || i == 5 || i == 8) {
      ck_assert_int_eq(gameInfo->field[20][i], 2);
    } else {
      ck_assert_int_eq(gameInfo->field[20][i], 0);
      ck_assert_int_eq(gameInfo->field[19][i], 0);
      ck_assert_int_eq(gameInfo->field[18][i], 0);
      ck_assert_int_eq(gameInfo->field[17][i], 0);
    }
  }
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

// Проверка удаления линий
// Последние четыре строки заполнены
// Перед ними частично заполнены строки
START_TEST(remove_lines_10) {
  GameInfo_t *gameInfo = CurrentGameInfo();
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    gameInfo->field[20][i] = 2;
    gameInfo->field[19][i] = 2;
    gameInfo->field[18][i] = 2;
    gameInfo->field[17][i] = 2;
  }
  gameInfo->field[16][3] = 2;
  gameInfo->field[16][5] = 2;
  gameInfo->field[16][8] = 2;
  gameInfo->field[15][3] = 2;
  gameInfo->field[15][8] = 2;
  gameInfo->score = 0;
  RemoveLines(gameInfo);
  ck_assert_int_eq(gameInfo->score, 1500);
  for (int i = FIELD_X_START + 1; i <= FIELD_X_END / 2; i++) {
    if (i == 5) {
      ck_assert_int_eq(gameInfo->field[20][i], 2);
    } else if (i == 3 || i == 8) {
      ck_assert_int_eq(gameInfo->field[20][i], 2);
      ck_assert_int_eq(gameInfo->field[19][i], 2);
    } else {
      ck_assert_int_eq(gameInfo->field[20][i], 0);
      ck_assert_int_eq(gameInfo->field[19][i], 0);
      ck_assert_int_eq(gameInfo->field[18][i], 0);
      ck_assert_int_eq(gameInfo->field[17][i], 0);
    }
  }
  FreeGameField(gameInfo->field);
  FreeNextFigure(gameInfo->next);
}
END_TEST

Suite *suite_backend(void) {
  Suite *suite = suite_create("backend_cases");
  TCase *tests = tcase_create("backend_tc");

  tcase_add_test(tests, initialization_check_statuses);
  tcase_add_test(tests, initialization_check_field);
  tcase_add_test(tests, initialization_check_next);
  tcase_add_test(tests, update_current_state_set_start_level);
  tcase_add_test(tests, update_current_state_high_score_changed);
  tcase_add_test(tests, update_current_state_high_score_not_changed);
  tcase_add_test(tests, update_current_state_level_1);
  tcase_add_test(tests, update_current_state_level_2);
  tcase_add_test(tests, update_current_state_level_3);
  tcase_add_test(tests, update_current_state_pause);
  tcase_add_test(tests, update_current_state_not_pause);
  tcase_add_test(tests, update_current_state_game_over_1);
  tcase_add_test(tests, update_current_state_game_over_2);
  tcase_add_test(tests, remove_lines_1);
  tcase_add_test(tests, remove_lines_2);
  tcase_add_test(tests, remove_lines_3);
  tcase_add_test(tests, remove_lines_4);
  tcase_add_test(tests, remove_lines_5);
  tcase_add_test(tests, remove_lines_6);
  tcase_add_test(tests, remove_lines_7);
  tcase_add_test(tests, remove_lines_8);
  tcase_add_test(tests, remove_lines_9);
  tcase_add_test(tests, remove_lines_10);

  suite_add_tcase(suite, tests);
  return suite;
}
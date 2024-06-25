#ifndef TESTS_H
#define TESTS_H

#include <check.h>

#include "../brick_game/tetris/tetris_backend.h"

void RunAllTests();

void RunTest(Suite *test);

Suite *suite_figures_creation();
Suite *suite_fsm();
Suite *suite_handlers();
Suite *suite_backend();

#endif

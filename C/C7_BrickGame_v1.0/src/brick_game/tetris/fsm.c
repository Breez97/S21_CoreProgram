/**
 * @file fsm.c
 * @brief Функции, отвечающие за взаимодействие с фигурами в игре.
 *
 * @ingroup FSM
 */

#include "tetris_backend.h"

/**
 * @ingroup FSM
 * @brief Функция, отвечающая за обработку пользовательского ввода.
 *
 * Данная функция в зависимости от текущего состояния игры и нажатой кнопки
 * игроком выполняет соответсвующее действие. В момент старта игры ждет от
 * пользователя ввод либо <Enter> для начала игры, либо <Esc> для выхода. В
 * момент падения фигур двигает их в зависимости от пользовательского ввода и
 * изменяет состояние игры на Attaching, в случае, если фигура достигла конца
 * игрового поля или столкнулась с другой, уже находящейся на поле фигурой. В
 * момент завершения игры ожидает от пользователя нажатия кнопки <Esc> для
 * выхода. В момент паузы игры ожидает нажатия <P> для возобновления игры, либо
 * <Esc> для завершения игры.
 *
 * @param input Пользовательский ввод.
 * @param tetBlock Указатель на текущую движущуюся фигуру.
 * @param gameInfo Указатель на текущее состояние игры.
 */
void ProcessUserAction(int input, TetBlock_t *tetBlock, GameInfo_t *gameInfo) {
  State_t *state = CurrentState();
  if (*state == GameStart) {
    if (input == BUTTON_ENTER) {
      userInput(Start, false);
    } else if (input == BUTTON_ESCAPE) {
      userInput(Terminate, false);
    }
  } else if (*state == Moving) {
    bool movingFigure = MovingFigure(input, tetBlock, gameInfo);
    if (movingFigure && CheckCollision(*tetBlock, *gameInfo)) {
      *CurrentState() = Attaching;
    }
  } else if (*state == GameOver && input == BUTTON_ESCAPE) {
    userInput(Terminate, false);
  } else if (*state == GamePause) {
    if (input == BUTTON_PAUSE) {
      userInput(Pause, false);
    } else if (input == BUTTON_ESCAPE) {
      userInput(Terminate, false);
    }
  }
}

/**
 * @ingroup FSM
 * @brief Функция, отвечающая за изменение состояний игры в зависимости от
 * пользовательского ввода.
 *
 * Данная функция изменяет состояние игры в зависимости от текущего состояния и
 * пользовательского действия. В случае, если совершено действие начала игры, то
 * состояние изменяется на спавн фигуры (Spawn). В случае, если совершено
 * действие завершения игры, меняет состояние на выход (Exit) или завершение
 * игры (GameOver) в зависимости от текущего статуса. В случае, если совершено
 * действие изменения положения фигуры, то состояние изменяется на движение
 * (Moving). В случае, если совершено действие постановки игры на паузу, то
 * изменяется текущее состояние на Moving , если игра уже стояла на паузе, либо
 * же на Pause, если игра не стояла на паузе.
 *
 * @param action Пользовательское действие.
 * @param hold Удержание клавиши
 */
void userInput(UserAction_t action, bool hold) {
  if (hold == false) {
    if (action == Start) {
      *CurrentState() = Spawn;
    } else if (action == Terminate) {
      if (*CurrentState() == GameOver || *CurrentState() == GameStart) {
        *CurrentState() = Exit;
      } else {
        *CurrentState() = GameOver;
      }
    } else if (action == Left || action == Right || action == Action) {
      *CurrentState() = Moving;
    } else if (action == Pause) {
      if (*CurrentState() == GamePause) {
        *CurrentState() = Moving;
      } else {
        *CurrentState() = GamePause;
      }
    }
  }
}

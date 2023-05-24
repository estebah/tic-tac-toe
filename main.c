#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"

char pos[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int player_turn = 1;
bool quit = true;

int board() {
  printf("     %sTIC TAC TOE\n%s", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
  printf("\n");
  printf("    %s%c%s  |  %s%c%s  |  %s%c%s\n",
         (pos[1] == 'X') ? ANSI_COLOR_RED : ((pos[1] == 'O') ? ANSI_COLOR_BLUE : ""),
         pos[1], ANSI_COLOR_RESET,
         (pos[2] == 'X') ? ANSI_COLOR_RED : ((pos[2] == 'O') ? ANSI_COLOR_BLUE : ""),
         pos[2], ANSI_COLOR_RESET,
         (pos[3] == 'X') ? ANSI_COLOR_RED : ((pos[3] == 'O') ? ANSI_COLOR_BLUE : ""),
         pos[3], ANSI_COLOR_RESET);
  printf("  -----------------\n");
  printf("    %s%c%s  |  %s%c%s  |  %s%c%s\n",
         (pos[4] == 'X') ? ANSI_COLOR_RED : ((pos[4] == 'O') ? ANSI_COLOR_BLUE : ""),
         pos[4], ANSI_COLOR_RESET,
         (pos[5] == 'X') ? ANSI_COLOR_RED : ((pos[5] == 'O') ? ANSI_COLOR_BLUE : ""),
         pos[5], ANSI_COLOR_RESET,
         (pos[6] == 'X') ? ANSI_COLOR_RED : ((pos[6] == 'O') ? ANSI_COLOR_BLUE : ""),
         pos[6], ANSI_COLOR_RESET);
  printf("  -----------------\n");
  printf("    %s%c%s  |  %s%c%s  |  %s%c%s\n",
         (pos[7] == 'X') ? ANSI_COLOR_RED : ((pos[7] == 'O') ? ANSI_COLOR_BLUE : ""),
         pos[7], ANSI_COLOR_RESET,
         (pos[8] == 'X') ? ANSI_COLOR_RED : ((pos[8] == 'O') ? ANSI_COLOR_BLUE : ""),
         pos[8], ANSI_COLOR_RESET,
         (pos[9] == 'X') ? ANSI_COLOR_RED : ((pos[9] == 'O') ? ANSI_COLOR_BLUE : ""),
         pos[9], ANSI_COLOR_RESET);
  printf("\n");
  return 0;
}

int check_board() {
  if (pos[1] == pos[2] && pos[2] == pos[3]) {
    return 1;
  }
  if (pos[4] == pos[5] && pos[5] == pos[6]) {
    return 1;
  }
  if (pos[6] == pos[7] && pos[7] == pos[8]) {
    return 1;
  }
  if (pos[1] == pos[4] && pos[4] == pos[7]) {
    return 1;
  }
  if (pos[2] == pos[5] && pos[5] == pos[8]) {
    return 1;
  }
  if (pos[3] == pos[6] && pos[6] == pos[9]) {
    return 1;
  }
  if (pos[1] == pos[5] && pos[5] == pos[9]) {
    return 1;
  }
  if (pos[3] == pos[5] && pos[5] == pos[7]) {
    return 1;
  }
  if (pos[1] != '1' && pos[2] != '2' && pos[3] != '3' && pos[4] != '4' &&
      pos[5] != '5' && pos[6] != '6' && pos[7] != '7' && pos[8] != '8' &&
      pos[9] != '9') {
    return 2;
  } else {
    return 0;
  }
}

int check_winner() {
  int winner;
  winner = check_board();
  if (winner == 1 && player_turn == 2) {
    printf("   %sWinner Player #1\n%s", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    printf("\n");
    quit = false;
  }
  if (winner == 1 && player_turn == 1) {
    printf("   %sWinner Player #1\n%s", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
    printf("\n");
    quit = false;
  }
  if (winner == 2) {
    printf("        Draw\n");
    printf("\n");
    quit = false;
  }
  return 0;
}

int play() {
  while (quit) {
    if (player_turn == 1) {
      printf("      Player #1:  \b");
    } else {
      printf("      Player #2:  \b");
    }

    char input[10];
    fgets(input, 10, stdin);
    int output;

    if (sscanf(input, "%d", &output) == 1) {
      if (output > 0 && output <= 9) {
        if (pos[output] != 'X' && pos[output] != 'O') {
          if (player_turn == 1) {
            pos[output] = 'X';
            player_turn = 2;
          } else {
            pos[output] = 'O';
            player_turn = 1;
          }
          system("clear");
          board();
          check_winner();
        } else {
          system("clear");
          board();
        }
      } else {
        system("clear");
        board();
      }
    } else {
      system("clear");
      board();
    }
  }
  return 0;
}

int main() {
  system("clear");
  board();
  play();
  return 0;
}

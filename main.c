#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char pos[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int player_turn = 1;
bool quit = true;

int board() {
  printf("     TIC TAC TOE\n");
  printf("\n");
  printf("    %c  |  %c  |  %c\n", pos[1], pos[2], pos[3]);
  printf("  -----------------\n");
  printf("    %c  |  %c  |  %c\n", pos[4], pos[5], pos[6]);
  printf("  -----------------\n");
  printf("    %c  |  %c  |  %c\n", pos[7], pos[8], pos[9]);
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
    printf("   Winner Player #1\n");
    printf("\n");
    quit = false;
  }
  if (winner == 1 && player_turn == 1) {
    printf("   Winner Player #2\n");
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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ROW 15
#define COL 15
#define BLACK 1
#define WHITE -1
#define BLANK 0

void chess_demo();

int main() {
    chess_demo();
    return 0;
}

void chess_demo() {
    int chess[ROW][COL] = {0};
    int loc_i = 0;
    int loc_j = 0;
    int player = BLACK;
    int winner = -1;
    do {
        system("clear");
        // 1
        printf("-----五子棋-----\n");
        for (int i = 0; i<COL; i++) {
            printf("%3d", i);
        }
        printf("\n");

        for (int i = 0; i<ROW; i++) {
            printf("%2d", i);
            printf("\033[47;34m");
            for (int j = 0; j<COL; j++) {
                if (chess[i][j] == BLANK) {
                    printf("%s", "|__");
                } else if (chess[i][j] == BLACK) {
                    printf("| X");
                } else {
                    printf("| O");
                }
            }
            printf("|\033[0m\n");
        }

        // 2
        for (int i = 0; i<ROW; i++) {
            for (int j = 0; j<COL; j++) {
                if (chess[i][j] == BLANK) {
                    continue;
                }
                // 横
                // 纵
                // 左斜
                // 又斜
                if (
                    (j < COL-4 && chess[i][j] == chess[i][j+1] && chess[i][j] == chess[i][j+2] && chess[i][j] == chess[i][j+3] && chess[i][j] == chess[i][j+4]) ||
                    (i < ROW-4 && chess[i][j] == chess[i+1][j] && chess[i][j] == chess[i+2][j] && chess[i][j] == chess[i+3][j] && chess[i][j] == chess[i+4][j]) ||
                    (i < ROW-4 && j > 4 && chess[i][j] == chess[i+1][j-1] && chess[i][j] == chess[i+2][j-2] && chess[i][j] == chess[i+3][j-3] && chess[i][j] == chess[i+4][j-4]) ||
                    (i < ROW-4 && j < COL-4 && chess[i][j] == chess[i+1][j+1] && chess[i][j] == chess[i+2][j+2] && chess[i][j] == chess[i+3][j+3] && chess[i][j] == chess[i+4][j+4])) {
                        winner = player;
                        goto L;
                }
            }
        }
        
        // 3
        printf("%d 号玩家请输入你的移动的地址:\n", player);
        scanf("%d %d", &loc_i, &loc_j);

        while (chess[loc_i][loc_j] != BLANK && loc_i < ROW && loc_j < COL) {
            printf("无效的位置!, 请再次输入:");
            scanf("%d %d", &loc_i, &loc_j);
        }

        chess[loc_i][loc_j] = player;
        player = player * -1;

    }while (loc_i != -1 && loc_j != -1);
    L: printf("%d 棋手赢!\n", winner);

}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define standardX 6
#define standardY 7

void welcome();
int options();
void createBoard();
void replayGame();
void display(char board[standardX][standardY]);
void init(char board[standardX][standardY]);
void insert(char board[standardX][standardY], int row, char player);
int check(char board[standardX][standardY]);
int checkHorizontal(char board[standardX][standardY]);
int checkVertical(char board[standardX][standardY]);
int checkDiagonal(char board[standardX][standardY]);

int main(void)
{
    welcome();
    int option = options();

    switch (option) {
    case 1:
        createBoard();
        break;
    case 2:
        replayGame();
        break;
    default:
        break;
    }

    return 0;
}

void welcome()
{
    printf("     ________   ________   ___  ___   ___  ___   ________   ________   _________ \n");
    printf("    /  _____/  / ____  /  /  | /  /  /  | /  /  /  _____/  /  _____/  /__    __/ \n");
    printf("   /  /       / /   / /  /   |/  /  /   |/  /  /  /____   /  /          /  / \n");
    printf("  /  /       / /   / /  /       /  /       /  /  _____/  /  /          /  / \n");
    printf(" /  /____   / /___/ /  /  /|   /  /  /|   /  /  /____   /  /____      /  / \n");
    printf("/_______/  /_______/  /__/ |__/  /__/ |__/  /_______/  /_______/     /__/ \n");
    printf("\n");
    printf("     ________   ________   ___   ___   ________ \n");
    printf("    /  _____/  / ____  /  /  /  /  /  /  __   / \n");
    printf("   /  /____   / /   / /  /  /  /  /  /  /_/__/ \n");
    printf("  /  _____/  / /   / /  /  /  /  /  /  /|  | \n");
    printf(" /  /       / /___/ /  /  /__/  /  /  / |  | \n");
    printf("/__/       /_______/  /________/  /__/  |__| \n");
    printf("\n");
    printf("By Andrew Clark (40345373)\n");
    printf("\n");
}

int options()
{
    int input = 0;
    char c;

    while (input < 1 || input > 3)
    {
        printf("Please select an option below \n");
        printf("1. Play \n");
        printf("2. Re-watch previous game \n");
        printf("3. Quit \n");
        scanf("%d", &input);
    }

    return input;
}

void createBoard()
{
    int input, result, wins = 0;
    char board[standardX][standardY];

    while (input < 1 || input > 3)
    {
        printf("Please select a board size \n");
        printf("1. Standard \n");
        printf("2. Custom (NOT YET DONE) \n");
        scanf("%d", &input);
    }

    switch (input) {
    case 1:
        init(board);
        display(board);
        break;
    default:
        break;
    }

    while ((input > 1 || input < 7) && wins == 0)
    {
        printf("Turn: Red \n");
        printf("Please select a row\n");
        scanf("%d", &input);
        insert(board, input - 1, 'R');
        display(board);
        result = check(board);
        if (result) {
            printf("Red wins\n");
            wins = 1;
        }

        if (wins != 1) {
            printf("Turn: Yellow \n");
            printf("Please select a row\n");
            scanf("%d", &input);
            insert(board, input - 1, 'Y');
            display(board);
            result = check(board);
            if (result) {
                printf("Yellow wins\n");
                wins = 1;
            }
        }
    }
}

void init(char board[standardX][standardY])
{
    int i, j;

    for (i = 0; i < standardX; ++i) {
        for (j = 0; j < standardY; ++j) {
            board[i][j] = 'O';
        }
    }
}

void display(char board[standardX][standardY])
{   
    int i, j;
    printf("\nConnect 4 \n");
    printf("\n  1   2   3   4   5   6   7 \n");
    printf("_____________________________ \n");
    for (i = 0; i < standardX; ++i) {
        for (j = 0; j < standardY; ++j) {
            printf("| %c ", board[i][j]);
        }
        printf("| \n");
    }
}

void insert(char board[standardX][standardY], int row, char player)
{
    int i, j;
    for (i = 0; i < standardX; i++) {
        if (board[i][row] == 'O' && board[i + 1][row] != 'O') {
            board[i][row] = player;
            continue;
        }
    }
}

int check(char board[standardX][standardY])
{
    return checkHorizontal(board) == 1 || checkVertical(board) == 1 || checkDiagonal(board) == 1;
}

int checkHorizontal(char board[standardX][standardY])
{
    int i, j;
    for (i = 0; i < standardX; i++) {
        for (j = 0; j < standardY; j++) {
            if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] != 'O') {
                printf("Horizontal\n");
                return 1;
            }
        }
    }

    return 0;
}

int checkVertical(char board[standardX][standardY])
{
    int i, j;
    for (i = 0; i < standardY; i++) {
        for (j = 0; j < standardX; j++) {
            if (board[j][i] == board[j + 1][i] && board[j][i] == board[j + 2][i] && board[j][i] == board[j + 3][i] && board[j][i] != 'O') {
                printf("Vertical\n");
                return 1;
            }
        }
    }

    return 0;
}

int checkDiagonal(char board[standardX][standardY])
{
    int i, j, count1, count2;
    for (i = 0; i < standardX; i++) {
        for (j = 0; j < standardY; j++) {
            if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] != 'O') {
                printf("Diagonal1\n");
                return 1;
            } else if (board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3] && board[i][j] != 'O') {
                printf("Diagonal2\n");
                return 1;
            }
        }
    }

    return 0;
}

void replayGame()
{
    printf("Replay Game \n");
}
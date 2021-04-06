#include <stdio.h>
#include <string.h>

#define standardX 6
#define standardY 7

void welcome();
int options();
void createBoard();
void replayGame();
void display(char board[standardX][standardY]);
void init(char board[standardX][standardY]);
void insert(char board[standardX][standardY], int row, char player);

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
    int input = 0;
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

    while (input > 1 || input < 7)
    {
        printf("Turn: Red \n");
        printf("Please select a row\n");
        scanf("%d", &input);
        insert(board, input - 1, 'R');
        display(board);

        printf("Turn: Yellow \n");
        printf("Please select a row\n");
        scanf("%d", &input);
        insert(board, input - 1, 'Y');
        display(board);
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

void replayGame()
{
    printf("Replay Game \n");
}
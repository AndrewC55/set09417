#include <stdio.h>

#define standardX = 7
#define standardY = 5

void welcome();
int options();
void createBoard(int *);
void replayGame();
void play(int *);

int main()
{
    welcome();
    int option = options();

    switch (option) {
    case 1:
        //int gameBoard[2] = createBoard();
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
    printf("    /  _____/  / ____  /  /  /  /  /  /       / \n");
    printf("   /  /____   / /   / /  /  /  /  /  /   4 __/ \n");
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
    int* returnAxis[2];

    while (input < 1 || input > 3)
    {
        printf("Please select a board size \n");
        printf("1. Standard \n");
        printf("2. Custom (NOT YET DONE) \n");
        scanf("%d", &input);
    }
}

void replayGame()
{
    printf("Replay Game \n");
}
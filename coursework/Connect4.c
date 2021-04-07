// include list of c standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// define length and breadth of standard sized connect 4 board
#define standardX 6
#define standardY 7

// prototypes of functions used
// welcome function prototype of type void
void welcome();
// options function prototype of type integer
int options();
// createBoard function prototype of type void
void createBoard();
// display function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
void display(char board[standardX][standardY]);
// init function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
void init(char board[standardX][standardY]);
// checkDiagonal function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
void play(char board[standardX][standardY]);
// insert function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant), row of type integer and player of type char
void insert(char board[standardX][standardY], int row, char player);
// check function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
bool check(char board[standardX][standardY]);
// checkHorizontal function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
bool checkHorizontal(char board[standardX][standardY]);
// checkVertical function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
bool checkVertical(char board[standardX][standardY]);
// checkDiagonal function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
bool checkDiagonal(char board[standardX][standardY]);
// validateInput function prototype of type int that takes in a singular char
int validateInput(char input, int max);

char* getPlayerName(bool player);
// replayGame function prototype of type void
void replayGame();

// main function of the programme which is used when the programme is run
int main(int argc, char* argv[]) {
    // call welcome function first
    welcome();
    // define integer option variable as the return value of the 'options' function
    int option = options();

    // switch statement for usage of the returned 'option' integer
    switch (option) {
    case 1:
        // if '1' is returned then 'createBoard' function is called
        createBoard();
        break;
    case 2:
        // if '2' is returned then 'replayGame' function is called
        replayGame();
        break;
    case 3:
        // if '3' is returned then game is exited via the c 'exit()' command
        exit(0);
        break;
    default:
        break;
    }

    return 0;
}

// welocme function is used to display connect 4 (non-functional at all and doesn't add much to the game)
void welcome() {
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

// options function used to return users input
int options() {
    // define option char as '0'
    char option;

    for (;;) {
        // Ask user what option they would like to select
        printf("Please select an option below \n");
        printf("1. Play \n");
        printf("2. Re-watch previous game \n");
        printf("3. Quit \n");
        // Take in user's option
        scanf("%c", &option);
        option = validateInput(option, 3);
        if (option != 0) {
            system("clear");
            break;
        } else {
            system("clear");
            continue;
        }
    }
    
    return option;
}

// createBoard function used to create the board based on size
void createBoard() {
    // define input and set it's value to '0'
    char option, board[standardX][standardY];

    for (;;) {
        // ask user what board size they would like to play with
        printf("Please select a board size \n");
        printf("1. Standard (7x6) \n");
        printf("2. Custom (NOT YET DONE) \n");
        scanf("%c", &option);
        option = validateInput(option, 2);
        if (option != 0) {
            system("clear");
            break;
        } else {
            system("clear");
            continue;
        }
    }

    // switch statement 
    switch (option) {
    case 1:
        init(board);
        display(board);
        play(board);
        break;
    default:
        break;
    }
}

// init function used to set all values of the 2 dimensional board array to 'O'
void init(char board[standardX][standardY]) {
    // define variables 'i' and 'j' as integers
    int i, j;

    // for loop through the the 'board' array
    for (i = 0; i < standardX; ++i) {
        for (j = 0; j < standardY; ++j) {
            // define every value in the array as 'O'
            board[i][j] = 'O';
        }
    }
}

// display function used to display the board based on size
void display(char board[standardX][standardY]) {
    // define variables 'i' and 'j' as integers
    int i, j;
    // clear the terminal so the it doesn't get too crowded and makes it easier on the eye
    system("clear");
    // printf Connect 4
    printf("\nConnect 4 \n");
    // printf column numbers
    printf("\n  1   2   3   4   5   6   7 \n");
    // pritnf top of game board
    printf("_____________________________ \n");
    // for loop through the 'board' array and display each value with a '|' to make create the board
    for (i = 0; i < standardX; ++i) {
        for (j = 0; j < standardY; ++j) {
            // printf array value as a char
            printf("| %c ", board[i][j]);
        }
        // printf final '|' and create new line
        printf("| \n");
    }
}

void play(char board[standardX][standardY]) {
    // define input, result and wins variables as integers and set values to '0'
    bool player = true, result = false;
    char* playerName;
    char move;
    playerName = malloc(sizeof(char) * 7);

    for (;;) {
        // comment
        playerName = getPlayerName(player);
        // Red will go first
        printf("Turn: %s \n", playerName);
        // ask user to select a row
        printf("Please select a row\n");
        // scanf user's input
        scanf("%c", &move);
        move = validateInput(move, 7);
        if (move != 0) {
            // call insert function to assign users inputted to a space in the 'board' array
            insert(board, move - 1, playerName[0]);
            // call display function to display updated board
            display(board);
            // call check function to see if user has won
            result = check(board);
            // if result is true then user has won
            if (result) {
                printf("%s wins\n", playerName);
                break;
            }
        } else {
            display(board);
            continue;
        }
        
        player = !player;
    }
}

void insert(char board[standardX][standardY], int row, char player) {
    for (int i = 0; i < standardX; i++) {
        if (board[i][row] == 'O' && board[i + 1][row] != 'O') {
            board[i][row] = player;
            continue;
        }
    }
}

bool check(char board[standardX][standardY]) {
    return checkHorizontal(board) || checkVertical(board) || checkDiagonal(board);
}

bool checkHorizontal(char board[standardX][standardY]) {
    int i, j;
    for (i = 0; i < standardX; i++) {
        for (j = 0; j < standardY; j++) {
            if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] != 'O') {
                return true;
            }
        }
    }

    return false;
}

bool checkVertical(char board[standardX][standardY]) {
    int i, j;
    for (i = 0; i < standardY; i++) {
        for (j = 0; j < standardX; j++) {
            if (board[j][i] == board[j + 1][i] && board[j][i] == board[j + 2][i] && board[j][i] == board[j + 3][i] && board[j][i] != 'O') {
                return true;
            }
        }
    }

    return false;
}

bool checkDiagonal(char board[standardX][standardY]) {
    int i, j, count1, count2;
    for (i = 0; i < standardX; i++) {
        for (j = 0; j < standardY; j++) {
            if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] != 'O') {
                return true;
            } else if (board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3] && board[i][j] != 'O') {
                return true;
            }
        }
    }

    return false;
}

int validateInput(char input, int max) {
    if (isdigit(input)) {
        input = (int)input - 48;
        if (input >= 1 && input <= max) {
            return input;
        }
    }

    return 0;
}

char* getPlayerName(bool player) {
    static char red[4] = "Red";
    static char yellow[7] = "Yellow";
    if (player) {
        return yellow;
    }

    return red;
}

void replayGame() {
    printf("Replay Game \n");
}
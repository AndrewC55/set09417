// include list of c standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

// maximum supported board size for length and breadth
#define MAX_BOARD_SIZE 9
// size of spaces on max board size
#define STACK_SIZE 81

// define length and breadth of standard sized connect 4 board
int standardX = 7, standardY = 6;

// struct for the stack to be used in the undo and redo feature
struct stack
{
    // integer array for storing the rows that the user has inputted of size 81 (size of maximum supported board size)
    int array[STACK_SIZE];
    // integer variable value top indicates the latest element added to the array
    int top;
};

// struct node for the linked list
struct node
{
    // char variables for player ('Y' or 'R') and move ('P' = 'Play', 'U' = 'Undo' or 'R' = 'Redo')
    char player, move;
    // integer variable row logs the row the user has chosen to drop their token into
    int row;
    // link to the next node in the linked list
    struct node * link;
};

// prototypes of functions used
// runGame function of type void
void runGame();
// welcome function prototype of type void
void welcome();
// options function prototype of type integer
int options();
// createBoard function prototype of type void
void createBoard();
// display function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
void display(char board[standardY][standardX]);
// init function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
void initArray(char board[standardY][standardX]);
// checkDiagonal function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
void play(char board[standardY][standardX]);
// insert function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant), row of type integer and player of type char
bool insert(char board[standardY][standardX], int row, char player);
// desert function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant), row of type integer and player of type char
bool desert(char board[standardY][standardX], int row, char player);
// check function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
bool check(char board[standardY][standardX]);
// checkHorizontal function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
bool checkHorizontal(char board[standardY][standardX]);
// checkVertical function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
bool checkVertical(char board[standardY][standardX]);
// checkDiagonal function prototype of type void that takes in a 2d char array of size 6 (standardX constant) x 7 (standardY constant)
bool checkDiagonal(char board[standardY][standardX]);
// validateInput function prototype of type int that takes in a singular char
int validateInput(char input, int max);
// getPlayerName function of type char*
char* getPlayerName(bool player);
// defineX of type int
int defineX();
// defineY of type int
int defineY();
// replay function of type void
void replayGame();
// initStack function of type void that takes in a struct stack *
void initStack(struct stack * s);
// push function of type void that takes in a struct stack * and item of type integer
void push(struct stack *s, int item);
// pop function of type int * that takes in a struct stack *
int *pop(struct stack *s);
// append function of type void that takes in a struct node **, row of type int, player of type char and move of type char
void append(struct node ** list, int row, char player, char move);
// saveGame function of type void takes in struct node ** 
void saveGame(struct node ** list);
// replayGame function of type void
void replayDelay();

// main function of the programme which is used when the programme is run
int main(int argc, char* argv[]) {
    // calls runGame function to start the game
    runGame();
    return 0;
}

void runGame() {
    // call welcome function first
    welcome();
    // define integer option variable as the return value of the 'options' function
    int option = options();

    // switch statement for usage of the returned 'option' integer
    switch (option) {
    case 1:
        // if '1' is returned then createBoard function is called
        createBoard();
        break;
    case 2:
        // if '2' is returned then replayGame function is called
        replayGame();
        break;
    case 3:
        // if '3' is returned then game is exited via the c exit command
        exit(0);
        break;
    default:
        break;
    }
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
    // define option char
    char option;

    for (;;) {
        // Ask user what option they would like to select
        printf("Please select an option below\n");
        printf("1. Play\n");
        printf("2. Re-watch previous game\n");
        printf("3. Quit\n");
        printf("Please select an option: ");
        // Take in user's option
        scanf(" %c", &option);
        // Validate that user's input is in range (1-3)
        option = validateInput(option, 3);
        // if option isn't valid 0 will be returned
        if (option != 0) {
            // clear terminal so it doesn't get too cluttered
            system("clear");
            // break loop
            break;
        } else {
            // clear terminal so it doesn't get too cluttered
            system("clear");
            // if inputted option isn't inputted then error message is displayed
            printf("Please select an option between 1 and 3\n");
            // continue to loop
            continue;
        }
    }
    
    // return value of option once the loop is broken
    return option;
}

// createBoard function used to create the board based on size
void createBoard() {
    // define variable option as char
    char option;

    for (;;) {
        // ask user what board size they would like to play with
        printf("What board size would you like?\n");
        printf("1. Standard (7x6)\n");
        printf("2. Custom (up to 9x9)\n");
        printf("Please select a board size: ");
        // scan in user's input
        scanf(" %c", &option);
        // validate option again
        option = validateInput(option, 2);
        // if user wants standard sized board the loop is broken
        if (option == 1) {
            system("clear");
            standardX = 7;
            standardY = 6;
            break;
            // if user wants custom sized board defineX and defineY are called
        } else if (option == 2) {
            system("clear");
            standardX = defineX();
            standardY = defineY();
            break;
        } else {
            // if inputted option isn't inputted then error message is displayed
            system("clear");
            printf("Please select an option between 1 and 2\n");
            continue;
        }
    }
    
    // define char array to be used for the board and set it to defined sizes
    char board[standardY][standardX];
    // call initArray to set all values to 'O' (empty space)
    initArray(board);
    // display board for user
    display(board);
    // game begins
    play(board);
}

// init function used to set all values of the 2 dimensional board array to 'O'
void initArray(char board[standardY][standardX]) {
    // define variables 'i' and 'j' as integers
    int i, j;

    // for loop through the the 'board' array
    for (i = 0; i < standardY; ++i) {
        for (j = 0; j < standardX; ++j) {
            // define every value in the array as 'O'
            board[i][j] = 'O';
        }
    }
}

// display function used to display the board based on size
void display(char board[standardY][standardX]) {
    // define variables 'i' and 'j' as integers
    int i, j;
    // clear terminal so it doesn't get too cluttered
    system("clear");
    printf("\nConnect 4 \n\n");

    // for loop to loop as many times
    for(i = 0; i < standardX; ++i) {
        if (i + 1 > 9) {
            printf("  %d", i + 1);
        } else {
            printf("  %d ", i + 1);
        }
    }
    printf("\n");
    for(i = 0; i < standardX; ++i) {
        printf("____");
    }
    printf("_\n");
    // for loop through the 'board' array and display each value with a '|' to make create the board
    for (i = 0; i < standardY; ++i) {
        for (j = 0; j < standardX; ++j) {
            // printf array value as a char
            printf("| %c ", board[i][j]);
        }
        // printf final '|' and create new line
        printf("| \n");
    }
}

// play function where most of the game functionality is carried out
void play(char board[standardY][standardX]) {
    // define stack structs 2 for each player (one for logging all moves for undo and one for logging all undos for redo)
    struct stack yellowPlay, redPlay, yellowUndo, redUndo;
    // define a linked list stuct and set it's value to NULL
    struct node * list = NULL;
    // init all stacks by setting the 'top' value to -1
    initStack(&yellowPlay);
    initStack(&redPlay);
    initStack(&yellowUndo);
    initStack(&redUndo);
    // define boolean variables for player (deterines who's turn it is) set to true and result (used to check if a winner is declared) set to false
    bool player = true, result = false;
    // integer variable for row (user selected row on the board) set to 0
    int row = 0, *temp = NULL;
    // char * variable playerName used to display user's name and insert token (Yellow or Red)
    char* playerName;
    // set size of playerName to 7 so it can account for both Yellow and Red
    playerName = malloc(sizeof(char) * 7);
    // char variables input (for row selection), move (for play, undo and redo) and option (selecting move)
    char input, move, option;

    // infinite loop to be broken as game could continue forever if undo and redo is constantly used
    for (;;) {
        // define playerName variable as return value from getPlayerName based on if player is truthy or falsey
        playerName = getPlayerName(player);

        // tells user's who's turn it is and asks them to play, undo previous move or redo previously undone move
        printf("Turn: %s \n", playerName);
        printf("1. Play\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("Please select an option: ");
        // scan in user's option
        scanf(" %c", &option);

        // validate user's option
        option = validateInput(option, 3);
        // if option is valid
        if (option != 0) {
            // if option is play or redo
            if (option != 2) {
                // if option is play
                if (option == 1) {
                    // ask user to select a row
                    printf("Please select a row: ");
                    // scanf user's input
                    scanf(" %c", &input);
                    // validate user's input
                    row = validateInput(input, standardX);
                    // define move as 'P' (play)
                    move = 'P';
                } else {
                    // if player = true (yellow)
                    if (player) {
                        // pop latest value from the undo yellow stack
                        temp = pop(&yellowUndo);
                    } else {
                        // pop latest value from the undo red stack
                        temp = pop(&redUndo);
                    }
                    // if a value is returned
                    if (temp) {
                        // define row as *temp
                        row = *temp;
                    } else {
                        // if temp isn't valid display board with error message
                        display(board);
                        printf("Cannot redo move\n");
                        continue;
                    }
                    // define move as 'R' (redo)
                    move = 'R';
                }
                
                // if row is valid
                if (row != 0) {
                    // call insert function to assign users inputted to a space in the 'board' array along with first char of playerName ('Y' or 'R') for token
                    if (insert(board, row - 1, playerName[0])) {
                        // if player = true (yellow)
                        if (player) {
                            // push to play stack for yellow
                            push(&yellowPlay, row);
                        } else {
                            // push to play stack for red
                            push(&redPlay, row);
                        }
                        // append to linked list to log move
                        append(&list, row, playerName[0], move);
                        // call display function to display updated board
                        display(board);
                        // call check function to see if user has won
                        result = check(board);
                        // if result is true then user has won
                        if (result) {
                            // tell user's a player has won and break the loop
                            printf("%s wins\n", playerName);
                            break;
                        }
                        
                        // if game is not won player is switched
                        player = !player;
                    } else {
                        // if insertion has failed it means row is full and cannot be selected
                        display(board);
                        printf("Row is full, please select another\n");
                    }
                } else {
                    // if row is not valid error message is displayed and loop is restarted
                    display(board);
                    printf("Please select a row between 1 and %d \n", standardX);
                    continue;
                }        
            // if user selects undo previous mobe
            } else if (option == 2) {
                // if player = true (yellow)
                if (player) {
                    // pop latest item from the play stack for yellow
                    temp = pop(&yellowPlay);
                    // if popped item is valid
                    if (temp) {
                        // define row as popped value
                        row = *temp;
                        // push row to undo stack for yellow
                        push(&yellowUndo, row);
                    }
                } else {
                    // pop latest item from the play stack for red
                    temp = pop(&redPlay);
                    // if popped item is valid
                    if (temp) {
                        // define row as popped value
                        row = *temp;
                        // push row to undo stack for red
                        push(&redUndo, row);
                    }
                }
                // define move as 'U' (undo)
                move = 'U';
                // desert the value from the board (set latest token back to 'O')
                if (desert(board, row - 1, playerName[0])) {
                    // append to linked list to log move
                    append(&list, row, playerName[0], move);
                    // displat board again
                    display(board);
                    // check if user has won by cause of undo
                    result = check(board);
                    // if result is true then user has won
                    if (result) {
                        // tell user's a player has won and break the loop
                        printf("%s wins\n", playerName);
                        break;
                    }

                    // switch player
                    player = !player;
                } else {
                    // if desertion has failed (user has no more undo's) board is displayed with error message
                    display(board);
                    printf("Cannot undo move \n");
                }
            }
        } else {
            // if user selects an option that doesn't exist then board is displayed with error message
            display(board);
            printf("Please select an option between 1 and 3 \n");
            continue;
        }
    }
    
    // infinite loop for saving a game once user has been declared winner
    for (;;) {
        // ask user to save game
        printf("Save game?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Save: ");
        // scan in user's option
        scanf(" %c", &input);
        // validate input
        input = validateInput(input, 2);
        // if input is valid
        if (input != 0) {
            // if user chooses to save game then saveGame function is called
            if (input == 1) {
                saveGame(&list);
                break;
            }
            // if not then game is not saved and loop is broken
            break;
        } else {
            continue;
        }
    }

    // game goes back to the start
    runGame();
}

// insertion function for board array
bool insert(char board[standardY][standardX], int row, char player) {
    // for loop for height of the board
    for (int i = 0; i < standardY; i++) {
        // if space in row is blank AND space below is not blank then 
        if (board[i][row] == 'O' && board[i + 1][row] != 'O') {
            // define space in array (board) by user's token
            board[i][row] = player;
            // break loop by returning true value to indicate successful insertion
            return true;
        } else if (i == standardY - 1) {
            // if 'i' reaches the top of the row then row is full and insertion has failed
            return false;
        }
    }

    return false;
}

// desertion for board array for undoing a previous move
bool desert(char board[standardY][standardX], int row, char player) {
    // for loop for height of the board
    for (int i = 0; i < standardY; i++) {
        // if char in the space is the user in questions token
        if (board[i][row] == player) {
            // set space in array back to 'O' and break the loop
            board[i][row] = 'O';
            break;
        } else if (i == standardY - 1) {
            // if 'i' reaches the top of the row then row is empty and desertion has failed
            return false;
        }
    }

    // for loop to push all other tokens above the removed one down (as to simulate the token falling if a token magically dissapears)
    for (int j = 0; j < standardY; j++) {
        // if space is blank and space above is not blank
        if (board[j][row] == 'O' && (board[j - 1][row] == 'Y' || board[j - 1][row] == 'R')) {
            // set space to space above's value
            board[j][row] = board[j - 1][row];
            // set space above to blank
            board[j - 1][row] = 'O';
            // continue until all necessary tokens have fallen
        }
    }

    // if token has been removed and all tokens have been moved down then desertion was succesful
    return true;
}

// check function returns if a win has occurred
bool check(char board[standardY][standardX]) {
    // return true value from checkHorizontal, checkVertical or checkDiagonal functions
    return checkHorizontal(board) || checkVertical(board) || checkDiagonal(board);
}

// checkHorizontal function returns if a win has occurred horizontally
bool checkHorizontal(char board[standardY][standardX]) {
    int i, j;
    // for loop for the height of the board first
    for (i = 0; i < standardY; i++) {
        // then for loop through the length of the board
        for (j = 0; j < standardX; j++) {
            // if the token is the same for 4 spaces in a row horizontally then true is returned
            if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] != 'O') {
                return true;
            }
        }
    }

    // if full board has been looped through without a win then return false
    return false;
}

// checkVertical function returns if a win has occurred vertically
bool checkVertical(char board[standardY][standardX]) {
    int i, j;
    // for loop for the length of the board first
    for (i = 0; i < standardX; i++) {
        // then for loop through the height of the board
        for (j = 0; j < standardY; j++) {
            // if the token is the same for 4 spaces in a row vertically then true is returned
            if (board[j][i] == board[j + 1][i] && board[j][i] == board[j + 2][i] && board[j][i] == board[j + 3][i] && board[j][i] != 'O') {
                return true;
            }
        }
    }

    // if full board has been looped through without a win then return false
    return false;
}

// checkDiagonal function returns if a win has occurred diagonally
bool checkDiagonal(char board[standardY][standardX]) {
    int i, j;
    // for loop for the height of the board first
    for (i = 0; i < standardY; i++) {
        // then for loop through the length of the board
        for (j = 0; j < standardX; j++) {
            if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] != 'O') {
                // if the token is the same for 4 spaces in a row diagonally left to right then true is returned
                return true;
            } else if (board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3] && board[i][j] != 'O') {
                // if the token is the same for 4 spaces in a row diagonally right to left then true is returned
                return true;
            }
        }
    }

    // if full board has been looped through without a win then return false
    return false;
}

// validateInput will return an integer value by converting a char inputted by the user to an integer in a range
int validateInput(char input, int max) {
    // if char entered is digit then continue
    if (isdigit(input)) {
        // char to integer conversion isn't the best as when casting a char to an int it will add 48 so 48 must be subtracted when casting
        input = (int)input - 48;
        // if input is more than or equal 1 but not more than or equal to the max (in range e.g. 1 to 3) then casted integer is returned
        if (input >= 1 && input <= max) {
            return input;
        }
    }

    // if char is not digit or not in range then 0 is returned
    return 0;
}

// getPlayerName returns the pointer of the static (will keeps it's value inside memory each time it is called) name of the player
char* getPlayerName(bool player) {
    // declare static char for yellow player
    static char yellow[7] = "Yellow";
    // declare static char for red player
    static char red[4] = "Red";
    // if player is true (yellow) return yellow
    if (player) {
        return yellow;
    }

    // if player is false (red) return red
    return red;
}

// defineX function is used for asking the user to input the length of a custom sized board
int defineX() {
    char length;
    int boardLength;
    for (;;) {
        // ask the user to input length
        printf("Please enter length of the board (number of rows across): ");
        // scanf user's input
        scanf(" %c", &length);
        // validate input and assign it to boardLength
        boardLength = validateInput(length, MAX_BOARD_SIZE);
        // if boardLength is valid break loop
        if (boardLength != 0) {
            break;
        } else {
            system("clear");
            printf("Please select a number between 1 and %d\n", MAX_BOARD_SIZE);
        }
    }

    // return boardLength
    return boardLength;
}

// defineY function is used for asking the user to input the height of a custom sized board
int defineY() {
    char height;
    int boardHeight;
    for (;;) {
        // ask the user to input height
        printf("Please enter height of the board (number of rows upwards): ");
        // scanf user's input
        scanf(" %c", &height);
        // validate input and assign it to boardHeight
        boardHeight = validateInput(height, MAX_BOARD_SIZE);
        // if boardHeight is valid break loop
        if (boardHeight != 0) {
            break;
        } else {
            system("clear");
            printf("Please select a number between 1 and %d\n", MAX_BOARD_SIZE);
        }
    }

    // return boardHeight
    return boardHeight;
}

void replayGame() {
    // define variables to be used
    int gameCount = 1, gameSelect = 1, gameNumber, row;
    char line[256], input, player, move;
    char* playerName;
    char* playerMove;
    playerName = malloc(sizeof(char) * 7);
    playerMove = malloc(sizeof(char) * 7);
    FILE *file;
    bool result;

    // list available tgames to user
    printf("Available games to be replayed:\n");
    // open gamelog file for reading
    file = fopen("games/gamelog.txt", "r");
    // if file exists
    if (file) {
        // while file's line is not blank
        while (fgets(line, sizeof(line), file)) {
            // if line contains "GAME" string
            if (strstr(line, "GAME") != NULL) {
                // increment gameCount
                gameCount++;
                // print GAME number and board size
                printf("%s", line);
            }
        }
    }
    // close file as file has been looped through and is at the end
    fclose(file);

    // infinite for loop
    for (;;) {
        // ask user to input game to replay
        printf("Please select a game you to replay: ");
        // scan user's input in
        scanf(" %c", &input);
        // validate user's input
        gameNumber = validateInput(input, gameCount);
        // if gameNumber is valid break infinite loop and continue through the function
        if (gameNumber != 0) {
            break;
        }
    }

    // reopen gamelog file
    file = fopen("games/gamelog.txt", "r");
    // while file's line is not blank
    while (fgets(line, sizeof(line), file)) {
        // if line contains "GAME"
        if (strstr(line, "GAME") != NULL) {
            // if incremented gameSelect is equal to user's input
            if (gameSelect == gameNumber) {
                standardY = validateInput(line[9], MAX_BOARD_SIZE);
                standardX = validateInput(line[7], MAX_BOARD_SIZE);
                // define board size
                char board[standardY][standardX];
                // init array by setting all spaces to 'O'
                initArray(board);
                // while file's line is not blank (start reading game)
                while (fgets(line, sizeof(line), file)) {
                    // if line doesn't contain "END" (end of game)
                    if (strstr(line, "END") == NULL) {
                        // define player
                        player = line[8];
                        // define move
                        move = line[17];
                        // validate row
                        row = validateInput(line[25], standardX);
                        // define playerName
                        playerName = player == 'Y' ? "Yellow" : "Red";
                        // if move is a play or redo
                        if (move == 'P' || move == 'R') {
                            // insert into board array
                            insert(board, row - 1, player);
                            playerMove = move == 'P' ? "played" : "redone";
                        } else {
                            // if move is undo
                            // desert from board array
                            desert(board, row - 1, player);
                            playerMove = "undone";
                        }
                        // display board
                        display(board);
                        // tell user's what move has been made by what player
                        printf("%s %s row %d\n", playerName, playerMove, row);

                        // check if someone has won
                        result = check(board);
                        // if result is true then user has won
                        if (result) {
                            // display winner and break the loop
                            printf("%s wins\n", playerName);
                            replayDelay();
                            break;
                        }
                        
                        // delay for a few seconds so that the user's can see what moves have been made
                        replayDelay();
                    } else {
                        // if line conatins "END" that means that the game is over but no winner has been declared
                        break;
                    }
                }
                // break loop
                break;
            } else {
                // increment gameSelect until it matches the user's input
                gameSelect++;
            }
        }
    }

    // close file
    fclose(file);
    // take user's back to the start
    runGame();
}

// initStack is used for initialising stacks by setting the tops to -1
void initStack(struct stack *s)
{
    s->top = -1;
}

// push is used for pushing integer values to a stack
void push(struct stack *s, int item)
{
    // increment top of stack
    s->top++;
    // assing item to the top of the stack
    s->array[s->top] = item;
}

// pop function is
int *pop(struct stack *s)
{
    // create integer pointer
    int *data;
    // if stack is empty return NULL
    if (s->top == -1) {
        return NULL;
    }

    // if stack is not empty take the top (latest item added) item
    data = &s->array[s->top];
    // decrement the top as previous top item doesn't exist in the stack anymore
    s->top--;
    // return popped item
    return data;
}

// append function is used to append row, move and player to a linked list so to be used later when saving current game
void append(struct node **list, int row, char player, char move)
{
    // create two temporary nodes to protect list and link properly
    struct node *temp1, *temp2;
    // if list is NULL (new)
    if (*list == NULL) {
        // define first temporary node as size of list
        temp1 = (struct node *)malloc(sizeof(struct node));
        // assign values to temporary node
        temp1->player = player;
        temp1->move = move;
        temp1->row = row;
        // next node doesn't exist as list is new so it is NULL
        temp1->link = NULL;
        // assign list as temporary node
        *list = temp1;
    } else {
        // temporary node is defines as list
        temp1 = *list;
        // while temporary node (list) doesn't have a next node define temporary node as next node
        while (temp1->link != NULL) {
            temp1 = temp1->link;
        }
        // define second temporary node as size of list
        temp2 = (struct node *)malloc(sizeof(struct node));
        // assign values to temporary node
        temp2->player = player;
        temp2->move = move;
        temp2->row = row;
        // next node doesn't exist as current node is last in the list so it is NULL
        temp2->link = NULL;
        // assign latest node as secondary temporary node
        temp1->link = temp2;
    }
}

void saveGame(struct node ** list)
{
    // integer variable gameNumber set to 1 in case it's first time saving game
    int gameNumber = 1;
    // char variable line set to 256 as that is the amount of characters that a typical file will hold per line
    char line[256];
    // FILE variable file is a pointer to the location of desired file
    FILE *file;

    // open gamelog file for reading purposes
    file = fopen("games/gamelog.txt", "r");
    // if file exists
    if (file) {
        // while loop that will run as long as the file has contents
        while (fgets(line, sizeof(line), file)) {
            // if line contains "GAME" then gameNumber is incremented
            if (strstr(line, "GAME") != NULL) {
                gameNumber++;
            }
        }
    }
    // close file as it is read only
    fclose(file);
    // reopen file but this time to append data to it
    file = fopen("games/gamelog.txt", "a");
    // create a new node for iterating through the list
    struct node * iterator = *list;
    // append game number and board size to file
    fprintf(file, "GAME %d %dx%d\n", gameNumber, standardX, standardY);
    // while list is not null
    while (iterator != NULL) {
        // append player, move and row to file
        fprintf(file, "Player: %c, Move: %c, Row: %d\n", iterator->player, iterator->move, iterator->row);
        // go to next node in list
        iterator = iterator->link;
    }

    // append "END" to signal end of game
    fprintf(file, "END\n");
    // close file
    fclose(file);
}

// replayDelay function is just 2 for loops that will run to cause a temporary delay
void replayDelay()
{
    int i, j;
    for (i = 0; i < 40000; i++) {
        for (j = 0; j < 60000; j++) {}
    }
}
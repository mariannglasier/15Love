#include "game.h"
#include "gba.h"

//function headers
extern inline unsigned char colorAt();

// colorAt function
extern inline unsigned char colorAt(int x, int y) {
    return ((unsigned char*) tennis_placeholder_collisionBitmap) [OFFSET(x, y, TENNISMAPWIDTH)];
}

// state switch functions
//start menu
void start() {
    waitForVBlank();
    updateStart();

    //go to game if start is pressed
    if (BUTTON_PRESSED(BUTTON_START)) {
        goToCourt();
    }

    // go to instructions if select is pressed
    if (BUTTON_PRESSED(BUTTON_SELECT)) {
        goToInstructions();
    }
}

void goToStart() {
    drawStart();
    state = START;
}

//instructions page
void instructions() {
    waitForVBlank();

    //go to game if start is pressed
    if (BUTTON_PRESSED(BUTTON_START)) {
        goToCourt();
    }

    //go back to start if select is pressed
    if (BUTTON_PRESSED(BUTTON_SELECT)) {
        goToStart();
    }
}

void goToInstructions() {
    drawInstructions();
    state = INSTRUCTIONS;
}

//court map
void court(){
    waitForVBlank();
    updateCourt();
    drawCourt();

    //go to instructions if select is pressed
    if (BUTTON_PRESSED(BUTTON_SELECT)) {
        goToInstructions();
    }

    //player will need to talk to characters to play tennis
    //press A near a character, talk, and then enter a game

    //go to pause screen if start is pressed
    if (BUTTON_PRESSED(BUTTON_START)) {
        goToPause();
    }
}

void goToCourt(){
    waitForVBlank();

    //draw stuff and bg

    state = COURT;
    initCourt();
}

//tennis match
void tennisGame() {
    waitForVBlank();
    updateTennisGame();
    drawTennisGame();

    // go to pause if start is pressed
    if (BUTTON_PRESSED(BUTTON_START)) {
        goToPause();
    }

    //player wins (learn tennis scoring lol)

    //player loses
}

void goToTennisGame() {
    waitForVBlank();

    //bg stuff

    hideSprites();

    state = TENNISGAME;
    initTennisGame();
}

//pause screen
void pause() {
    waitForVBlank();

    //go to start / reset game
    if (BUTTON_PRESSED(BUTTON_SELECT)) {
        goToStart();
    }

    //go back to game
    //depends on previous state
    //tennis game or court?
}

void goToPause() {
    waitForVBlank();
    drawPause();
}

//win screen
void win() {
    waitForVBlank();

    //restart game if start pressed
    if (BUTTON_PRESSED(BUTTON_START)) {
        goToStart();
    }
}

void goToWin() {
    waitForVBlank();
    drawWin();
}

//lose screen
void lose() {
    waitForVBlank();

    //restart game if start pressed
    if (BUTTON_PRESSED(BUTTON_START)) {
        goToStart();
    }
}

void goToLose() {
    waitForVBlank();
    drawLose();
}

//initalize functions

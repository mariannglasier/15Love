#ifndef GAME_H
#define GAME_H

//state enum
enum {
    START,
    INSTRUCTIONS,
    COURT,
    TENNISGAME,
    PAUS,
    WIN,
    LOSE
};
extern int state;

typedef enum{DOWN, UP, LEFT, RIGHT} DIRECTION;

inline unsigned char colorAt(int x, int y);


#endif
/*
 Robotics Programming Maze Race
 Zheng Onn Ng's solo work 45
 24th March 2017
*/

#include "simpletools.h"
#include "abdrive.h"
#include "ping.h"
#include <stdbool.h>

//***IMPORTANT INFO***
/*  X-Y Coordinates                                                    Priority Table (Left-Hand Rule)
                                | 5,5                                  +--------+-----+-----+-----+-----+
        +-----+-----+-----+-----+-----                                 |Facing? | 1st | 2nd | 3rd | 4th |   
        | 1,4   2,4   3,4   4,4 |                     0                |--------+-----+-----+-----+-----|  
        +     +     +     +     +                     N                |North   |  W  |  N  |  E  |  S  |
        | 1,3   2,3   3,3   4,3 |                     |                |--------+-----+-----+-----+-----|
        +     +     +     +     +          3 W ------   ------ E 1     |South   |  E  |  S  |  W  |  N  |
        | 1,2   2,2   3,2   4,2 |                     |                |--------+-----+-----+-----+-----|
        +     +     +     +     +                     S                |East    |  N  |  E  |  S  |  W  |
        | 1,1   2,1   3,1   4,1 |                     2                |--------+-----+-----+-----+-----|
   -----+-----+-----+-----+-----+                                      |West    |  S  |  W  |  N  |  E  |
    0,0 |                                                              +--------+-----+-----+-----+-----+
    
*/

//Declaration of Variables and Constant Definitions
#define ONE_MOVE_UNIT_TICKS 123
#define WALL_DETECTED_DISTANCE 30 

typedef enum direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    UNDIRECTED,
} direction;

direction currFacingDirection = NORTH;
direction phase2directions[30];
int enum_counter = 0;
int currX = 1;
int currY = 1;
bool goal_reached = false;

void rotateCW90(){
    drive_goto(26, -25);
}

void rotateACW90(){
    drive_goto(-26, 25);
}

void rotateCW180(){
    drive_goto(51, -52);
}

void rotateACW180(){
    drive_goto(-51, 52);
}

void moveForward(int numOfCell){   
    drive_goto( numOfCell*ONE_MOVE_UNIT_TICKS, numOfCell*ONE_MOVE_UNIT_TICKS);
}

int checkIfWallExists(){
	int distance_from_front_wall = ping_cm(8);
	return (distance_from_front_wall < WALL_DETECTED_DISTANCE) ? 1 : 0;
}

//turns the robot to the specified direction in the argument
void turn(direction nextFacingDirection){

	int turn_degree = (nextFacingDirection-currFacingDirection)*90;
    
    switch(turn_degree){
        case 0:
            break;
        case 90:
            rotateCW90();
            break;
        case -90:
            rotateACW90();
            break;
        case 180:
            rotateCW180();
            break;
        case -180:
            rotateACW180();
            break;
        case 270:
            rotateACW90();
            break;
        case -270:
            rotateCW90();
            break;
    }
    currFacingDirection = nextFacingDirection;
}

//store a series of turn directions needed for robot to reach goal from start
void store_directions(direction p2direction){
    if (goal_reached == false) {
        if ((currX != 4) || (currY != 4)) {
            phase2directions[enum_counter] = p2direction;
            enum_counter++;
            } else {
                phase2directions[enum_counter] = p2direction;
                enum_counter++;
                phase2directions[enum_counter] = UNDIRECTED;
                goal_reached = true;
            }
    }
}

int checkNorthWall(){
    if (currFacingDirection != NORTH){
        turn(NORTH);
    }
    return checkIfWallExists() ? 1 : 0;
}

int checkEastWall(){
    if (currFacingDirection != EAST){
        turn(EAST);
    }
    return checkIfWallExists() ? 1 : 0;
}

int checkSouthWall(){
    if (currFacingDirection != SOUTH){
        turn(SOUTH);
    }
    return checkIfWallExists() ? 1 : 0;
}

int checkWestWall(){
    if (currFacingDirection != WEST){
        turn(WEST);
    }
    return checkIfWallExists() ? 1 : 0;
}

//left-hand wall follower rule, sets priority of turn direction based on current facing direction
//this function also updates the current coordinates of where the robot is, to know when to stop phases 1 and 2
void movetoNextCell(direction currdirection){
    if (currdirection == NORTH){
        if (checkWestWall() == 0) {
            turn(WEST);
            moveForward(1);
            currX--;
            store_directions(WEST);
        } else if (checkNorthWall() == 0) {
            turn(NORTH);
            moveForward(1);
            currY++;
            store_directions(NORTH);
        } else if (checkEastWall() == 0) {
            turn(EAST);
            moveForward(1);
            currX++;
            store_directions(EAST);
        } else {
            turn(SOUTH);
            moveForward(1);
            currY--;
            store_directions(SOUTH);
        }
    }

    if (currdirection == SOUTH){
        if (checkEastWall() == 0){
            turn(EAST);
            moveForward(1);
            currX++;
            store_directions(EAST);
        } else if (checkSouthWall() == 0){
            turn(SOUTH);
            moveForward(1);
            currY--;
            store_directions(SOUTH);
        } else if (checkWestWall() == 0){
            turn(WEST);
            moveForward(1);
            currX--;
            store_directions(WEST);
        } else {
            turn(NORTH);
            moveForward(1);
            currY++;
            store_directions(NORTH);
        }
    }

    if (currdirection == EAST){
        if (checkNorthWall() == 0){
            turn(NORTH);
            moveForward(1);
            currY++;
            store_directions(NORTH);
        } else if (checkEastWall() == 0){
            turn(EAST);
            moveForward(1);
            currX++;
            store_directions(EAST);
        } else if (checkSouthWall() == 0){
            turn(SOUTH);
            moveForward(1);
            currY--;
            store_directions(SOUTH);
        } else {
            turn(WEST);
            moveForward(1);
            currX--;
            store_directions(WEST);
        }
    }

    if (currdirection == WEST){
        if (checkSouthWall() == 0){
            turn(SOUTH);
            moveForward(1);
            currY--;
            store_directions(SOUTH);
        } else if (checkWestWall() == 0){
            turn(WEST);
            moveForward(1);
            currX--;
            store_directions(WEST);
        } else if (checkNorthWall() == 0){
            turn(NORTH);
            moveForward(1);
            currY++;
            store_directions(NORTH);
        } else {
            turn(EAST);
            moveForward(1);
            currX++;
            store_directions(EAST);
        }
    }
}

//keeps wall following until it reaches back to coordinates (1,1) which is the starting cell
void phase1(){
    do {
    print("Current X,Y coordinate: (%d,%d)\n", currX, currY);
    print("Current facing direction: %d\n", currFacingDirection);
    print("\n");
    movetoNextCell(currFacingDirection);
    } while ((currX != 1) || (currY != 1));
}

//checks if there are repeated cells to go to in the same direction, if yes, then move forward to cover the cells in one go
void phase2(){
    int i = 0;
    while (i < enum_counter){
        if ((phase2directions[i] == phase2directions[i+1]) && (phase2directions[i+1] == phase2directions[i+2])){
            turn(phase2directions[i]);
            moveForward(3);
            i += 3;
        } else if (phase2directions[i] == phase2directions[i+1]){
            turn(phase2directions[i]);
            moveForward(2);
            i += 2;
        } else {
            turn(phase2directions[i]);
            moveForward(1);
            i++;
        }
    }
}

int main() {
    pause(1000);
    drive_goto(25,25);
    print("***PHASE 1 BEGIN***\n");
    moveForward(1);
    phase1();
    turn(SOUTH);
    moveForward(1);
    turn(NORTH);
    pause(1000);
    print("***PHASE 2 BEGIN***\n");
    moveForward(1);
    phase2();
    print("***END OF MAZE***\n");
    return 0;
}

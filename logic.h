
#ifndef __LOGIC__
#define __LOGIC__

//Set and Get
void set_positionX(int positionX);
void set_positionY(int positionY);
int  get_positionX();
int  get_positionY();

void set_velocityX(int velocityX);
void set_velocityY(int velocityY);
int  get_velocityX();
int  get_velocityY();

void set_thrustX(int thrustX);
void set_thrustY(int thrustY);
int  get_thrustX();
int  get_thrustY();

// 0 -> smooth sailing
// 1 -> blackout
// 2 -> lose :(
// 3 -> win :)
void set_shipState(int input);
int  get_shipState();

void set_sliderPos(int pos);
int  get_sliderPos();

void set_angle(int angle);
int  get_angle();

void button_inc();
void button_dec();
int  get_button_num();

//Task Logic
void physics_logic();

#endif
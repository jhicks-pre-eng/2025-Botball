#include <kipr/wombat.h>
// servo 2 is big claw
// servo 3 is mini
// servo 0 is mini swing
// servo 1 is big swing
//pivot 1 1200

void Drive(int distance);
void LTurn(float degree);
void RTurn(float degree);
void DriveBack(int distance);

int main()
{
  
    msleep(700);  // this is just a little delay for our other robot to have time to get out
    enable_servos(1); 
    set_servo_position(1,884);  // Setting our servo one just to get it ready for the burger grab
    msleep(1200);
    set_servo_position(3,1250);  // Setting up some counter balance
    Drive(-2450);  // Initial drive
    msleep(500);
    RTurn(60);  // First turn
    msleep(500);
    Drive(-2650);  // Drive to burger
    msleep(500);
    set_servo_position(1,870);  // Perfect height to grab burger
    msleep(500);
    set_servo_position(2,1800);  // opening claw
    msleep(0);
    Drive(-1650); // Driving rest of the way to burger
    motor(0,0);  // Motors off
    motor(1,0);  
    msleep(500);
    set_servo_position(2,1000);  // Squeezing burger
    ao();
    msleep(500);
    DriveBack(2560);  // Driving away from burger area
    msleep(500);
    ao();
    msleep(500);
    RTurn(105);  // Turn to go to the trays
    motor(0,0);
    motor(1,0);
    msleep(500);
    Drive(-5500);  // Driving to trays
    msleep(500);
    ao();
    msleep(500);
    RTurn(70);  // Lining up
    ao();
    msleep(500);
    set_servo_position(1,355);  // Drop servo arm
    msleep(250);
    set_servo_position(2,1900);// Drop burger in tray
    msleep(500);
    set_servo_position(1,1250); // Raise arm back up
    ao();
    msleep(500);
    RTurn(128); // Turn back to go hopefully grab the hot dog
    Drive(-3900); // Drive towards hot dog area
    set_servo_position(1,870); // Set arm back up
  	RTurn(100); // Turn towards hot dog
    ao();
    msleep(500);
    Drive(-2500);
    msleep(500);
    set_servo_position(2,1250); // Squeeze hot dog
    ao();
    msleep(500);
    DriveBack(2700); // Drive back 
    ao();
    msleep(500);
    RTurn(80); // Turn to trays
    Drive(-2800); // Drive to trays
    msleep(500);
    RTurn(120);
    Drive(-3000);
    set_servo_position(1,355); // Drop arm
    set_servo_position(2,2000); // open claw
    set_servo_position(3,0);  // Bring up counterweight
  
  
   return 0;
}
void Drive(int distance)
{
cmpc(0);
    while (gmpc(0)>distance-20) 
    {
    motor(0,-70);
    motor(1,-70+3);
    }
}
 void LTurn(float degree)
 {
cmpc(0);
    while (gmpc(0)<degree*12.972) 
    {
    motor(0,100);
    motor(1,0);
    }
 }

 void RTurn(float degree)
 {
cmpc(1);
    while (gmpc(1)<degree*12.972) 
    {
    motor(1,50);
    motor(0,-50);
    }
 }
void DriveBack(int distance)
{
cmpc(0);
    while (gmpc(0)<distance-20) 
    {
    motor(0,70);
    motor(1,70-3);
    }
}
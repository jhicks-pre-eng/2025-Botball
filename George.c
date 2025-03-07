#include <kipr/wombat.h>
void Crab(int distance);
void Drive(int distance);
void Lturn(float degree);
void Rturn(float degree);
void DriveBack(int ditance);
int main()
    //servo 0 is ARM, high # to raise arm, small to lower
    //servo 1 is CLAW, high # to close claw, small to open
    
    //motor 0 is
    //motor 1 is
    //motor 2 is
    //motor 3 is
{
    enable_servos(0,1); 
    set_servo_position(1,1250); //sets claw open
    set_servo_position(0,1870); //sets arm down
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500); 
    
    Crab(1000); //crab walk left
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
    
    Drive(5000); //drive forward, collects first 3 condiments
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
    
    set_servo_position(1,600); //close claw, collects condiments
    ao();
    msleep(500);
    
    set_servo_position(0,1500-30); //raise arm, with first 3 condiments in them
    msleep(500);
    
    Rturn(75+3); //turn right, condiments in arm
    
    Drive(250+10); //drive forward, toward container 1
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep (500);
    
    set_servo_position(1,1250); //open claw, drops condiments into first container ^o^
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500); 
    
// 
// 1/3 containers
    
    DriveBack(-350); //slight drive back
    
    Lturn(60+5); //turn left
    ao();
    msleep(500);
    
    set_servo_position(0,1870); //lower arm with bump
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500); 
    
    Drive(600); //slight drive forward
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
    
    Lturn(10); //slight turn left
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
    
    Crab(1200); //crab walk left (seems to be going forward for some reason)
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
    
    DriveBack(-400); //drive backwards to counter the forward movement ^^^
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
    
    Crab(1200); //crab walk left, push condimetns 
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
    
    set_servo_position(1,600); //close claw, collect condiments
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
    
    set_servo_position(0,1500); //raise arm, with condiments
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
    
    Rturn(100); //turn right, with condiments
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
    
    Drive(1800); //drive forward, with condiments
    
    set_servo_position(1,1250); //open claw, dropping condiments into second container :D (yay)
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
    
//
// 2/3 containers
    
    Lturn(28); //slight turn left
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
//2    
    DriveBack(-600); //slight drive backwards
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
//2   
    Lturn(60); //turn left
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
//2    
    set_servo_position(0,1870); //lower arm
//2    
    Drive(3700); //drive forward, collect last 3 condiments
//2    
    set_servo_position(1,600); //close claw, collect condiments
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
//2    
    set_servo_position(0,1500); //raise arm, w/ condiments
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    msleep(500);
//2    
    Rturn(150-5); //turn right, with condimetns
//2    
    Drive(250+10); //drive forward, toward container 3
//2    
    set_servo_position(1,1250); //open claw, drop final condmients in third container \^u^/

//
// 3/3 containers 
    
    return 0;
}




//command area
void Drive(int distance)
{
cmpc(0);
    while (gmpc(0)<distance-25) 
    {
        motor(0,75);
        motor(1,75);
        motor(2,75);
        motor(3,75);
    }
}
    void Crab(int distance)
{
cmpc(1);
    while (gmpc(1)<distance) 
    {
        motor(0,-85);
        motor(1,85);
        motor(2,85);
        motor(3,-85);
    }
    }
void Lturn(float degree)
{
cmpc(0);
        while (gmpc(0)<degree*21)
        {
            motor(0,75);
            motor(1,-75);
            motor(2,75);
            motor(3,-75);
        }
}
void Rturn(float degree)
{
cmpc(1);
        while (gmpc(1)<degree*21)
        {
            motor(0,-75);
            motor(1,75);
            motor(2,-75);
            motor(3,75);
        }
}
void DriveBack(int distance)
{
cmpc(0);
    while (gmpc(0)>distance-25) 
    {
        motor(0,-75);
        motor(1,-75);
        motor(2,-75);
        motor(3,-75);
    }
}
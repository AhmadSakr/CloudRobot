#include "motor.h"




Motor::Motor(int pwmRightPin1, int pwmRightPin2, int pwmLeftPin1, int pwmLeftPin2, int pwmMinVal, int pwmMaxVal)
{
	this->pwmRightPin1 = pwmRightPin1;
	this->pwmRightPin2 = pwmRightPin2;
	this->pwmLeftPin1 = pwmLeftPin1;
	this->pwmLeftPin2 = pwmLeftPin2;
	this->pwmMinVal = pwmMinVal;
	this->pwmMaxVal = pwmMaxVal;
	
	init();
}


Motor::~Motor()
{
}

void Motor::forward()
{
	rightSideForward();
	leftSideForward();
}

void Motor::backward()
{
	rightSideBackward();
	leftSideBackward();
}
void Motor::turnRight()
{
	rightSideBackward();
	leftSideForward();
}
void Motor::turnLeft()
{
	
	leftSideBackward();
	rightSideForward();
}

void Motor::init()
{
	wiringPiSetupGpio();
	pinMode(pwmRightPin1, OUTPUT);
	pinMode(pwmRightPin2, OUTPUT);
	pinMode(pwmLeftPin1, OUTPUT);
	pinMode(pwmLeftPin2, OUTPUT);
	softPwmCreate(pwmRightPin1, pwmMinVal, pwmMaxVal);
	softPwmCreate(pwmRightPin2, pwmMinVal, pwmMaxVal);
	softPwmCreate(pwmLeftPin1, pwmMinVal, pwmMaxVal);
	softPwmCreate(pwmLeftPin2, pwmMinVal, pwmMaxVal);
}

void Motor::rightSideForward()
{
	softPwmWrite(pwmRightPin1, pwmMinVal);
	softPwmWrite(pwmRightPin2, pwmMaxVal);
}

void Motor::rightSideBackward()
{
	softPwmWrite(pwmRightPin1, pwmMaxVal);
	softPwmWrite(pwmRightPin2, pwmMinVal);
}

void Motor::leftSideForward()
{
	softPwmWrite(pwmLeftPin1, pwmMinVal);
	softPwmWrite(pwmLeftPin2, pwmMaxVal);
}

void Motor::leftSideBackward()
{
	softPwmWrite(pwmLeftPin1, pwmMaxVal);
	softPwmWrite(pwmLeftPin2, pwmMinVal);
}

void Motor::leftSideStop()
{
	softPwmWrite(pwmLeftPin1, pwmMinVal);
	softPwmWrite(pwmLeftPin2, pwmMinVal);
}

void Motor::rightSideStop()
{
	softPwmWrite(pwmRightPin1, pwmMinVal);
	softPwmWrite(pwmRightPin2, pwmMinVal);
}

void Motor::stop()
{
	rightSideStop();
	leftSideStop();
}
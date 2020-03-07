#pragma once
#include <wiringPi.h>
#include <softPwm.h>

class Motor
{
	
public:
	Motor(int pwmRightPin1, int pwmRightPin2, int pwmLeftPin1, int pwmLeftPin2, int pwmMinVal, int pwmMaxVal);
	~Motor();
	void forward();
	void backward();
	void turnRight();
	void turnLeft();
	void stop();
private:
	void init();
	void rightSideForward();
	void leftSideForward();
	void rightSideBackward();
	void leftSideBackward();
	void leftSideStop();
	void rightSideStop();
	
	int pwmRightPin1;
	int pwmRightPin2;
	int pwmLeftPin1;
	int pwmLeftPin2;
	int pwmMinVal;
	int pwmMaxVal;
};


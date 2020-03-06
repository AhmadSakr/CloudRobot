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
private:
	void init();
	void rightSideForward();
	void leftSideForward();
	void rightSideBackward();
	void leftSideBackward();
	
	int pwmRightPin1;
	int pwmRightPin2;
	int pwmLeftPin1;
	int pwmLeftPin2;
	int pwmMinVal;
	int pwmMaxVal;
};


#include <iostream>
#include <wiringPi.h>
#include <csignal>
#include <softPwm.h>

using namespace std;

int main(int argc, char *argv[])
{
	wiringPiSetupGpio();
	pinMode(21,OUTPUT);
	softPwmCreate(21, 0, 100);
	
	while(true)
	{
		softPwmWrite(21, 0);
		delay(1000);
		softPwmWrite(21, 50);
		delay(1000);
		softPwmWrite(21, 100);
		delay(1000);
	}
	return 0;
}
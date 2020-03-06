#include <iostream>
#include "motor.h"

using namespace std;

int main(int argc, char *argv[])
{
	Motor motor(20,21,13,19,0,100);
	
	while (true)
	{
		motor.forward();
		cout << "f" <<endl;
		delay(3000);
		motor.backward();
		cout << "b" << endl;
		delay(3000);
		motor.turnLeft();
		cout << "l" << endl;
		delay(3000);
		motor.turnRight();
		cout << "r" << endl;
		delay(3000);
		
	}
	return 0;
}
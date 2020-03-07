#include <cstdlib>
#include <iostream>
#include <string>
#include <wiringPi.h>
#include "motor.h"
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client; 
using namespace std;

int main(int argc, char** argv)
{
	Motor motor(20, 21, 13, 19, 0, 100);
	http_client client(U("http://192.168.1.9:8000"));
	uri_builder builder(U("/test"));
	http_response response;
	utility::string_t body;
	string body_string;
	while (true)
	{
		try
		{
			response = client.request(methods::GET, builder.to_string()).get();
			body = response.extract_string(true).get();
			//cout << "Received response status code: " << response.status_code() << ", body: "  << body << endl;
		}
		catch (const std::exception& e)
		{
			motor.stop();
			cout << e.what() << endl;
		}
		body_string = body;
		if (body_string == "UP")
		{
			motor.forward();
			cout << "UP" << endl;
		}
		else if (body_string == "DOWN")
		{
			motor.backward();
			cout << "DOWN" << endl;
		}
		else if (body_string == "LEFT")
		{
			motor.turnLeft();
			cout << "LEFT" << endl;
		}
		else if (body_string == "RIGHT")
		{
			motor.turnRight();
			cout << "RIGHT" << endl;
		}
		else
		{
			motor.stop();
			cout << "STOP" << endl;
		}		
		delay(100);
	}
}
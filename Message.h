#pragma once
#include <iostream>

using namespace std;\
class Message
{
protected:
	string _message;
		
public:
	Message();
	
	Message(string message);
	~Message();

	void printMess(string mess);
	string GetMessage();
};


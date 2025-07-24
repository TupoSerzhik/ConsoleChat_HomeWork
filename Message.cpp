#include "Message.h"


Message::Message()
{
}

void Message::printMess(string mess)
{
	cout << mess;
}
string Message::GetMessage()
{
	return _message;
}

Message::Message(string message) : _message(message)
{}

Message::~Message()
{
}

#include "Subject.h"

Subject::Subject(string str)
{
	cout << "1\n";
	name = str;
	pre = post = NULL;
}

Subject::Subject(string str, Subject* preSub, Subject* postSub)
{
	name = str;
	pre = preSub;
	post = postSub;
}

void Subject::setName(string str)
{
	name = str;
	pre = post = NULL;
}

string Subject::getName()
{
	return name;
}

void Subject::display()
{
	cout << name << endl;
}

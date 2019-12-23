#include "Student.h"

Student::Student(string str, int percentage)
{
	cout << "3\n";
	name = str;
	agr = percentage;
	next = 0;
}

void Student::setName(string str)
{
	name = str;
}

void Student::setAggregate(float matric, float inter, float entryTest)
{
	agr = matric * 10 / 100 + inter * 50 / 100 +
		entryTest * 40 / 100;
}

/*void Student::setAggregate(int percentage)
{
	agr = percentage;
}
*/
void Student::registerSubject(Subject sub)
{
	int num;
	if (sub.pre)
	{
		cout << "Have You studied";
		sub.pre->display();
		cout << "Enter 1 for yes and 0 for No\n";
		cin >> num;
		if (num == 1)
			regSubjects.addSubject(sub);
		else
			cout << "You cannot study this Subject\n";
	}
	else
		regSubjects.addSubject(sub);
}

Subject* Student::unRegisterSubject(string str)
{

	return regSubjects.removeSubject(str);
}

int Student::getAggregate()
{

	return agr;
}

string Student::getName()
{
	return name;
}

void Student::display()
{
	cout << "Name of student : " << name << endl;
	cout << "Aggregate : " << agr;
	regSubjects.display();
}

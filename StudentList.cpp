#include "StudentList.h"

StudentList::StudentList(Student std)
{
	headPtr = &std;
	std.next = NULL;
	numOfStudents = 1;
}

void StudentList::addStudent(Student std)
{
	Student* ptr;
	ptr = headPtr;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = &std;
	std.next = NULL;
	++numOfStudents;
}

Student* StudentList::removeStudent(string str)
{
	Student* rptr,* ptr;
	rptr = ptr = headPtr;
	if (ptr->getName() == str)
	{
		headPtr = headPtr->next;
		ptr->next = NULL;
		--numOfStudents;
		return ptr;
	}
	rptr = rptr->next;
	while (rptr->next != NULL)
	{
		if (rptr->getName() == str)
		{
			ptr->next = rptr->next;
			rptr->next = NULL;
			--numOfStudents;
			return rptr;
		}
		ptr = rptr;
		rptr = rptr->next;
	}
	return NULL;
}

int StudentList::getNum()
{
	return numOfStudents;
}

Student* StudentList::getLastStudent()
{
	Student* ptr = headPtr;
	while (ptr->next)
		ptr = ptr->next;
	return ptr;
}

void StudentList::display()
{
	if (!headPtr)
		cout << "There are no Students Yet.\n";
	else
	{
		cout << "Students are :\n";
		Student* ptr;
		ptr = headPtr;
		while (ptr->next != NULL)
		{
			ptr->display();
			ptr = ptr->next;
		}
	}
	
}

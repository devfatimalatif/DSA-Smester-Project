#include "SubjectList.h"



SubjectList::SubjectList()
{
	num = 0;
}

SubjectList::SubjectList(Subject sub)
{
	List[0] = sub;
	num = 1;
}

void SubjectList::addSubject(Subject sub)
{
	cout << "2\n";
	List[num] = sub;
	++num;
}

Subject* SubjectList::removeSubject(int n)
{
	Subject* ptr = NULL;
	if (n <= num)
	{
		ptr = &List[n - 1];
		for (int i = n; i < num; i++)
		{
			List[i - 1] = List[i];
		}
		--num;
	}
	

	return ptr;
}

Subject* SubjectList::removeSubject(string str)
{
	for (int i = 0; i < num; ++i)
	{
		if(str.compare(List[i].getName())==0)
		{
			Subject* ptr = &List[i];
			for (int j = i + 1; j < num; j++)
			{
				List[j - 1] = List[j];
			}
			--num;
			return ptr;
		}
	}
	return NULL;
}

int SubjectList::getNum()
{
	return num;
}

void SubjectList::display()
{
	cout << "Subjects are :\n";
	for (int i = 0; i < num; ++i)
	{
		cout << i + 1 << "\t";
		List[i].display();
	}
}

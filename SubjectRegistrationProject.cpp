// SubjectRegistrationProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StudentList.h"

using namespace std;

int main()
{

    Subject sub1("PF");
    Subject sub2("OOP");
    Subject sub3("DSA");
    Subject sub4("DLD");
    Subject sub5("ItoC");
    Subject sub6("Calculus");
    Subject sub7("LAD");

    sub1.post = &sub2;
    sub2.pre = &sub1;
    sub2.post = &sub3;
    sub3.pre = &sub2;
    sub4.pre = &sub5;
    sub5.post = &sub4;
    sub6.post = &sub7;
    sub7.pre = &sub6;

    SubjectList* mySubjectsList = new SubjectList();

    mySubjectsList->addSubject(sub1);
    mySubjectsList->addSubject(sub2);
    mySubjectsList->addSubject(sub3);
    mySubjectsList->addSubject(sub4);
    mySubjectsList->addSubject(sub5);
    mySubjectsList->addSubject(sub6);
    mySubjectsList->addSubject(sub7);

    Student s1("Ali", 85);
    Student s2("Ahmed", 58);
    Student s3("Raza", 75);
    Student s4("Saad", 62);
    Student s5("Rehan", 55);
    Student s6("Salman", 83);
    Student s7("Hadi", 79);
    Student s8("Ibrahim", 71);
    Student std;

    StudentList myStudentsList;
    myStudentsList.addStudent(s1);
    myStudentsList.addStudent(s2);
    myStudentsList.addStudent(s3);
    myStudentsList.addStudent(s4);
    myStudentsList.addStudent(s5);
    myStudentsList.addStudent(s6);
    myStudentsList.addStudent(s7);
    myStudentsList.addStudent(s8);

    int input1, input2;

    do {
        cout << "Write 1 to register a new student\n";
        cout << "Write 2 to display lists of students registered\n";
        cout << "Write 3 to register in subject\n";
        cout << "Write 4 to quit\n";
        cin >> input1;
        switch (input1)
        {
        case 1: {
            string str;
            float metric_marks, fsc_marks, entryTest_marks;
            cout << "Write name of student\n";
            cin >> str;
            cout << "Enter metric percentage\n";
            cin >> metric_marks;
            cout << "Enter fsc percentage\n";
            cin >> fsc_marks;
            cout << "Enter entry test percentage\n";
            cin >> entryTest_marks;
            std.setName(str);
            std.setAggregate(metric_marks, fsc_marks, entryTest_marks);
            myStudentsList.addStudent(std);
            break;
        }
          
        case 2:
            myStudentsList.display();
            break;
        case 3:
        {
            cout << "Select Subject to register :\n";
            cout << "1. PF\n";
            cout << "2. Object Oriented Programming\n";
            cout << "3. Data Structure and Alogrithm \n";
            cout << "4. Digital logic Design\n";
            cout << "5. ItoC\n";
            cout << "6. Calculus \n";
            cout << "7. LAD \n";
            cin >> input2;
            while (input2 < 1 && input2 > 7)
            {
                if (input2 == 1)
                    myStudentsList.getLastStudent()->registerSubject(sub1);
                else if (input2 == 2)
                    myStudentsList.getLastStudent()->registerSubject(sub2);
                else if (input2 == 3)
                    myStudentsList.getLastStudent()->registerSubject(sub3);
                else if (input2 == 4)
                    myStudentsList.getLastStudent()->registerSubject(sub4);
                else if (input2 == 5)
                    myStudentsList.getLastStudent()->registerSubject(sub5);
                else if (input2 == 6)
                    myStudentsList.getLastStudent()->registerSubject(sub6);
                else if (input2 == 7)
                    myStudentsList.getLastStudent()->registerSubject(sub7);
                else
                    cout << "Enter Correct Option\n";
            }
        }
            
        case 4:
            break;
        default:
            cout << "Enter Correct Option\n";
        }
    } while (input1 != 4);

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "book.h"
#include "student.h"
#include "student_list.h"

using namespace std;

int main(int argc, char** argv)
{

    Book book1 = Book("The Iliad", "Homer Simpson", 599);
    Book book2 = Book("The Window", "Peter Griffin", 348);

    vector<Book> books;

    books.push_back(book1);
    books.push_back(book2);

    student_list students;

    for (int i = 0; i < books.size(); i++) {
        cout << "Author: " << books[i].getAuthor() << endl;
    }

    int choice = 0;

    while (choice != -1)
    {
        cout << endl
            << "## (College Student Tuition) ##" << endl;
        cout << endl
            << "1 Add Student Details";
        cout << endl
            << "2 Print Student Names";
        cout << endl
            << "-1 Exit";
        cout << "\n\n Enter your choice : ";
        cin >> choice;

        // cout << endl << "Press any key to add Students details\n";
        getchar();

        switch (choice)
        {
        case 1:
        {
            cout << endl << "\n Enter Name of Student: ";
            string name;
            getline(cin, name);
            students.addStudent(name);
        }
        break;
        case 2:
            students.printStudents();
            break;
        case -1:
            cout << endl
                << "thank you for using this thing!!";
            break;
        default: {
            cout << endl
                << "Invalid Choice..";
            getchar();
        }

        }
    }



    return 0;
}
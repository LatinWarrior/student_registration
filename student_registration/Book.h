#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book
{
private:
    string title;
    int pages;
    string author;

public:
    Book(string aTitle, string anAuthor, int aPages);
    Book();
    string getAuthor() { return author; };
    string getTitle() { return title; };
    int getPages() { return pages; };
};

#endif
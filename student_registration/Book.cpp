#include "Book.h"

using namespace std;

Book::Book() {
    title = "";
    author = "";
    pages = 0;
};

Book::Book(string aTitle, string anAuthor, int aPages) {
    title = aTitle;
    author = anAuthor;
    pages = aPages;
};


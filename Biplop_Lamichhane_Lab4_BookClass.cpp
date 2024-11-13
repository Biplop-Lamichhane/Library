#include "Biplop_Lamichhane_Lab4_BookClass.hpp"
#include <iostream>
using namespace std;

Book::Book() : title(""), author(""), ISBN(0), status(false), checkedOutBy("") {}

Book::Book(string p_title, string p_author, int p_ISBN)
    : title(p_title), author(p_author), ISBN(p_ISBN), status(false), checkedOutBy("") {}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getISBN() const { return ISBN; }
bool Book::getStatus() const { return status; }

void Book::setTitle(string new_title) { title = new_title; }
void Book::setAuthor(string new_author) { author = new_author; }
void Book::setISBN(int new_ISBN) { ISBN = new_ISBN; }

bool Book::checkOutBook(string name) {
    if (status) return false;
    status = true;
    checkedOutBy = name;
    return true;
}

void Book::returnBook() {
    status = false;
    checkedOutBy = "";
}

void Book::outputBook() const {
    cout << title << " by " << author << endl;
    cout << "ISBN: " << ISBN << endl;
    if (status) {
        cout << "Checked out by: " << checkedOutBy << endl;
    }
}

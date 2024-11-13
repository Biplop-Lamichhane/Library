#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int ISBN;
    bool status;
    string checkedOutBy;

public:
    Book();
    Book(string p_title, string p_author, int p_ISBN);

    string getTitle() const;
    string getAuthor() const;
    int getISBN() const;
    bool getStatus() const;

    void setTitle(string new_title);
    void setAuthor(string new_author);
    void setISBN(int new_ISBN);

    bool checkOutBook(string name);
    void returnBook();
    void outputBook() const;
};

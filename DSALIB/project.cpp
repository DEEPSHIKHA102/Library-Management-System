#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int id, const string& title, const string& author)
        : id(id), title(title), author(author), isIssued(false) {}
};

class Library {
private:
    vector<Book> books;
public:
    void addBook(int id, const string& title, const string& author);
    void searchBookById(int id);
    void searchBookByTitle(const string& title);
    void issueBook(int id);
    void returnBook(int id);
    void listAllBooks();
    void deleteBook(int id);
};

void Library::addBook(int id, const string& title, const string& author) {
    books.push_back(Book(id, title, author));
    cout << "Book added successfully.\n";
}

void Library::searchBookById(int id) {
    for (const auto& book : books) {
        if (book.id == id) {
            cout << "Book found: ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author 
            << ", Status: " << (book.isIssued ? "Issued" : "Available") << '\n';
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::searchBookByTitle(const string& title) {
    for (const auto& book : books) {
        if (book.title == title) {
            cout << "Book found: ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Status: " << (book.isIssued ? "Issued" : "Available") << '\n';
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::issueBook(int id) {
    for (auto& book : books) {
        if (book.id == id) {
            if (!book.isIssued) {
                book.isIssued = true;
                cout << "Book issued successfully.\n";
            } else {
                cout << "Book is already issued.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::returnBook(int id) {
    for (auto& book : books) {
        if (book.id == id) {
            if (book.isIssued) {
                book.isIssued = false;
                cout << "Book returned successfully.\n";
            } else {
                cout << "Book was not issued.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::listAllBooks() {
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.id < b.id;
    });
    for (const auto& book : books) {
        cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Status: " << (book.isIssued ? "Issued" : "Available") << '\n';
    }
}

void Library::deleteBook(int id) {
    auto it = remove_if(books.begin(), books.end(), [id](const Book& book) {
        return book.id == id;
    });
    if (it != books.end()) {
        books.erase(it, books.end());
        cout << "Book deleted successfully.\n";
    } else {
        cout << "Book not found.\n";
    }
}

int main() {
    Library library;
    int choice, id;
    string title, author;

    while (true) {
        cout << "Library Management System\n";
        cout << "1. Add New Book\n2. Search Book by ID\n3. Search Book by Title\n4. Issue Book\n5. Return Book\n6. List All Books\n7. Delete Book\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore(); // it is used to skip characters in input buffer 
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                library.addBook(id, title, author);
                break;
            case 2:
                cout << "Enter Book ID: ";
                cin >> id;
                library.searchBookById(id);
                break;
            case 3:
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, title);
                library.searchBookByTitle(title);
                break;
            case 4:
                cout << "Enter Book ID to issue: ";
                cin >> id;
                library.issueBook(id);
                break;
            case 5:
                cout << "Enter Book ID to return: ";
                cin >> id;
                library.returnBook(id);
                break;
            case 6:
                library.listAllBooks();
                break;
            case 7:
                cout << "Enter Book ID to delete: ";
                cin >> id;
                library.deleteBook(id);
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}
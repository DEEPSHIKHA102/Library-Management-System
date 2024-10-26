#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Book {
    int id;
    std::string name;
    std::string author;
    std::string genre;
    int quantity;
};

struct User {
    std::string username;
    std::string password;
    bool isLibrarian;
};

std::vector<Book> books;
std::unordered_map<std::string, User> users;
int nextBookId = 1;

void displayMainMenu() {
    std::cout << "---------------------------------------------\n";
    std::cout << "| WELCOME TO THE LIBRARY |\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "Please Choose an appropriate option:\n";
    std::cout << "=======================================\n";
    std::cout << "0. Exit\n";
    std::cout << "1. LogIn as Librarian\n";
    std::cout << "2. LogIn as Student\n";
    std::cout << "Please Pick any one option: ";
}

bool login(bool isLibrarian) {
    std::string username, password;
    std::cout << "-----------------------------------------------------\n";
    std::cout << "| LogIn as " << (isLibrarian ? "Librarian" : "Student") << " |\n";
    std::cout << "-----------------------------------------------------\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    auto it = users.find(username);
    if (it != users.end() && it->second.password == password && it->second.isLibrarian == isLibrarian) {
        std::cout << "Access granted.\n";
        return true;
    } else {
        std::cout << "Error: Invalid username or password.\n";
        return false;
    }
}

void displayAllBooks() {
    for (const auto& book : books) {
        std::cout << "ID: " << book.id << "\n";
        std::cout << "Book Name: " << book.name << "\n";
        std::cout << "Author: " << book.author << "\n";
        std::cout << "Genre: " << book.genre << "\n";
        std::cout << "Quantity Available: " << book.quantity << "\n\n";
    }
}

void insertBook() {
    Book newBook;
    newBook.id = nextBookId++;
    std::cout << "Book Name: ";
    std::cin.ignore();
    std::getline(std::cin, newBook.name);
    std::cout << "Author Name: ";
    std::getline(std::cin, newBook.author);
    std::cout << "Book Genre: ";
    std::getline(std::cin, newBook.genre);
    std::cout << "Book Quantity: ";
    std::cin >> newBook.quantity;

    books.push_back(newBook);
    std::cout << "Book added successfully.\n";
}

void deleteBook() {
    std::string bookName;
    std::cout << "Enter Book Name to delete: ";
    std::cin.ignore();
    std::getline(std::cin, bookName);

    auto it = std::find_if(books.begin(), books.end(), 
        [&bookName](const Book& book) { return book.name == bookName; });

    if (it != books.end()) {
        books.erase(it);
        std::cout << "[BOOK DELETED]\n";
    } else {
        std::cout << "Book not found.\n";
    }
}

void searchBook() {
    std::string bookName;
    std::cout << "Book Name: ";
    std::cin.ignore();
    std::getline(std::cin, bookName);

    auto it = std::find_if(books.begin(), books.end(), 
        [&bookName](const Book& book) { return book.name == bookName; });

    if (it != books.end()) {
        std::cout << "[BOOK FOUND]\n";
        std::cout << "Book Title: " << it->name << "\n";
        std::cout << "Book Author: " << it->author << "\n";
        std::cout << "Book Genre: " << it->genre << "\n";
        std::cout << "Book Quantity: " << it->quantity << "\n";
    } else {
        std::cout << "Book not found.\n";
    }
}

void showBooksByGenre() {
    std::string genre;
    std::cout << "Enter Genre: ";
    std::cin.ignore();
    std::getline(std::cin, genre);

    for (const auto& book : books) {
        if (book.genre == genre) {
            std::cout << book.name << " by " << book.author << "\n";
        }
    }
}

void registerStudent() {
    std::string username, password;
    std::cout << "Student Name: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    users[username] = {username, password, false};
    std::cout << "[USER ADDED]\n";
}

void displayLibrarianMenu(const std::string& name) {
    std::cout << "++++++++++ M E N U ++++++++++\n";
    std::cout << "Welcome " << name << "\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Display All Books\n";
    std::cout << "2. Insert a Book\n";
    std::cout << "3. Delete a Book\n";
    std::cout << "4. Search Book\n";
    std::cout << "5. Show Books by Genre\n";
    std::cout << "6. Register a Student\n";
    std::cout << "7. LogOut\n";
    std::cout << "Select an option: ";
}

void librarianMenu(const std::string& name) {
    while (true) {
        displayLibrarianMenu(name);
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Exiting...\n";
                return;
            case 1:
                displayAllBooks();
                break;
            case 2:
                insertBook();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                searchBook();
                break;
            case 5:
                showBooksByGenre();
                break;
            case 6:
                registerStudent();
                break;
            case 7:
                std::cout << "Logging out...\n";
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void displayStudentMenu(const std::string& name) {
    std::cout << "++++++++++ M E N U ++++++++++\n";
    std::cout << "Welcome " << name << "\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Display All Books\n";
    std::cout << "2. Issue a Book\n";
    std::cout << "3. Return a Book\n";
    std::cout << "4. Show all Issued Books\n";
    std::cout << "5. Search Book\n";
    std::cout << "6. Show Books by Genre\n";
    std::cout << "7. LogOut\n";
    std::cout << "Select an option: ";
}

void studentMenu(const std::string& name) {
    while (true) {
        displayStudentMenu(name);
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Exiting...\n";
                return;
            case 1:
                displayAllBooks();
                break;
            case 2:
                // Issue a book
                break;
            case 3:
                // Return a book
                break;
            case 4:
                // Show all issued books
                break;
            case 5:
                searchBook();
                break;
            case 6:
                showBooksByGenre();
                break;
            case 7:
                std::cout << "Logging out...\n";
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    // Add some sample users
    users["admin"] = {"admin", "admin123", true};
    users["student"] = {"student", "student123", false};

    while (true) {
        displayMainMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Exiting...\n";
                return 0;
            case 1:
                if (login(true)) {
                    librarianMenu("Librarian");
                }
                break;
            case 2:
                if (login(false)) {
                    studentMenu("Student");
                }
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
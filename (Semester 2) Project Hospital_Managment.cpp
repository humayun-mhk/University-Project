#include <iostream>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

// Class to manage the library system
class Library {
private:
    Book books[100]; // Array to store books
    int bookCount = 0; // Number of books in the library

public:
    void addBook() {
        if (bookCount < 100) {
            cout << "Enter Book ID: ";
            cin >> books[bookCount].id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, books[bookCount].title);
            cout << "Enter Author: ";
            getline(cin, books[bookCount].author);
            bookCount++;
            cout << "Book added successfully!\n";
        } else {
            cout << "Library is full!\n";
        }
    }

    void displayBooks() {
        if (bookCount == 0) {
            cout << "No books available.\n";
            return;
        }
        cout << "\nBooks in Library:\n";
        for (int i = 0; i < bookCount; i++) {
            cout << "ID: " << books[i].id << " | Title: " << books[i].title << " | Author: " << books[i].author << "\n";
        }
    }

    void searchBook() {
        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {
                cout << "Book Found - Title: " << books[i].title << ", Author: " << books[i].author << "\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void deleteBook() {
        int id;
        cout << "Enter Book ID to delete: ";
        cin >> id;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {
                for (int j = i; j < bookCount - 1; j++) {
                    books[j] = books[j + 1];
                }
                bookCount--;
                cout << "Book deleted successfully!\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: library.addBook(); break;
            case 2: library.displayBooks(); break;
            case 3: library.searchBook(); break;
            case 4: library.deleteBook(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}


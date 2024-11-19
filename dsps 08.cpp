#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;
    Book* next;

    Book(string t, string a, string i, bool avail) {
        title = t;
        author = a;
        isbn = i;
        isAvailable = avail;
        next = nullptr;
    }
};

class Library {
private:
    Book* head;

public:
    Library() {
        head = nullptr;
    }

    // Add a new book to the library
    void addBook(string title, string author, string isbn, bool isAvailable) {
        Book* newBook = new Book(title, author, isbn, isAvailable);
        if (!head) {
            head = newBook;
        } else {
            Book* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newBook;
        }
        cout << "Book added successfully.\n";
    }

    // Display all books in the library
    void displayBooks() {
        if (!head) {
            cout << "Library is empty.\n";
            return;
        }
        Book* temp = head;
        while (temp != nullptr) {
            cout << "Title: " << temp->title << ", Author: " << temp->author
                 << ", ISBN: " << temp->isbn << ", Availability: " 
                 << (temp->isAvailable ? "Available" : "Not Available") << endl;
            temp = temp->next;
        }
    }

    // Search for a book by ISBN
    void searchBook(string isbn) {
        Book* temp = head;
        while (temp != nullptr) {
            if (temp->isbn == isbn) {
                cout << "Book found:\n";
                cout << "Title: " << temp->title << ", Author: " << temp->author
                     << ", ISBN: " << temp->isbn << ", Availability: " 
                     << (temp->isAvailable ? "Available" : "Not Available") << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found.\n";
    }

    // Remove a book by ISBN
    void removeBook(string isbn) {
        if (!head) {
            cout << "Library is empty.\n";
            return;
        }
        if (head->isbn == isbn) {
            Book* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Book removed successfully.\n";
            return;
        }
        Book* temp = head;
        while (temp->next != nullptr && temp->next->isbn != isbn) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Book not found.\n";
        } else {
            Book* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Book removed successfully.\n";
        }
    }
};

int main() {
    Library library;
    int choice;
    string title, author, isbn;
    bool isAvailable;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book by ISBN\n";
        cout << "4. Remove Book by ISBN\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                cout << "Is the book available (1 for Yes, 0 for No): ";
                cin >> isAvailable;
                library.addBook(title, author, isbn, isAvailable);
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                cout << "Enter ISBN to search: ";
                cin >> isbn;
                library.searchBook(isbn);
                break;

            case 4:
                cout << "Enter ISBN to remove: ";
                cin >> isbn;
                library.removeBook(isbn);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
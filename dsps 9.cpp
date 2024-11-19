#include <iostream>
#include <string>

using namespace std;
struct Donor {
    int id;
    string name;
    double donationAmount;
    Donor* prev;
    Donor* next;

    Donor(int _id, string _name, double _donationAmount) 
        : id(_id), name(_name), donationAmount(_donationAmount), prev(nullptr), next(nullptr) {}
};

class CharityManagement {
private:
    Donor* head;
    Donor* tail;

public:
    CharityManagement() : head(nullptr), tail(nullptr) {}

    // Add a new donor
    void addDonor(int id, string name, double donationAmount) {
        Donor* newDonor = new Donor(id, name, donationAmount);
        if (!head) {
            head = tail = newDonor;
        } else {
            tail->next = newDonor;
            newDonor->prev = tail;
            tail = newDonor;
        }
        cout << "Donor added successfully!\n";
    }

    void removeDonor(int id) {
        Donor* current = head;

        while (current) {
            if (current->id == id) {
                if (current == head && current == tail) {
                    head = tail = nullptr;
                } else if (current == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Donor removed successfully!\n";
                return;
            }
            current = current->next;
        }
        cout << "Donor with ID " << id << " not found.\n";
    }

    void displayDonors() {
        if (!head) {
            cout << "No donors in the database.\n";
            return;
        }

        Donor* current = head;
        cout << "List of donors:\n";
        while (current) {
            cout << "ID: " << current->id << ", Name: " << current->name 
                 << ", Donation Amount: $" << current->donationAmount << '\n';
            current = current->next;
        }
    }

    ~CharityManagement() {
        Donor* current = head;
        while (current) {
            Donor* next = current->next;
            delete current;
            current = next;
        }
    }
};


int main() {
    CharityManagement cm;

    int choice, id;
    string name;
    double donationAmount;

    do {
        cout << "\n--- Charity Management System ---\n";
        cout << "1. Add Donor\n2. Remove Donor\n3. Display Donors\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Donor ID: ";
            cin >> id;
            cout << "Enter Donor Name: ";
            cin.ignore(); // Clear the newline character from input buffer
            getline(cin, name);
            cout << "Enter Donation Amount: ";
            cin >> donationAmount;
            cm.addDonor(id, name, donationAmount);
            break;
        case 2:
            cout << "Enter Donor ID to remove: ";
            cin >> id;
            cm.removeDonor(id);
            break;
        case 3:
            cm.displayDonors();
            break;
        case 4:
            cout << "Exiting system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

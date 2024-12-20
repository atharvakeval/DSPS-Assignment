#include <iostream>
#include <string>
using namespace std;
struct MusicTrack { //structure to hold information about a single  track
    string title;
    string artist;
    string album;
    string genre;
    int releaseYear;
    double duration; 
    MusicTrack* next;
};
class MusicLibrary {
private:
    MusicTrack* head; // Points to the first track

public:
    MusicLibrary() : head(nullptr) {}

    // Add a new track
    void addTrack(string title, string artist, string album, string genre, int year, double duration) {
        MusicTrack* newTrack = new MusicTrack{title, artist, album, genre, year, duration, nullptr};

        if (!head) {
            head = newTrack;
            head->next = head; // for the circular queue
        } else {
            MusicTrack* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newTrack;
            newTrack->next = head; 
        }
        cout << "Track added successfully!\n";
    }
    void searchTrack(string title) {
        if (!head) {
            cout << "Music library is empty.\n";
            return;
        }
        MusicTrack* temp = head;
        do {
            if (temp->title == title) {
                displayTrack(temp);
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Track not found.\n";
    }
    void updateTrack(string title) {
        if (!head) {
            cout << "Music library is empty.\n";
            return;
        }
        MusicTrack* temp = head;
        do {
            if (temp->title == title) {
                cout << "Enter new details:\n";
                cout << "Artist: "; cin >> temp->artist;
                cout << "Album: "; cin >> temp->album;
                cout << "Genre: "; cin >> temp->genre;
                cout << "Release Year: "; cin >> temp->releaseYear;
                cout << "Duration (minutes): "; cin >> temp->duration;
                cout << "Track updated successfully!\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Track not found.\n";
    }

    void removeTrack(string title) {
        if (!head) {
            cout << "Music library is empty.\n";
            return;
        }

        MusicTrack* temp = head;
        MusicTrack* prev = nullptr;

        do {
            if (temp->title == title) {
                if (temp == head && temp->next == head) { 
                    delete temp;
                    head = nullptr;
                } else {
                    if (temp == head) {
                        head = head->next;
                    }
                    if (prev) {
                        prev->next = temp->next;
                    }

                    MusicTrack* toDelete = temp;
                    delete toDelete;
                }
                cout << "Track removed successfully!\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Track not found.\n";
    }

    void displayAllTracks() {
        if (!head) {
            cout << "Music library is empty.\n";
            return;
        }

        MusicTrack* temp = head;
        cout << "Music Library Tracks:\n";
        do {
            displayTrack(temp);
            temp = temp->next;
        } while (temp != head);
    }

    void displayTrack(MusicTrack* track) {
        cout << "Title: " << track->title << "\n"
             << "Artist: " << track->artist << "\n"
             << "Album: " << track->album << "\n"
             << "Genre: " << track->genre << "\n"
             << "Release Year: " << track->releaseYear << "\n"
             << "Duration: " << track->duration << " minutes\n";
        cout << "----------------------------\n";
    }

    ~MusicLibrary() { // here used distructor for free memory
        if (!head) return;

        MusicTrack* temp = head;
        do {
            MusicTrack* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } while (temp != head);
    }
};

int main() {
    MusicLibrary library;
    int choice;
    string title, artist, album, genre;
    int year;
    double duration;

    do {
        cout << "\nMusic Library Menu:\n";
        cout << "1. Add Track\n";
        cout << "2. Search Track\n";
        cout << "3. Update Track\n";
        cout << "4. Remove Track\n";
        cout << "5. Display All Tracks\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter details:\n";
                cout << "Title: "; cin >> title;
                cout << "Artist: "; cin >> artist;
                cout << "Album: "; cin >> album;
                cout << "Genre: "; cin >> genre;
                cout << "Release Year: "; cin >> year;
                cout << "Duration (minutes): "; cin >> duration;
                library.addTrack(title, artist, album, genre, year, duration);
                break;
            case 2:
                cout << "Enter title to search: ";
                cin >> title;
                library.searchTrack(title);
                break;
            case 3:
                cout << "Enter title to update: ";
                cin >> title;
                library.updateTrack(title);
                break;
            case 4:
                cout << "Enter title to remove: ";
                cin >> title;
                library.removeTrack(title);
                break;
            case 5:
                library.displayAllTracks();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

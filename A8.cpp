#include <iostream>
using namespace std;

struct Node {
    bool isBooked;
    Node* next;
    Node* prev;
};

Node* initializeRow(int seats) {
    Node* head = nullptr;
    Node* prev = nullptr;

    for (int i = 1; i <= seats; ++i) {
        Node* newNode = new Node{false, nullptr, nullptr};
        if (!head) {
            head = newNode;
        } else {
            prev->next = newNode;
            newNode->prev = prev;
        }
        prev = newNode;
    }

    if (head && prev) {
        head->prev = prev;
        prev->next = head;
    }

    return head;
}

void displayAvailableSeats(Node* head) {
    Node* current = head;
    do {
        if (!current->isBooked) {
            cout << "O "; // O for available seat
        } else {
            cout << "X "; // X for booked seat
        }
        current = current->next;
    } while (current != head);
    cout << endl;
}

void bookSeat(Node*& head, int seatNumber) {
    Node* current = head;
    for (int i = 1; i < seatNumber; ++i) {
        current = current->next;
    }

    if (!current->isBooked) {
        current->isBooked = true;
        cout << "Seat booked successfully." << endl;
    } else {
        cout << "Seat is already booked." << endl;
    }
}

void cancelBooking(Node*& head, int seatNumber) {
    Node* current = head;
    for (int i = 1; i < seatNumber; ++i) {
        current = current->next;
    }

    if (current->isBooked) {
        current->isBooked = false;
        cout << "Booking canceled successfully." << endl;
    } else {
        cout << "Seat is not booked." << endl;
    }
}

int main() {
    const int rows = 10;
    const int seatsPerRow = 7;
    Node* rowPointers[rows];

    for (int i = 0; i < rows; ++i) {
        rowPointers[i] = initializeRow(seatsPerRow);
    }

    int option;
    int row, seat;

    do {
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel booking\n";
        cout << "0. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter row number: ";
                cin >> row;
                displayAvailableSeats(rowPointers[row - 1]);
                break;
            case 2:
                cout << "Enter row number: ";
                cin >> row;
                cout << "Enter seat number: ";
                cin >> seat;
                bookSeat(rowPointers[row - 1], seat);
                break;
            case 3:
                cout << "Enter row number: ";
                cin >> row;
                cout << "Enter seat number: ";
                cin >> seat;
                cancelBooking(rowPointers[row - 1], seat);
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (option != 0);

    return 0;
}
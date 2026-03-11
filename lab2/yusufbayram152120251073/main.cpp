#include <iostream>
#include <string>

using namespace std;


struct Node
{
    string data;
    Node* next;
};


void addWord(Node*& head, string word)
{
    Node* newNode = new Node();
    newNode->data = word;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void undo(Node*& head) {

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }


    Node* temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}


void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    string input;

    cout << "Enter any words or UNDO/undo or EXIT/exit)" << endl;


    while (true) {
        cout << "> ";
        cin >> input;

        if (input == "EXIT" ||input == "exit") {
            break;
        } else if (input == "UNDO" || input == "undo") {
            undo(head);
        } else {
            addWord(head, input);
        }

        display(head);
    }

    return 0;
}

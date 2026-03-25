#include <iostream>
#include <string>

using namespace std;

struct Song
{
    string title;
    string artist;
    int ratings[3];
    Song* next;
    Song* prev;

    Song(string t, string a, int r1, int r2, int r3)
    {
        title = t;
        artist = a;
        ratings[0] = r1;
        ratings[1] = r2;
        ratings[2] = r3;
        next = nullptr;
        prev = nullptr;
    }
};

    Song* start = nullptr;
    Song* last = nullptr;
    Song* current = nullptr;

void addSong(string t, string a, int r1, int r2, int r3)
{
    Song* newSong = new Song(t, a, r1, r2, r3);
    if (start == nullptr)
    {
        start = last = current = newSong;
    }
    else
    {
        last->next = newSong;
        newSong->prev = last;
        last = newSong;
    }
}

void nextSong()
{
    if (current != nullptr && current->next != nullptr)
    {
        current = current->next;
    }
    else
    {
        cout << "Error Next song isnt available." << endl;
    }
}

void prevSong()
{
    if (current != nullptr && current->prev != nullptr)
    {
        current = current->prev;
    }
    else
    {
        cout << "Error previous song isnt available." << endl;
    }
}

void removeCurrent()
{
    if (current == nullptr)
    {
        cout << "Error, you dont have a song in current" << endl;
        return;
    }

    Song* toDelete = current;

    if (toDelete->prev != nullptr)
    {
        toDelete->prev->next = toDelete->next;
    }
    else
    {
        start = toDelete->next;
    }

    if (toDelete->next != nullptr)
    {
        toDelete->next->prev = toDelete->prev;
    }
    else
    {
        last = toDelete->prev;
    }

    if (toDelete->next != nullptr)
    {
        current = toDelete->next;
    }
    else
    {
        current = start;
    }
}

void display() {
    Song* temp = start;
    while (temp != nullptr)
    {
        if (temp == current) cout << "-> ";

        cout << temp->title << " - " << temp->artist << " [";

        for (int i = 0; i < 3; i++)
        {
            cout << temp->ratings[i] << ", ";
        }

        cout << "]" << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice = 0;
    string t, a;
    int r1, r2, r3;

    while (choice != 5)
    {
        display();
        cout << "1. Add Song" << endl;
        cout << "2. Next Song" << endl;
        cout << "3. Previous Song" << endl;
        cout << "4. Remove Current" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Title: ";
            cin.ignore();
            getline(cin, t);
            cout << "Enter Artist: ";
            getline(cin, a);
            cout << "Enter 3 Ratings (separated by space): ";
            cin >> r1 >> r2 >> r3;
            addSong(t, a, r1, r2, r3);
            break;
        case 2:
            nextSong();
            break;
        case 3:
            prevSong();
            break;
        case 4:
            removeCurrent();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}


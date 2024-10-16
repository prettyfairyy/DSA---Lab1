#include <iostream>
using namespace std;

class Node{
    public:
        string song;
        Node* next;
        Node* prev;
        Node(string str){
            song = str;
            next = nullptr;
            prev = nullptr;
        }
};

class PlayList{
    public:
        Node* head;
        Node* current;
        PlayList(){
            head = nullptr;
            current = nullptr;
        }
        void addSong(string);
        Node *playNext();
        Node *playPrev();
        void removeSong(string);
        void display();
};

void PlayList::addSong(string str){
    Node* newNode = new Node(str);
    if (head == nullptr){
        head = newNode;
        current = head;
    } else{
        Node* t = head;
        while (t->next != nullptr){
            t = t->next;
        }
        newNode->prev = t;
        t->next = newNode;
    }
}

Node *PlayList::playNext(){
    if (current == nullptr || current->next == nullptr)
        return current;
    current = current->next;
    return current;
}

Node *PlayList::playPrev(){
    if (current == nullptr || current->prev == nullptr)
        return current;
    current = current->prev;
    return current;
}

void PlayList::removeSong(string str){
    Node* t = head;
    if (!t) return;

    // If the song to remove is at the head
    if (head->song == str) {
        Node* toDelete = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete toDelete;
        if (current == toDelete) current = head;
        return;
    }

    while (t != nullptr && t->song != str) {
        t = t->next;
    }

    if (t == nullptr) return; // Song not found

    // Remove the song
    if (t->next) t->next->prev = t->prev;
    if (t->prev) t->prev->next = t->next;

    if (current == t) current = t->next ? t->next : t->prev;

    delete t;
}

void PlayList::display(){
    Node* temp = head;
    while (temp != nullptr){
        cout << temp->song << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    PlayList pl;
    int n;
    cout << "Number of operations: ";
    cin >> n;
    string command;
    string song;
    for (int i = 0; i < n; i++){
        cin >> command;
        if (command == "ADD"){
            cin >> song;
            pl.addSong(song);
            cout << song << " added to the playlist." << endl;
        }
        else if (command == "NEXT"){
            Node* nextSong = pl.playNext();
            if (nextSong)
                cout << "Now playing: " << nextSong->song << endl;
            else
                cout << "End of playlist, can't move to the next song." << endl;
        }
        else if (command == "PREV"){
            Node* prevSong = pl.playPrev();
            if (prevSong)
                cout << "Now playing: " << prevSong->song << endl;
            else
                cout << "Start of playlist, can't move to the previous song." << endl;
        }
        else if (command == "REMOVE"){
            cin >> song;
            pl.removeSong(song);
            cout << song << " removed from the playlist." << endl;
        }
        else if (command == "DISPLAY"){
            cout << "Playlist: ";
            pl.display();
        }
    }
    return 0; 
}

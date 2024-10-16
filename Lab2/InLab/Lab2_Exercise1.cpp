// StudentID: 22520836
// Full Name: Ngo Thi Hong Ly
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;  
    int size;   
    int capacity; 

public:
    // Function to view the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    // Exercise 1: Constructor to initialize the stack
    Stack(int cap) {
        top = nullptr;
        size = 0;
        capacity = cap;
    }

    // Exercise 2: Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Exercise 3: Function to check if the stack is full
    bool isFull() {
        return size == capacity;
    }

    // Exercise 4: Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full! Cannot push more elements.\n";
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        size++;
        cout << value << " pushed onto the stack.\n";
    }

    // Exercise 5: Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop elements.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from the stack.\n";
        delete temp;
        size--;
    }

    // Exercise 6: Function to print the top element
    void printTop() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element to print.\n";
        } else {
            cout << "Top element is: " << top->data << endl;
        }
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    int capacity;
    cout << "Enter the stack capacity: ";
    cin >> capacity;

    Stack stack(capacity);

    int choice, value;

    do {
        cout << "\nStack Operations:\n";
        cout << "4. Push an element\n";
        cout << "5. Pop an element\n";
        cout << "6. Print the TOP element\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 4:
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 5:
                stack.pop();
                break;
            case 6:
                stack.printTop();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please choose between 4 to 7.\n";
                break;
        }
    } while (choice != 7);  

    return 0;
}

//STT: 22520836
//Full Name: Ngo Thi Hong Ly

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* random;
        Node (int x){
            data = x;
            next = nullptr;
            random = nullptr;
        }
};

class LinkedList{
    public:
        Node* head;
        LinkedList() : head(nullptr){};
        void addNode(int);
        void makeList();
        void print();
        void checkMiddle();
        void detectCycle();
        LinkedList combine(LinkedList& list2);
        int intersection(LinkedList& list2);
        LinkedList reverse();
        void removeDup();
        void palindrome();
        Node** search(int&);
        void addTwo(Node*&,Node*&);
        LinkedList randomPoint();
        void swap();
        void removefrEnd();
        void seperate();
        void devidePart();
        void removeZeroSum();
        void automaticInput();
};

void LinkedList::addNode(int x){
    Node* temp = new Node(x);
    if (head == nullptr) head = temp;
    else{
        Node* t = head;
        while (t->next != nullptr)
            t = t->next;
        t->next = temp;
    }
}

void LinkedList::makeList(){
    cout << "Enter the list and end up with 0: ";
    int x;
    while (true){
        cin >> x;
        if (x == 0) break;
        addNode(x);
    }
}

void LinkedList::print(){
    Node* t = head;
    while (t != nullptr){
        cout << t->data << " ";
        t = t->next;
    }
}

//Part 01 - Exercise 01: Find the Middle Node of a Linked List
void LinkedList::checkMiddle(){
    Node* t = head;
    int s = 0;
    while (t != nullptr){
        s += 1;  
        t = t->next;
    }
    Node* p = head;
    if (s % 2 == 0){
        for (int i = 0; i < s/2 - 1; i++){
            p = p->next;
        }
        cout << p->data << " " << p->next->data;
    }
    else{
        for (int i = 0; i < s/2; i++){
            p = p->next;
        }
        cout << "The middle node: " << p->data;
    }
}

//Part 01 - Exercise 02: Detect a Cycle in a Linked List
void LinkedList::detectCycle() {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout << "Cycle in LinkedList";
            return;
        }
    }
    cout << "No Cycle in LinkedList";
}

//Part 01 - Exercise 03: Combine Two Sorted Linked List
LinkedList LinkedList::combine(LinkedList& list2){
    LinkedList newList;
    Node* n = new Node(0);
    Node* current = n;
    Node* l1 = head;
    Node* l2 = list2.head;

    while (l1 != nullptr && l2 != nullptr){
        if (l1->data <= l2->data){
            current->next = l1;
            l1 = l1->next;
        }
        else 
        {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    if (l1 != nullptr) current->next = l1;
    if (l2 != nullptr) current->next = l2;

    newList.head = n->next;
    delete n;

    return newList;
}

//Part 01 - Exercise 04: Find the Intersection of Two Linked Lists
int LinkedList::intersection(LinkedList& list2) {
    Node* l1 = head;
    Node* l2 = list2.head;

    while (l1 != nullptr) {
        l2 = list2.head;  
        while (l2 != nullptr) {
            if (l1->data == l2->data) {
                return l1->data;  
            }
            l2 = l2->next;
        }
        l1 = l1->next;
    }
    return -1;  
}


//Part 01 - Exercise 05: Reverse a Linked List
LinkedList LinkedList::reverse() {
    Node* t = nullptr;
    Node* newHead = nullptr;
    while (head){
        t = head;
        head = head->next;
        t->next = newHead;
        newHead = t;
    }
    head = newHead;
    return *this;
}

//Part 01 - Exercise 06: Eliminate Duplicates from a Sorted Linked List
void LinkedList::removeDup(){
    Node* t = head;
    Node* a = t->next;
    Node* temp;
    while (t->next != nullptr){
        Node* a = t->next;
        if (t->data == a->data){
            temp = a;
            a = a->next;
            t->next = a;
            delete(temp);
        }
        t = t->next;
    }
} 

//Part 01 - Exercise 07: Check if a Linked List is a Palindrome
void LinkedList::palindrome(){
    if (!head) return;

    Node* fast = head;
    Node* slow = head;
    Node* prev = nullptr;
    Node* temp = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    if (fast != nullptr) slow = slow->next;

    while (slow != nullptr) {
        if (slow->data != prev->data) {
            cout << "Not a Palindrome" << endl;
            return;
        }
        slow = slow->next;
        prev = prev->next;
    }
    cout << "Linked List is a Palindrome" << endl;
}

/*Part 01 - Exercise 08: Write a function to search for nodes with the value X in the list. 
            If found, return the addresses of the nodes; if not found, return NULL. */

Node** LinkedList::search(int &c){
    cout << "Enter the value X: ";
    int x;
    cin >> x;
    Node* t = head;
    c = 0;
    while (t != nullptr){
        if (t->data == x) c++;
        t = t->next;
    }
    if (c == 0) return nullptr;

    Node** result = new Node*[c];
    t = head;
    int i = 0;
    while (t != nullptr){
        if (t->data == x)   result[i++] = t;
        t = t->next;
    }
    return result;
}


//Part 02 - Exercise 01: Add Two Numbers
void LinkedList::addTwo(Node* &n1, Node* &n2) {
    int x;
    cout << "Enter the first new number: ";
    cin >> x;
    n1 = new Node(x);

    cout << "Enter the second new number: ";
    cin >> x;
    n2 = new Node(x);

    if (head == nullptr) {
        head = n1;
        n1->next = n2;
    } else {
        Node* t = head;
        while (t->next != nullptr) {
            t = t->next;
        }
        t->next = n1;
        n1->next = n2;
    }
}


//Part 02 - Exercise 02: Copy List with Random Pointers
LinkedList LinkedList::randomPoint() {
    if (head == nullptr) return LinkedList();
    Node* current = head;
    while (current) {
        Node* newNode = new Node(current->data);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }

    current = head;
    while (current) {
        if (current->random) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    LinkedList newList;
    current = head;
    Node* copyHead = head->next;
    Node* copyCurrent = copyHead;

    while (current) {
        current->next = copyCurrent->next; 
        current = current->next;

        if (current) {
            copyCurrent->next = current->next; 
            copyCurrent = copyCurrent->next;
        }
    }

    newList.head = copyHead; 
    return newList;
}

//Part 02 - Exercise 03: Swap Nodes in a Linked List
void LinkedList::swap(){
    cout << "Enter two position need to be swapped (p1 < p2): ";
    int p1,p2;
    cin >> p1 >> p2;
    Node* t = head;
    Node* a = head;
    Node* b = head;
    Node* prva = nullptr;
    Node* prvb = nullptr;
    for (int i = 0; i < p1; i++){
        prva = a;
        a = a->next;
    }
    for (int i = 0; i < p2; i++){
        prvb = b;
        b = b->next;
    }
    prva->next = b;
    prvb->next = a;
    Node *temp = a->next;
    a->next = b->next;
    b->next = temp;
}


//Part 02 - Exercise 04: Remove the N-th Node from the End of a List
void LinkedList::removefrEnd(){
    cout << "Enter the position from the End of list need to be removed: ";
    int p;
    cin >> p;
    int c = 0;
    Node* t = head;
    Node* temp;
    while (t){
        t = t->next;
        c++;
    }
    if (p > c || p == 0){
        cout << "No node removed.";
        return;
    }
    t = head;
    if (p == c){
        head = head->next;
        delete(t);
        return;
    }
    for (int i = 0; i < c-p-1; i++){
        t = t->next;
    }
    temp = t->next;
    t->next = t->next->next;
    delete(temp);
}

//Part 02 - Exercise 05: Separate Odd and Even Nodes in a Linked List
void LinkedList::seperate(){
    Node* t = head;
    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;
    while (t){
        if (t->data % 2 == 0){
            if (evenHead == nullptr){
                evenHead = t;
                evenTail = evenHead;
            }
            else{
                evenTail->next = t;
                evenTail = evenTail->next;
            }
        }
        else {
            if (oddHead == nullptr){
                oddHead = t;
                oddTail = oddHead;
            }
            else{
                oddTail->next = t;
                oddTail = oddTail->next;
            }
        }
    t = t->next;
    }
    if (evenHead == nullptr) {
        head = oddHead;
    } else {
        head = evenHead;
        evenTail->next = oddHead;
    }
    if (oddTail != nullptr) {
        oddTail->next = nullptr;
    }
}

//Part 02 - Exercise 06: Divide a Linked List into Parts
void LinkedList::devidePart(){
    int k;
    cout << "Enter number of parts need to be devide: ";
    cin >> k;

    Node* t = head;
    int c = 0;
    while (t){
        t = t->next;
        c++;
    }

    int num = c / k;
    int r = c % k;

    if (k <= 0)  return;

    Node** arr = new Node*[k];
    t = head;
    for (int i = 0; i < k; i++) {
        arr[i] = t; 
        int part_size = num + (i < r ? 1 : 0);
    
        for (int j = 0; j < part_size - 1; j++) {
            if (t) t = t->next;
        }
        
        if (t) {
            Node* nextPart = t->next; 
            t->next = nullptr;        
            t = nextPart;             
        }
    }
    for (int i = 0; i < k; i++){
        cout << "Part " << i+1 << ": ";
        while (arr[i]){
            cout << arr[i]->data << " ";
            arr[i] = arr[i]->next;
        }
        cout << endl;
    }
    delete[] arr;
}

//Part 02 - Exercise 07: Remove Zero-Sum Consecutive Nodes from a Linked List
void LinkedList::removeZeroSum() {
    Node* dummy = new Node(0);  
    dummy->next = head;
    Node* current = dummy;       
    while (current) {
        Node* runner = current->next; 
        int sum = 0;
        while (runner) {
            sum += runner->data;
            if (sum == 0) {
                Node* temp = current->next;
                while (temp != runner) {
                    Node* toDelete = temp;
                    temp = temp->next;
                    delete toDelete; 
                }
                current->next = runner->next; 
                break; 
            }
            runner = runner->next;
        }
        if (runner == nullptr) {
            current = current->next;
        }
    }

    head = dummy->next; 
    delete dummy; 
}

/*Part 02 - Exercise 08: Write a function to input values for a list using the 
            automatic input method, with values selected from the range [-99; 99].
            The number of entries is randomly chosen from the range [39; 59] 
            (using a function to insert at the end of the list).*/
void LinkedList::automaticInput(){
    int numberOfEntries = 39 + rand() % 21; 
    for (int i = 0; i < numberOfEntries; i++) {
        int randomValue = -99 + rand() % 199; 
        addNode(randomValue);
    }
}

int main(){
    LinkedList l;
    l.makeList();
    int p,e;
    cout << "Enter the order of part p and excersise e: ";
    cin >> p >> e;
    switch (p)
    {
        case 1:
            switch (e)
            {
                case 1: 
                    l.checkMiddle();
                    break;
                case 2:
                    l.detectCycle();
                    break;
                case 3:{
                    LinkedList l2;
                    l2.makeList();
                    l.combine(l2).print();
                    break;
                }
                case 4:{
                    LinkedList l2;
                    l2.makeList();
                    int result = l.intersection(l2);
                    if (result != -1) {
                        cout << "Intersection of 2 linked list: " << l.intersection(l2);
                    } 
                    else {
                        cout << "No intersection in 2 linked list \n";
                    } 
                    break;
                }
                case 5:
                    l.reverse().print();
                    break;
                case 6:
                    l.removeDup();
                    l.print();
                    break;
                case 7:
                    l.palindrome();
                    break;
                case 8:
                    int c = 0;
                    Node** result = l.search(c);
                    if (result != nullptr){
                        cout <<"Nodes are equal to X: ";
                        for (int i = 0; i < c; i++){
                            cout << result[i] << " ";
                        }
                    }
                    else cout <<"No nodes found";
                    break;
            }
            break;
            
        case 2: 
            switch(e)
            {
                case 1: 
                    Node* n1,* n2;
                    l.addTwo(n1,n2);
                    l.print();
                    break;
                case 2:
                    l.randomPoint().print();
                    break;
                case 3:
                    l.swap();
                    l.print();
                    break;
                case 4:
                    l.removefrEnd();
                    l.print();
                    break;
                case 5:
                    l.seperate();
                    l.print();
                    break;
                case 6:
                    l.devidePart();
                    break;
                case 7:
                    l.removeZeroSum();
                    l.print();
                    break;
                case 8:
                    l.automaticInput();
                    l.print();
                    break;
            }

    }
    
    return 0;
}




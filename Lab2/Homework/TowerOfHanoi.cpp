//STT: 22520836
//Full Name: Ngo Thi Hong Ly

#include <iostream>
using namespace std;

const int MAX_DISKS = 100;

class Tower {
private:
    int disks[MAX_DISKS]; // Mảng cố định để lưu đĩa
    int top;

public:
    Tower() : top(-1) {} // Khởi tạo top là -1

    void push(int disk) {
        if (top < MAX_DISKS - 1) {
            disks[++top] = disk;
        }
    }

    int pop() {
        if (top >= 0) {
            return disks[top--];
        }
        return -1; // Trả về -1 nếu tháp rỗng
    }

    void print() {
        if (top == -1) {
            cout << "|";
        } else {
            for (int i = top; i >= 0; --i) {
                cout << disks[i] << " ";
            }
        }
        cout << endl;
    }
};

// Hàm in trạng thái của ba tháp
void printTowers(Tower& A, Tower& B, Tower& C) {
    cout << "Tower A: ";
    A.print();
    cout << "Tower B: ";
    B.print();
    cout << "Tower C: ";
    C.print();
    cout << "------------------" << endl;
}

// Hàm đệ quy di chuyển đĩa
void moveDisks(int n, Tower& source, Tower& destination, Tower& auxiliary, char src, char dest, char aux, Tower& A, Tower& B, Tower& C) {
    if (n == 1) {
        destination.push(source.pop());
        cout << "Move disk 1 from " << src << " to " << dest << endl;
        printTowers(A, B, C); // In trạng thái sau khi di chuyển
        return;
    }
    moveDisks(n - 1, source, auxiliary, destination, src, aux, dest, A, B, C);
    destination.push(source.pop());
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    printTowers(A, B, C); // In trạng thái sau khi di chuyển
    moveDisks(n - 1, auxiliary, destination, source, aux, dest, src, A, B, C);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    if (n > MAX_DISKS) {
        cout << "Number of disks exceeds the limit of " << MAX_DISKS << endl;
        return 1;
    }

    Tower A, B, C;

    // Khởi tạo tháp A với các đĩa theo thứ tự giảm dần
    for (int i = n; i > 0; --i)
        A.push(i);

    // In trạng thái ban đầu của ba tháp
    cout << "Initial status:" << endl;
    printTowers(A, B, C);

    // Di chuyển đĩa từ tháp A sang tháp C với B làm trung gian
    moveDisks(n, A, C, B, 'A', 'C', 'B', A, B, C);

    // In trạng thái sau khi hoàn thành
    cout << "Finished status:" << endl;
    printTowers(A, B, C);

    return 0;
}

#include <iostream>
#include <cstring> // for strcpy
using namespace std;

const int MAX_HISTORY = 100;

class BrowserHistory {
private:
    char history[MAX_HISTORY][100]; // Mảng để lưu trữ lịch sử các URL
    int backStack[MAX_HISTORY]; // Mảng cho stack back
    int forwardStack[MAX_HISTORY]; // Mảng cho stack forward
    int backTop; // Đỉnh của stack back
    int forwardTop; // Đỉnh của stack forward
    int currentIndex; // Chỉ số trang hiện tại

public:
    BrowserHistory(const char* homepage) {
        strcpy(history[0], homepage); // Lưu trang chủ vào vị trí đầu tiên
        currentIndex = 0;
        backTop = -1; // Stack back rỗng
        forwardTop = -1; // Stack forward rỗng
    }

    void visit(const char* url) {
        // Lưu trang hiện tại vào stack back
        backStack[++backTop] = currentIndex;

        // Cập nhật lịch sử mới
        currentIndex++;
        strcpy(history[currentIndex], url);

        // Xóa stack forward khi có URL mới
        forwardTop = -1; 
    }

    const char* back() {
        if (backTop >= 0) {
            forwardStack[++forwardTop] = currentIndex; // Lưu trang hiện tại vào stack forward
            currentIndex = backStack[backTop--]; // Quay lại trang trước
            return history[currentIndex];
        }
        return history[currentIndex]; // Đã ở trang đầu tiên, không thể back thêm
    }

    const char* forward() {
        if (forwardTop >= 0) {
            backStack[++backTop] = currentIndex; // Lưu trang hiện tại vào stack back
            currentIndex = forwardStack[forwardTop--]; // Tiến tới trang tiếp theo
            return history[currentIndex];
        }
        return history[currentIndex]; // Đã ở trang cuối cùng, không thể forward thêm
    }

    void printCurrent() {
        cout << "Current page: " << history[currentIndex] << endl;
    }
};

int main() {
    // Khởi tạo lịch sử với trang chủ
    BrowserHistory browser("home.com");
    
    char url[100];
    char command[10];

    while (true) {
        cout << "Enter command (visit/back/forward/exit): ";
        cin >> command;

        if (strcmp(command, "visit") == 0) {
            cout << "Enter URL: ";
            cin >> url;
            browser.visit(url);
            browser.printCurrent();
        } 
        else if (strcmp(command, "back") == 0) {
            cout << "Back to: " << browser.back() << endl;
            browser.printCurrent();
        } 
        else if (strcmp(command, "forward") == 0) {
            cout << "Forward to: " << browser.forward() << endl;
            browser.printCurrent();
        } 
        else if (strcmp(command, "exit") == 0) {
            break; // Thoát khỏi vòng lặp
        } 
        else {
            cout << "Invalid command. Please enter visit, back, forward, or exit." << endl;
        }
    }

    return 0;
}

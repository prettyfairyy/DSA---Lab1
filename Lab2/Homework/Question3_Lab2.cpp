//STT: 22520836
//Full Name: Ngo Thi Hong Ly

#include <iostream>
#include <stack>
using namespace std;

const int MAX_N = 100; // Giới hạn số người

void peopleVisible(int heights[], int n, int result[]) {
    stack<int> s; // Stack để lưu trữ chỉ số người

    // Duyệt từ phải sang trái
    for (int i = n - 1; i >= 0; --i) {
        // Khởi tạo số lượng người có thể nhìn thấy
        result[i] = 0;

        // Kiểm tra những người nằm giữa
        while (!s.empty() && heights[s.top()] < heights[i]) {
            result[i]++; // Người hiện tại có thể nhìn thấy người ở đỉnh stack
            s.pop(); // Loại bỏ người không còn nhìn thấy
        }

        // Thêm chỉ số của người hiện tại vào stack
        s.push(i);
    }
}

int main() {
    int heights[MAX_N];
    int n;

    cout << "Enter the number of people: ";
    cin >> n;

    cout << "Enter the heights of the people: ";
    for (int i = 0; i < n; ++i) {
        cin >> heights[i]; // Nhập chiều cao từng người
    }

    int result[MAX_N] = {0}; // Mảng kết quả khởi tạo bằng 0

    // Gọi hàm để tính số lượng người có thể nhìn thấy
    peopleVisible(heights, n, result);

    // In kết quả
    cout << "Output: [";
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

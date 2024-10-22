#include <iostream>
using namespace std;
int Ackerman(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (m > 0 && n == 0) {
        return Ackerman(m - 1, 1);
    }
    else {
        return Ackerman(m - 1, Ackerman(m, n - 1));
    }
}
int main() {
    int m, n;
    cout << "請輸入兩個正整數 m 和 n: ";
    cin >> m >> n;
    cout << "Ackerman(" << m << ", " << n << ") = " << Ackerman(m, n) << endl;//依每次輸入，輸出Ackermanc函數
    return 0;
}
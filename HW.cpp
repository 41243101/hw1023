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
    cout << "�п�J��ӥ���� m �M n: ";
    cin >> m >> n;
    cout << "Ackerman(" << m << ", " << n << ") = " << Ackerman(m, n) << endl;//�̨C����J�A��XAckermanc���
    return 0;
}
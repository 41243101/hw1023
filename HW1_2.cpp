#include <iostream>
#include <stack>
using namespace std;

int Ackerman(int m, int n) {
    stack<pair<int, int>> stk; // �ϥΰ��|�Ӽ������j
    stk.push({ m, n }); // �N��J�� m �M n ���J���|
    int result = 0; //�x�s�M�l�ܷ�e���J�Ҩ�ƪ����G

    while (!stk.empty()) {
        auto cur = stk.top(); // ���o�ثe��(m, n)
        stk.pop(); // �������ݤ���
        m = cur.first; // ���� m
        n = cur.second; // ���� n

        if (m == 0) {
            result = n + 1; // Ackerman(0, n) = n + 1
        }
        else if (m == 1) {
            result = n + 2; // Ackerman(1, n) = n + 2
        }
        else if (m == 2) {
            result = 2 * n + 3; // Ackerman(2, n) = 2n + 3
        }
        else if (m == 3){
            result = 5; //Ackerman(3,0)=5
            for (int i = 1; i <= n; i++) {
                    result = 2*result +3; 
            }
        }
        else {
            stk.push({ m - 1, result }); // �N�ݭn�B�z�� (m-1, result) ���J���|�A�ھڪ��J�Ҩ�ƪ��w�q�A�p��Ackerman(??,??)�A �|�̿�� Ackerman(???1,??(??,???1))
            stk.push({ m, n - 1 }); // �p�� Ackerman(m, n-1)�A�ھڪ��J�Ҩ�ƪ��w�q�A�o�O�Ĥ@�B�����i�檺�p��
            continue; // �~��B�z���|
        }
    }
    return result;
}
int main() {
    int m, n;
    cout << "�п�J��ӥ���� m �M n: ";
    cin >> m >> n;
    cout << "Ackerman(" << m << ", " << n << ") = " << Ackerman(m, n) << endl;
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

int Ackerman(int m, int n) {
    stack<pair<int, int>> stk; // 使用堆疊來模擬遞迴
    stk.push({ m, n }); // 將輸入的 m 和 n 推入堆疊
    int result = 0; //儲存和追蹤當前阿克曼函數的結果

    while (!stk.empty()) {
        auto cur = stk.top(); // 取得目前的(m, n)
        stk.pop(); // 移除頂端元素
        m = cur.first; // 提取 m
        n = cur.second; // 提取 n

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
            stk.push({ m - 1, result }); // 將需要處理的 (m-1, result) 推入堆疊，根據阿克曼函數的定義，計算Ackerman(??,??)， 會依賴於 Ackerman(???1,??(??,???1))
            stk.push({ m, n - 1 }); // 計算 Ackerman(m, n-1)，根據阿克曼函數的定義，這是第一步必須進行的計算
            continue; // 繼續處理堆疊
        }
    }
    return result;
}
int main() {
    int m, n;
    cout << "請輸入兩個正整數 m 和 n: ";
    cin >> m >> n;
    cout << "Ackerman(" << m << ", " << n << ") = " << Ackerman(m, n) << endl;
    return 0;
}
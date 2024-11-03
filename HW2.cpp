#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 10;  // 假設集合最多有10個元素

// 用來印出幂集 P(S)(集合S可能的子集組合)
void printSubset(const string subset[], int subsetSize) 
{
    cout << "{ ";
    for (int i = 0; i < subsetSize; ++i) 
    {
        cout << subset[i] <<" ";
    }
    cout << "}" << endl;
}

// 計算幂集的遞迴函數
void countpowerset(string S[], int size, int index, string currentSubset[], int currentSubsetSize) //index是目前處理到的元素位置
{
    // 當 startindex 到達集合 S 的結尾，輸出當前子集
    if (index == size) 
    {
        printSubset(currentSubset, currentSubsetSize);
        return;
    }

    //「不包含」當前元素，直接遞迴進到下一層，處理下一個元素
    countpowerset(S, size, index + 1, currentSubset, currentSubsetSize);

    //「包含」當前元素，生成包含當前元素的子集並處理下一個元素
    currentSubset[currentSubsetSize] = S[index];
    countpowerset(S, size, index + 1, currentSubset, currentSubsetSize + 1);
}

int main() {
    int n;
    cout << "請輸入集合的元素個數 (最多" << MAX_SIZE <<"個): ";
    cin >> n;

    if (n < 0 || n > MAX_SIZE)
    {
        cout << "元素個數必須在 0 到 " << MAX_SIZE << " 之間！" << endl;//包含0
        return 0;
    }

    string S[MAX_SIZE];  // 儲存輸入元素之集合
    string currentSubset[MAX_SIZE];  // 儲存子集的靜態陣列
    cout << "請輸入集合的元素: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> S[i];
    }

    cout << "幂集powerset(S)=" << endl;
    countpowerset(S, n, 0, currentSubset, 0);
    return 0;
}
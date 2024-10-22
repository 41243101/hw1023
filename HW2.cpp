#include <iostream>
#include <sstream>  // 用於 stringstream
#include <string>   // 支援字串處理
using namespace std;

const int MAX_SIZE = 10;

template <typename T>
string my_to_string(T value) {
    ostringstream oss;
    oss << value;
    return oss.str();
}

void generatePowerSet(string set[], int size, int index, string subset[], int subsetSize) {
    if (index == size) {
        cout << "{ ";
        for (int i = 0; i < subsetSize; ++i) {
            cout << subset[i] << " ";
        }
        cout << "}" << endl;
        return;
    }

    generatePowerSet(set, size, index + 1, subset, subsetSize);
    subset[subsetSize] = set[index];
    generatePowerSet(set, size, index + 1, subset, subsetSize + 1);
}

string getStringInput(const string& prompt) {
    string value;
    cout << prompt;
    cin >> value;
    return value;
}

int main() {
    int n;
    cout << "請輸入集合的元素個數 (最多 10 個): ";
    cin >> n;
    if (n < 0 || n > MAX_SIZE) {
        cout << "元素個數必須在 0 到 " << MAX_SIZE << " 之間！" << endl;
        return 1;
    }

    string set[MAX_SIZE];
    for (int i = 0; i < n; ++i) {
        string elementString = my_to_string(i + 1);
        set[i] = getStringInput("元素" + elementString + ": ");
    }

    string subset[MAX_SIZE];
    cout << "幂集為：" << endl;
    generatePowerSet(set, n, 0, subset, 0);

    return 0;
}

#include <iostream>
#include <set>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    set<int> group;
    int num;

    cout << "Введите число: ";
    cin >> num;

    while ( cin >> num) {
        if (group.find(num) == group.end()) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
        group.insert(num);
    }
    return 0;
}
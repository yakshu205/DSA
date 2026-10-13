#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> shelf[10];
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book codes: ";
    for (int i = 0; i < n; i++) {
        cin >> code;

        int index = code % 10;
        shelf[index].push_back(code);
    }

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";
        for (int j = 0; j < shelf[i].size(); j++) {
            cout << shelf[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
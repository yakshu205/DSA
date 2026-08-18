#include <iostream>
using namespace std;

int main() {
    int n, h;

    cout << "Enter number of items: ";
    cin >> n;

    int arr[100];

    cout << "Enter the items: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of hours: ";
    cin >> h;

    h = h % n;   

    cout << "Final display order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[(i + h) % n] << " ";
    }

    return 0;
}
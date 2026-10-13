#include <iostream>
using namespace std;

int main()
{
    int parking[10];

    for (int i = 0; i < 10; i++)
    {
        parking[i] = -1;
    }

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int reg;
        cout << "\n enter youe registration number : ";
        cin >> reg;

        int slot = reg % 10;

        int start = slot;

        while (parking[slot] != -1)
        {
            slot = (slot + 1) % 10;

            if (slot == start)
            {
                cout << "Parking lot is full!" << endl;
                break;
            }
        }

        if (parking[slot] == -1)
        {
            parking[slot] = reg;
        }
    }
    cout << "\nFinal Parking State:\n";

    for(int i = 0; i < 10; i++)
    {
        cout << "Slot " << i << " : ";

        if(parking[i] == -1)
            cout << "Empty";
        else
            cout << parking[i];

        cout << endl;
    }

    return 0;
} 
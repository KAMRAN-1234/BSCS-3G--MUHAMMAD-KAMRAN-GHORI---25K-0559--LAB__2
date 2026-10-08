#include <iostream>
#include <string>
using namespace std;

int main() {
    int capacity = 3;
    int itemCount = 0;
    string* itemList = new string[capacity];

    for (int entry = 0; entry < 7; ++entry) {
        string item;
        cout << "Enter item " << entry + 1 << ": ";
        cin >> item;

        if (itemCount == capacity) {
            int newCapacity = capacity * 2;
            cout << "Resize triggered: " << capacity << " -> " << newCapacity << endl;

            string* resizedList = new string[newCapacity];
            for (int index = 0; index < itemCount; ++index) {
                resizedList[index] = itemList[index];
            }

            delete[] itemList;
            itemList = resizedList;
            capacity = newCapacity;
        }

        itemList[itemCount] = item;
        ++itemCount;
    }

    cout << "\nCart items:\n";
    for (int index = 0; index < itemCount; ++index) {
        cout << itemList[index] << endl;
    }

    delete[] itemList;
    return 0;
}
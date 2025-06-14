#include<iostream>
#include<vector>

using namespace std;

int main() {
    // Declare a vector of integers
    vector<int> numbers;

    // Add some elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Print the elements of the vector
    cout << "Elements in the vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Remove the last element from the vector
    numbers.pop_back();
    cout << "After removing the last element: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    cout << endl;
    // Check the size of the vector
    cout << "Size of the vector: " << numbers.size() << endl;
    // Check if the vector is empty
    if (numbers.empty()) {
        cout << "The vector is empty." << endl;
    } else {
        cout << "The vector is not empty." << endl;
    }

    return 0;
}   
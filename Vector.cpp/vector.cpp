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

    return 0;
}   
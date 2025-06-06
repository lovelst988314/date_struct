#include<iostream>
#include<vector>

using namespace std;

void  heapify(vector<int> &nums, int start, int end) {
    int leftchild = start * 2 + 1;
    int rightchild = start * 2 + 2;
    int min = start;
    if(leftchild < end && nums[leftchild] < nums[min]) {
        min = leftchild;
    }
    if(rightchild < end && nums[rightchild] < nums[min])
    {
        min = rightchild;
    }
    if(min != start) {
        swap(nums[min], nums[start]);
        heapify(nums, min, end);
    }
} 

void heapsort(vector<int> &nums) {
    int len = nums.size();
    for(int i = len/2-1; i >= 0; i--) {
        heapify(nums, i, len);
    }

    for(int i = 0; i < len; i++) {
        swap(nums[0], nums[len-1-i]);
        heapify(nums, 0, len-i-1);
    }
}
int main () {
    vector<int> nums = {9,5,6,3,5,3,1,0,96,66};

    heapsort(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
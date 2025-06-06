#include<iostream>
#include<vector>

using namespace std;

int main() {
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    int left = 0, right = 0;
    int sum = 0, len = INT_MAX;
    while(right < nums.size()) {
        sum += nums[right];
        while(sum >= target) {
            len = min(len,right-left);
            left++;
            sum -= nums[left];
        }
        right++;
    }
    cout << len << endl;
}
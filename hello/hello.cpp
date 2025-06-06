#include<iostream>
#include<vector>

using namespace std;
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    if(sum%2 == 1) return false;
    int ans = sum/2;
    vector<int> dp(ans,0);
    for(int i = ans-1; i >= nums[0]; i--) {
        dp[i] = nums[0];
    }
    for(int i = 1; i < nums.size(); i++) {
        for(int j = ans-1; j >=nums[i]; j--) {
            dp[j] = max(dp[j-nums[i]] + nums[i],dp[j]);
        }
    }
    if(dp[ans-1] != ans) return false;
    cout  << dp[ans-1] << endl;
    return true;
}


int main() {
    vector<int> res = {1,5,11,5};
    cout << canPartition(res) << endl;
    return 0;
}   
#include<iostream>
#include<vector>

using namespace std;

int mintili(const vector<vector<int>> &map) {
    vector<vector<int>> dp(map.size(),vector<int>(map[0].size(),INT_MAX));
    dp[0][0] = map[0][0];

    for(int i = 1; i < map.size(); i++) {
        if(abs(map[i][0] - map[i-1][0]) <= 1) {
            dp[i][0] = dp[i-1][0] + map[i][0];
        } else {
            break;
        } 
    }
    for(int i = 1; i < map[0].size(); i++) {
        if(abs(map[0][i] - map[0][i-1]) <= 1) {
            dp[0][i] = dp[0][i-1] + map[0][i];
        } else {
            break;
        } 
    }

    for(int i = 1; i < map.size(); i++) {
        for(int j = 1; j < map[0].size(); j++) {
            if(abs(map[i][j] - map[i-1][j]) <= 1 && abs(map[i][j] - map[i][j-1]) <= 1 && dp[i-1][j] != INT_MAX && dp[i][j-1] != INT_MAX) dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + map[i][j];
            if(abs(map[i][j] - map[i-1][j]) <= 1 && abs(map[i][j] - map[i][j-1]) > 1 && dp[i-1][j] != INT_MAX) dp[i][j] = dp[i-1][j] + map[i][j];
            if(abs(map[i][j] - map[i-1][j]) > 1 && abs(map[i][j] - map[i][j-1]) <= 1 && dp[i][j-1] != INT_MAX) dp[i][j] = dp[i][j-1] + map[i][j];
        }
    }

    int nums = INT_MAX;
    for(int i = 0; i < map.size(); i++) {
        nums = min(nums, dp[i][map[0].size()-1]);
    }
    if(nums == INT_MAX) return -1;

    for(int i = 0; i < map.size(); i++) {
        for(int j = 0; j < map[0].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return nums;
}

int main () {
    int k;
    cin >> k;

    if(k < 0 || k >100) {
        cout << -2 << endl;
        return 0;
    }

    vector<vector<int>> map(k,vector<int>(k));
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            cin >> map[i][j];
            if(map[i][j] < 0 || map[i][j] > 10) {
                cout << -2 << endl;
                return 0;  
            }
        }
    }
    cout << mintili(map) << endl;

    return 0;
}
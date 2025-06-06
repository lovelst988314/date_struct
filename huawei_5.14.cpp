#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main() {
    string line1;
    getline(cin, line1);

    string line2;
    getline(cin, line2);

    istringstream iss(line1);
    vector<int> cars;
    int x;
    while(iss >> x) {
        cars.push_back(x);
    }

    istringstream iss2(line2);
    vector<int> requires;
    while(iss2 >> x) {
        requires.push_back(x);
    }

    if(cars.size() < 1 || requires.size() < 1 || cars.size() > 200 || requires.size() > 100000) {
        return -1;
    } 
    for(auto x : cars) {
        if(x < 1 || x > 5000) {
            return -1;
        }
    }
    for(auto x : requires) {
        if(x < 1 || x > 100) {
            return -1;
        }
    }

    int assigntimes = 0;
    int carsindex = 0;
    int stock = cars[carsindex];

    while(!requires.empty() && carsindex < cars.size()) {
        int maxlen = 0, left = 0, right = 0, endleft = 0;
        while(right < requires.size()) {
            stock -= requires[right];
            while(stock < 0) {
                int nums = maxlen;
                maxlen = max(maxlen, right-left);
                if(nums != maxlen) endleft = left;
                stock += requires[left];
                left++;
            }
            right++;
        }

        if (left < right && stock >= 0) {
            int lastLen = right - left;
            if (lastLen > maxlen) {
                maxlen = lastLen;
                endleft = left;
        }
    }

        if(maxlen > 0) {
            requires.erase(requires.begin()+endleft, requires.begin()+endleft+maxlen);
            assigntimes++;
            carsindex++;
            if(carsindex < cars.size()) stock = cars[carsindex];
        } else {
            carsindex++;
            if(carsindex < cars.size()) {
                stock += cars[carsindex];
            } else {
                break;
            }
        }
    }

    cout << assigntimes << " " << requires.size() << endl;

    return 0;

}
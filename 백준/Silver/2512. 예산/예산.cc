#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int n;
    long long real_max;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }
    cin >> real_max;

    int mins = 1;
    int maxs = 100000;
    int mid;

    while(mins + 1 < maxs){
        mid = (mins + maxs) / 2;
        //cout << "mid : " << mid << "    " << mins << ", " << maxs << endl;

        long long test_money = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] > mid) test_money += mid;
            else                test_money += nums[i];
        }

        if(test_money <= real_max){
            mins = mid;
        }else{
            maxs = mid;
        }

    }

    cout << min((mins + maxs) / 2, *max_element(nums.begin(), nums.end()));


    return 0;
}
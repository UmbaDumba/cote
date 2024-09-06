#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    vector<long long> trees;
    cin >> n >> m;
    long long maxvalue = 0;
    long long minvalue = 0;
    for(int i = 0; i<n; i++){
        long long temp;
        cin >> temp;
        trees.push_back(temp);
        maxvalue = max(maxvalue, temp);
    }

    long long mid;
    while(minvalue + 1 < maxvalue){
        
        mid = (maxvalue + minvalue)/2;
        long long cuts = 0;
        for(int i = 0; i<trees.size(); i++){
            if(trees[i] > mid){
                cuts += (trees[i] - mid);
            }
        }
        if(cuts > m){
            minvalue = mid;
        }else if(cuts < m){
            maxvalue = mid;
        }else{
            break;
        }
    }
    mid = (maxvalue + minvalue)/2;
    cout << mid;

    return 0;
}
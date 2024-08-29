#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> sangdams; // [days, pay]

int maxmoney = 0;

void sol(int index, int money){
    if(index >= n){
        // 불가능한 상담
        maxmoney = max(maxmoney, money);
        return;
    }
    int next = index + sangdams[index].first;
    if(next > n){
        // 불가능한 상담, 이 상담은 안하고 끝내야함
        maxmoney = max(maxmoney, money);
        return;
    }else if(next == n){
        // 지금게 마지막 상담
        money+=sangdams[index].second;
        maxmoney = max(maxmoney, money);
        return;
    }
    money+=sangdams[index].second;

    for(int i = 0; i<n; i++){
        sol(next+i, money);
    }
    
}

int main(){

    cin >> n;

    for(int i = 0; i<n; i++){
        int a, b;
        cin >>a >> b;
        sangdams.push_back({a, b});
    }

    for(int i = 0; i<n; i++){
        sol(i, 0);
    }

    cout << maxmoney;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _na{
    int code;
    int gold;
    int silver;
    int bronze;
}nara;

bool comp(nara a, nara b){
    if(a.gold == b.gold){
        if(a.silver == b.silver){
            return a.bronze > b.bronze;
        }else{
            return a.silver > b.silver;
        }
    }else{
        return a.gold > b.gold;
    }
}

int main(){

    int n, k;
    cin >> n >> k;
    
    vector<nara> nations(n);
    for(int i = 0; i<n; i++){
        cin >> nations[i].code;
        cin >> nations[i].gold;
        cin >> nations[i].silver;
        cin >> nations[i].bronze;
    }
    
    sort(nations.begin(), nations.end(), comp);
    
    
    for(int i = n-1; i>=0; i--){
        if(nations[i].code == k){
            if(i == 0){
                cout << "1";
                return 0;
            }
            if((nations[i].gold == nations[i-1].gold)
                && (nations[i].silver == nations[i-1].silver)
                && (nations[i].bronze == nations[i-1].bronze)){
                k = nations[i-1].code;
                continue;
            }else{
                cout << i + 1;
                return 0;
            }
        }
    }
    

    return 0;
}
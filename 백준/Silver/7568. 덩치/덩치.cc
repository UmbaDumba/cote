#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _na{
    int height;
    int weight;
}dungchi;



bool comp(dungchi a, dungchi b){
    return (a.height > b.height) && (a.weight > b.weight);
}


int main(){

    int n;
    cin >> n;
    
    vector<dungchi> peoples(n);
    for(int i = 0; i<n; i++){
        cin >> peoples[i].height;
        cin >> peoples[i].weight;
    }
    

    for(int i = 0; i<n; i++){
        int score = 1;
        for(int j = 0; j<n; j++){
            if(comp(peoples[j], peoples[i])) score++;
        }
        cout << score << " ";
    }
    

    return 0;
}
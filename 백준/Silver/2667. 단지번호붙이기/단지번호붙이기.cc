#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector<vector<int>> maps;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

vector<int> get_seed(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(maps[i][j] == 1){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    maps = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i = 0; i<n; i++){
        string str;
        cin >> str;
        for(int j = 0; j<n; j++){
            maps[i][j] = str[j] - '0';
        }
    }
    

    vector<int> vuliges;
    while(true){
        vector<int> seed = get_seed();
        if(seed[0] == -1){
            break;
        }
        int vuls = 1;
        queue<vector<int>> que;
        que.push(seed);
        maps[seed[0]][seed[1]] = 0;
        while(!que.empty()){
            vector<int> nowindex = que.front();
            que.pop();
            for(int i = 0; i<4; i++){
                int newx = nowindex[0] + dx[i];
                int newy = nowindex[1] + dy[i];
                if(newx < 0 || newx >= n|| newy < 0 || newy >= n){
                    continue;
                }
                if(maps[newx][newy] == 1){
                    vuls++;
                    maps[newx][newy] = 0;
                    que.push({newx, newy});
                }
            }
        }
        vuliges.push_back(vuls);

    }

    sort(vuliges.begin(), vuliges.end());

    cout << vuliges.size()<<endl;
    for(int i = 0; i<vuliges.size(); i++){
        cout << vuliges[i] << endl;
    }


    return 0;
}
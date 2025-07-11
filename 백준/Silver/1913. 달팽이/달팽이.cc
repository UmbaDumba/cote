#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/*

    [0][0] = n^2
    [1][1] = (n-1)^2

*/


int main(){


    int n, pose;
    cin >> n >> pose;

    vector<vector<long long>> result(n, vector<long long>(n, 0));
    int rx, ry;

    long long n2 = (long long)n * n;
    int nn = n;

    int si = 0;
    int sj = 0;
    while(n2 > 0){
        int x = si;
        int y = sj;


        // 아래로
        for(int i = 0; i<n; i++){
            result[x][y] = n2;
            if(n2 == pose){
                rx = x+1;
                ry = y+1;
            }
            n2--;
            x++;
        }
        x--;

        //오른쪽으로
        y++;
        for(int i = 0; i<n-1; i++){
            result[x][y] = n2;
            if(n2 == pose){
                rx = x+1;
                ry = y+1;
            }
            n2--;
            y++;
        }
        y--;

        // 위로
        x--;
        for(int i = 0; i<n-1; i++){
            result[x][y] = n2;
            if(n2 == pose){
                rx = x+1;
                ry = y+1;
            }
            n2--;
            x--;
        }
        x++;

        // 왼쪽으로
        y--;
        for(int i = 0; i<n-2; i++){
            result[x][y] = n2;
            if(n2 == pose){
                rx = x+1;
                ry = y+1;
            }
            n2--;
            y--;
        }
        y++;

        x++;


        si++;
        sj++;

        n-=2;
    }

    for(int i = 0; i<nn; i++){
        for(int j = 0; j<nn; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << rx << " " << ry;

    return 0;
}
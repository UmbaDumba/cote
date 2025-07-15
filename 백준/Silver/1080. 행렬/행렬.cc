#include <iostream>
#include <vector>
using namespace std;



int main(){
    int n, m;
    int answer = 0;
    cin >> n >> m;

    vector<vector<int>> array_a(n, vector<int>(m));
    vector<vector<int>> array_b(n, vector<int>(m));
    

    for(int i = 0; i<n; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j<m; j++){
            array_a[i][j] = tmp[j] - '0';
        }
    }

    

    for(int i = 0; i<n; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j<m; j++){
            array_b[i][j] = tmp[j] - '0';
        }
    }

    // 크기가 3*3보다 작은경우 -> 토글없이 일단비교
    if(n < 3 || m < 3){
        bool flag = true;
        for(int k = 0; k<n; k++){
            for(int l = 0; l<m; l++){
                if(array_a[k][l] != array_b[k][l]){
                    flag = false;
                    break;
                }
            }
        }

        if(flag){
            cout << answer;
            return 0;
        }
    }

    // greedy
    for(int i = 0; i<n-2; i++){
        for(int j = 0; j<m-2; j++){

            // 지금위치의 숫자가 다르면 toggle
            if(array_a[i][j] != array_b[i][j]){
                answer++;
                for(int k = i; k<i+3; k++){
                    for(int l = j; l<j+3; l++){
                        array_a[k][l] = !array_a[k][l];
                    }
                }
            }

            // 토글시켰는데 두 배열이 일치하면 마무리
            bool flag = true;
            for(int k = 0; k<n; k++){
                for(int l = 0; l<m; l++){
                    if(array_a[k][l] != array_b[k][l]){
                        flag = false;
                        break;
                    }
                }
            }

            if(flag){
                cout << answer;
                return 0;
            }
        }
    }

    cout << "-1";


    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));

// 빈칸인 곳에 val가 들어갈 수 있는지
bool is_ok(int i, int j, int val){

    // 가로줄 확인
    for(int k = 0; k<9; k++){
        if(sudoku[i][k] == val) return false;
    }

    // 세로줄 확인
    for(int k = 0; k<9; k++){
        if(sudoku[k][j] == val) return false;
    }

    // 3*3 확인
    int ti = (i / 3) * 3;
    int tj = (j / 3) * 3;
    for(int k = ti; k < ti + 3; k++){
        for(int l = tj; l < tj + 3; l++){
            if(sudoku[k][l] == val) return false;
        }
    }

    return true;
}

void sol(int a, int b){
    // a, b부터 시작

    if(b == 9){
        a++;
        b = 0;
    }
    if(a == 9){
        // 완성
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
        return;
    }

    if(sudoku[a][b] != 0) sol(a, b+1);
    else{
        // 빈칸채우기
        for(int k = 1; k < 10; k++){
            if(is_ok(a, b, k)){
                // 재귀
                sudoku[a][b] = k;
                sol(a, b+1);
                sudoku[a][b] = 0;
            }
        }
    }
}

int main(){

    int unsols = 0;
    int preunsols = 0;
    bool multi_flag = false;

    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0) unsols++;
        }
    }

    sol(0, 0);


    return 0;
}
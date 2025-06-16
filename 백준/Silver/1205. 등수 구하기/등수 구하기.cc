/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    
    int n, tesu, p;
    cin >> n >> tesu >> p;
    if(n == 0){
        cout << 1;
        return 0;
    }
    
    vector<int> scores(n);
    for(int i = 0; i<n; i++){
        cin >> scores[i];
    }
    
    int rank = 1;
    for(int i = 0; i<p; i++){
        if(i >= n){
            cout << rank;
            return 0;
        }
        if(scores[i] < tesu){
            cout << rank;
            return 0;
        }else if(scores[i] > tesu){
            rank = i + 2;
        }
    }
    
    cout << "-1";

    return 0;
}
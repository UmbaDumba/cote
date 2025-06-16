/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> min_heap;
    int n;
    cin >> n;
    
    for(int i = 0; i<n; i++){
        int q;
        cin >> q;
        if(q == 0){
            if(min_heap.empty()){
                cout << "0\n";
            }else{
                cout << min_heap.top() << "\n";
                min_heap.pop();
            }
        }else{
            min_heap.push(q);
        }
    }
    

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;



int main(){
    int n;
    cin >> n;
    vector<int> students(2*n);
    for(int i = 0; i<2*n; i++){
        cin >> students[i];
    }

    sort(students.begin(), students.end());

    int result = INT_MAX;

    for(int i = 0; i<n; i++){
        int tmp = students[i] + students[2*n-1-i];
        result = min(result, tmp);
    }

    cout << result;

    return 0;
}
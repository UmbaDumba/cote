#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    if(t == 1){
        unsigned long long a, b;
        cin >> a >> b;
        unsigned long long sums = a + b;
        char answer[14];

        for(int i = 0; i<13; i++){
            int tmp = sums % 26;
            answer[i] = 'a' + tmp;
            sums /= 26;
        }
        answer[13] = 0;

        cout << answer << endl;

    }else if(t == 2){
        char text[14];
        cin >> text;

        unsigned long long sums = 0;
        for(int i = 12; i>=0; i--){
            sums *= 26;
            sums += (text[i] - 'a');
        }

        cout << sums << endl;
    }


    return 0;
}
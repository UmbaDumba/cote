#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// a, c 는 고정이므로 b에 대한것만 잘라서 저장
unordered_map<int, int> mem;
int a, c;


// (a^b) mod c
// a^b   ->   a^(b/2) * a^(b/2)
// (a^b) mod c == ((a^(b/2) mod c) * (a^(b/2) mod c)) mod c
int mod(int b){
    //cout << a << ", " << b << ", " << c << endl;
    if(b == 1){
        return mem[1];
    }

    if(mem.find(b) != mem.end()){
        return mem[b];
    }

    mem[b] = ((long long)mod(b - (b/2)) * (long long)mod(b/2)) % c;
    return mem[b];
}



int main(){

    int b;
    cin >> a >> b >> c;

    mem[1] = a % c;

    cout << mod(b);

    return 0;
}
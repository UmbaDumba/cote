#include <string>
#include <vector>

using namespace std;

vector<int> mem(100001, -1);

int fiv(int n){
    if(mem[n] != -1){
        return mem[n];
    }
    
    mem[n] = (fiv(n-2) + fiv(n-1)) % 1234567;
    return mem[n];
}

int solution(int n) {
    mem[0] = 0;
    mem[1] = 1;
    return fiv(n);
}

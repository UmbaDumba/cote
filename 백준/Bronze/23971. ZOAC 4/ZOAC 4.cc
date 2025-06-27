#include <iostream>
using namespace std;

int main(){

    int h, w, n, m;
    cin >> h >> w >> n >> m;

    int garo = w / (m + 1);
    if(w % (m + 1) > 0) garo++;

    int sero = h / (n + 1);
    if(h % (n+1) > 0) sero++;

    cout << garo * sero;

    return 0;
}
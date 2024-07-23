#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// a > b
int gcd(int a, int b){
    int mod = a%b;
    if(mod == 0){
        return b;
    }
    return gcd(b, mod);
}

int gcds(vector<int> a){
    //sort(a.begin(), a.end()); // 오름차순
    int gcdd = a[0];
    for(int i = 1; i<a.size(); i++){
        if(gcdd > a[i]){
            gcdd = gcd(gcdd, a[i]);
        }else{
            gcdd = gcd(a[i], gcdd);
        }
    }
    return gcdd;
}

bool is_devided(vector<int> vec, int n){
    // vec속 숫자들이 n으로 나눠지는지 (하나라도 나눠지는게 있으면 true)
    for(int i = 0; i < vec.size(); i++){
        if((vec[i] % n) == 0){
            return true;
        }
    }
    return false;
}


int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    // 조건 1 확인
    int culgcd = gcds(arrayA);
    if(!is_devided(arrayB, culgcd)){
        answer = culgcd;
    }
    
    // 조건 2 확인
    int yunggcd = gcds(arrayB);
    if(!is_devided(arrayA, yunggcd)){
        if(answer < yunggcd){
            answer = yunggcd;
        }
    }
    
    
    return answer;
}
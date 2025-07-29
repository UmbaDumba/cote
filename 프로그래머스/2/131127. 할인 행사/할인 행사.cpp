#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> wishlist;
    for(int i = 0; i<want.size(); i++){
        wishlist[want[i]] = number[i];
    }
    
    unordered_map<string, int> cart;
    for(int i = 0; i<10; i++){
        if(cart.find(discount[i]) == cart.end()){
            cart[discount[i]] = 1;
        }else{
            cart[discount[i]]++;
        }
    }
    
    bool flag = true;
    for(int i = 0; i<want.size(); i++){
        if(cart.find(want[i]) == cart.end()){
            flag = false;
            break;
        }
        if(cart[want[i]] < number[i]){
            flag = false;
            break;
        }
    }
    if(flag) answer++;
    
    for(int i = 10; i<discount.size(); i++){
        // [i]를 포함하고 [i-10]을 제외했을 때 충족여부
        cart[discount[i-10]]--;
        
        if(cart.find(discount[i]) == cart.end()){
            cart[discount[i]] = 1;
        }else{
            cart[discount[i]]++;
        }
        
        bool flag = true;
        for(int j = 0; j<want.size(); j++){
            if(cart.find(want[j]) == cart.end()){
                flag = false;
                break;
            }
            if(cart[want[j]] < number[j]){
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    
    return answer;
}
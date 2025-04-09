#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<int> stones, int k) {
    int answer = 0;
    
    long long min_ninis = 0;
    long long max_ninis = *max_element(stones.begin(), stones.end()) + 1;
    
    int stone_num = stones.size();
    
    while(min_ninis + 1 < max_ninis)
    {
        long long mid_ninis = (min_ninis + max_ninis) / 2;
        //cout << mid_ninis << endl;
        
        int is_ok = true;
        int k_count = k - 1;
        for(int i = 0; i<stone_num; i++)
        {
            
            
            if(stones[i] >= mid_ninis)
            {
                k_count = k - 1;
            }else{
                k_count--;
            }
            
            if(k_count < 0)
            {
                is_ok = false;
                break;
            }
        }
        
        if(is_ok)
        {
            // mid명이 건널 수 있음
            min_ninis = mid_ninis;
        }else{
            // mid명이 못건넘
            max_ninis = mid_ninis;
        }
    }
    
    return min_ninis;
}
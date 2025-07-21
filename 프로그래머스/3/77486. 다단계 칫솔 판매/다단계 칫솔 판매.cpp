#include <string>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct human{
    struct human *parent;
    int cost;
}t_human;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, t_human *> users;
    
    t_human minho = {NULL, 0};
    
    for(int i = 0; i<enroll.size(); i++)
    {
        t_human* temp = (t_human *)malloc(sizeof(t_human));
        temp->cost = 0;
        if(referral[i] == "-")
        {
            temp->parent = &minho;
        }else{
            temp->parent = users[referral[i]];
        }
        users[enroll[i]] = temp;
    }
    
    for(int i = 0; i<seller.size(); i++)
    {
        //cout << seller[i]<<endl;
        t_human * sel = users[seller[i]];
        int cost = amount[i] * 100;
        
        while(sel != NULL)
        {
            sel->cost += (cost - cost / 10);
            //cout << sel->cost << endl;
            cost /= 10;
            
            sel = sel->parent;
        }
    }
    
    for(int i = 0; i<enroll.size(); i++)
    {
        answer.push_back(users[enroll[i]]->cost);
    }
    
    
    return answer;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool is_m(char c){
    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

int main(){

    while(true){
        string pw;
        cin >> pw;
        if(pw == "end") break;

        int mcountall = 0;
        int mcount = 0; // a,e,i,o,u
        int jcount = 0;

        bool flag = true;
        bool eeflag = false;
        bool ooflag = false;

        for(int i = 0; i<pw.size(); i++){
            if(is_m(pw[i])){
                jcount = 0;
                mcount++;
                mcountall++;
                if(mcount > 2){
                    flag = false;
                    break;
                }
            }else{
                mcount = 0;
                jcount++;
                if(jcount > 2){
                    flag = false;
                    break;
                }
            }

            if(pw[i] == 'e'){
                if(eeflag){
                    flag = false;
                    break;
                }
                if((i != 0) && (pw[i-1] == 'e')){
                    eeflag = true;
                }
            }else if(pw[i] == 'o'){
                if(ooflag){
                    flag = false;
                    break;
                }
                if((i != 0) && (pw[i-1] == 'o')){
                    ooflag = true;
                }
            }else if((i != 0) && (pw[i] == pw[i-1])){
                flag = false;
                break;
            }else{
                eeflag = false;
                eeflag = false;
            }
        }


        if(!flag || (mcountall == 0)){
            cout << "<" << pw << "> is not acceptable." << endl;
        }else{
            cout << "<" << pw << "> is acceptable." << endl;
        }

    }
    

    return 0;
}
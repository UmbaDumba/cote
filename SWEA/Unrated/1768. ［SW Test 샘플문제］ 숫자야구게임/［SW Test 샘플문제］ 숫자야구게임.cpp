#define N 4


using namespace std;

typedef struct {
           int strike;
           int ball;
} Result;
 
// API
extern Result query(int guess[]);

int data[210][6]; // {n ,n ,n ,n, b, s}
int datacount;
int visit[10];
int answer[4];

bool isok(int num[4]){
    for(int i = 0; i<datacount; i++){
        Result testresult;
        testresult.strike = 0;
        testresult.ball = 0;
        for(int j = 0; j<4; j++){
            // num[j]에 대해 테스트
            
            //strike테스트
            if(num[j] == data[i][j]){
                testresult.strike++;
                continue;
            }

            //ball 테스트
            for(int k = 0; k<4; k++){
                if(num[j] == data[i][k]){
                    testresult.ball++;
                    break;
                }
            }
        }
        if(testresult.ball != data[i][4] || testresult.strike != data[i][5]){
            return false;
        }
    }
    
    return true;
}

void coms(int index, int num[4]){
    if(index == 4){
        if(isok(num)){
            Result testresult = query(num);
            if(testresult.strike == 4){
                answer[0] = num[0];
                answer[1] = num[1];
                answer[2] = num[2];
                answer[3] = num[3];
                return;
            }
            data[datacount][0] = num[0];
            data[datacount][1] = num[1];
            data[datacount][2] = num[2];
            data[datacount][3] = num[3];
            data[datacount][4] = testresult.ball;
            data[datacount][5] = testresult.strike;
            datacount++;
        }
        return;
    }

    for(int i = 0; i<10; i++){
        if(visit[i] == 1){
            continue;
        }
        visit[i] = 1;
        num[index] = i;
        coms(index+1,num);
        visit[i] = 0;
    }

}

 
void doUserImplementation(int guess[]) {
           // Implement a user's implementation function
           //
           // The array of guess[] is a return array that
           // is your guess for what digits[] would be.

           datacount = 0;
           for(int i = 0; i<10; i++){
            visit[i] = 0;
           }

           int num[4];
            coms(0, num);

            for(int i = 0; i<4; i++){
                guess[i] = answer[i];
            }
           

}

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> *vec, int i, int j)
{
    int tmp = (*vec)[i];
    (*vec)[i] = (*vec)[j];
    (*vec)[j] = tmp;
}

int main(){

    int p;
    cin >> p;

    for(int i = 0; i<p; i++)
    {
        int qnum, answer;
        cin >> qnum;
        answer = 0;

        vector<int> heights(20);
        for(int j = 0; j<20; j++)
        {
            cin >> heights[j];
        }

        // 정렬 (삽입정렬이었나 먼정렬이지 암튼)
        for(int j = 1; j<20; j++){
            for(int k = j-1; k>=0; k--){
                if(heights[k] < heights[k+1]){
                    // 이동 멈추기
                    break;
                }
                swap(&heights, k+1, k);
                answer++;
            }
        }
        

        cout << qnum << " " << answer << endl;

    }

    return 0;
}
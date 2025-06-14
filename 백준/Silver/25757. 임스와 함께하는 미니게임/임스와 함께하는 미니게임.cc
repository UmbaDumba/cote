#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;



int main(){

    unordered_set<string> explay;

    int n, game_people;
    char game;
    cin >> n >> game;

    if(game == 'Y') game_people = 2;
    if(game == 'F') game_people = 3;
    if(game == 'O') game_people = 4;

    int play_people = 1;
    int play_count = 0;
    for(int i = 0; i<n; i++){
        string name;
        cin >> name;
        if(explay.find(name) == explay.end()){
            play_people++;
            explay.insert(name);
        }else{
            continue;
        }

        if(play_people >= game_people){
            play_count++;
            play_people = 1;
        }
    }

    cout << play_count;
    

    return 0;
}
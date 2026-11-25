#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int correct;
    while(cin >> correct){
        int correct_guesses = 0;
        int answer;
        for(int i=0;i<5;i++){
            cin >> answer;
            if(answer==correct) correct_guesses++;
        }
        cout << correct_guesses << endl;
    }

    return 0;
}
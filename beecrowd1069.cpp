#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string line;
    getline(cin,line); // consome o \n

    while(n--){
        getline(cin,line);
        int brackets = 0;
        int diamonds = 0;

        for(char c : line){
            if(c=='<') brackets++;
            else if(c=='>'){
                if(brackets>0){
                    diamonds++;
                    brackets--;
                }
            }
        }

        cout << diamonds << endl;
    }

    return 0;
}
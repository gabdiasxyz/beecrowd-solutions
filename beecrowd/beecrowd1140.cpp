#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string line;

    while(getline(cin,line) && line!="*"){
        stringstream ss(line);
        string word;

        char first_letter;
        bool tautogram = true;

        if(ss>>word){
            first_letter = toupper(word[0]);

            while(ss >> word){
                char current_letter = toupper(word[0]);
                if(current_letter!=first_letter){
                    tautogram = false;
                    break;
                }
            }
        }

        if(tautogram) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}
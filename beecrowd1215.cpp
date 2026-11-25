#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> distinct_words; // o set os elementos sao sorted+unique
    string line;

    while(getline(cin,line)){
        // substituir tds as palavras nao alpha por espaço
        for(char &c : line){
            if(!isalpha(static_cast<unsigned char>(c))) c = ' ';
        }

        stringstream ss(line);
        string word;

        while(ss>>word){
            transform(word.begin(),word.end(),word.begin(),[](unsigned char c){ return tolower(c); });
            if(!word.empty()) distinct_words.insert(word);
        }
    }

    for(const string &w : distinct_words){ cout << w << '\n'; }

    return 0;
}
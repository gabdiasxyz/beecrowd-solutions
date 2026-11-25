#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    cin.ignore(); // consome o \n do input buffer

    for(int i=0;i<test_cases;i++){
        string line;
        getline(cin,line);
        
        stringstream ss(line);
        string word;
        vector<string> words;

        while(ss>>word) words.push_back(word);

        stable_sort(words.begin(),words.end(),[](const string& a, const string& b){
            return a.length() > b.length();
        });

        size_t size = words.size();
        for(size_t j=0;j<size;j++){
            cout << words[j];
            if(j<size-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
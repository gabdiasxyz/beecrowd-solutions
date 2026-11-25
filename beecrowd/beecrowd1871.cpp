#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M,N,sum;
    string aux,answer;
    stringstream ss;

    while(cin >> M >> N){
        if(!M && !N) break;

        sum = M+N;

        ss.clear();
        ss.str("");

        ss << sum;
        ss >> aux;

        answer = "";
        for(int i=0;i<aux.length();++i){
            if(aux[i]!='0') answer += aux[i];
        }

        cout << answer << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool repeated_digits(int n){
    bool seen[10]; // marcar digitos 0-9
    memset(seen,0,sizeof(seen));

    while(n>0){
        int digit = n%10;
        if(seen[digit]) return true; // repetido
        seen[digit] = true;
        n = n/10;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    while(cin>>N>>M){
        int count = 0;
        for(int i=N;i<=M;i++){
            if(!repeated_digits(i)) count++;
        }
        cout << count << '\n';
    }

    return 0;
}
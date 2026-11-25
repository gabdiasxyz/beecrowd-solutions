#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    while(b){
        a %= b;
        swap(a,b);
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        int f1,f2;
        cin >> f1 >> f2;

        cout << gcd(f1,f2) << '\n';
    }

    return 0;
}
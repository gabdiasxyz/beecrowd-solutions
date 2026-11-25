#include "bits/stdc++.h"
using namespace std;

typedef long long int64;

pair<int64,int64> fib(int64 n, int64 m){
    if(n==0) return {0,1};
    auto p = fib(n>>1,m);

    int64 a = p.first; // F(k)
    int64 b = p.second; // F(k+1)
    int64 c = (a * (2*b%m - a+m)%m)%m; // F(2k)
    int64 d = ((a*a%m) + (b*b%m))%m; // F(2k+1)

    if(n&1) return {d,(c+d)%m};
    else return {c,d};
}

int main(){
    // cin, cout optimization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 n; int b; int tc = 1;
    while(cin >> n >> b){ 
        if(n==0 && b==0) break; 

        auto res = fib(n+1,b);
        int64 Fn1 = res.first;
        
        int64 calls = (2*Fn1-1)%b;
        if(calls<0) calls += b;

        cout <<"Case "<<tc++<<": "<<n<<" "<<b<<" "<<calls<< "\n";
    }
    return 0;
}
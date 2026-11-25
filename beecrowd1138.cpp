#include "bits/stdc++.h"
using namespace std;

typedef long long int64;

int64 count_ocurrences(int n, int d){
    int64 count = 0;
    for(int64 p=1;p<=n;p*=10){
        int64 higher = n/(p*10);
        int64 lower = n%p;
        int64 current_digit = (n/p)%10;

        if(d==0){
            if(higher>0){
                count += (higher-1)*p;
                if(current_digit==0) count += lower+1;
                else count += p;
            }
        }else{
            count += higher*p;
            if(current_digit>d) count += p;
            else if(current_digit==d) count += lower+1;
        }
    }

    return count;
}

vector<int64> solve(int n){
    if(n<0) return vector<int64>(10,0);
    vector<int64> counts(10,0);
    for(int i=0;i<10;i++) counts[i] = count_ocurrences(n,i);
    return counts;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b;
    while(cin >> a >> b && (a!=0 && b!=0)){
        if(a>b) swap(a,b);
        vector<int64> cb = solve(b);
        vector<int64> ca = solve(a-1);
        for(int i=0;i<10;i++) cout << cb[i]-ca[i] << (i==9 ? "" : " ");
        cout << '\n';
    }

    return 0;
}
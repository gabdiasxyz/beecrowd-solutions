#include <bits/stdc++.h>
using namespace std;

#define X 40

long long fibs[X];
int calls[X];

void precompute_fib(){
    fibs[0] = 0;
    fibs[1] = 1;

    calls[0] = 0;
    calls[1] = 0;

    for(int i=2;i<X;++i){
        fibs[i] = fibs[i-1]+fibs[i-2];
        calls[i] = calls[i-1]+calls[i-2]+2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_fib();

    int test_cases;
    cin >> test_cases;

    for(int i=0;i<test_cases;i++){
        int x;
        cin >> x;
        cout << "fib(" << x << ") = " << calls[x] << " calls = " << fibs[x] << endl;
    }

    return 0;
}
#include "bits/stdc++.h"
using namespace std;

typedef long long int64;

// vamos pre computar alguns valores pq o codigo tava lento dms
const int SIEVE_LIMIT = 50000;
int64 phi[SIEVE_LIMIT+1];
vector<int> primes;

void phi_sieve(){
    for(int i=0;i<=SIEVE_LIMIT;i++) phi[i] = i;
    for(int i=2;i<=SIEVE_LIMIT;i++){
        if(phi[i]==i){
            primes.push_back(i);
            for(int j=i;j<=SIEVE_LIMIT;j+=i) phi[j] -= phi[j]/i;
        }
    }
}

int64 eulerPhi_largeN(int64 n){
    int64 result = n;

    for(int p : primes){
        if((int64)p*p > n) break;
        if(n%p==0){
            result -= result/p;
            while(n%p==0) n/= p;
        }
    }

    if(n>1) result -= result/n;
    return result;
}

int main(){
    phi_sieve();

    int64 n;
    while(scanf("%lld",&n)==1){
        int64 phi_n;

        if(n<=SIEVE_LIMIT) phi_n = phi[n];
        else phi_n = eulerPhi_largeN(n);

        printf("%lld\n",phi_n/2);
    }

    return 0;
}
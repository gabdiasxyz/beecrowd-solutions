// o numero de maneiras de escrever um numero pela soma de numeros consecutivos eh a qtt de seus divisores impares
// a dificuldade desse daqui é o tamanho do numero, 9E^14

#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int MAXP = 10000000; // sieve ate sqrt(9e14)+1 ~ 1e7
vector<int> primes;
vector<char> is_prime; // vector<bool> is slow

void sieve(){
    is_prime.assign(MAXP+1,true);
    is_prime[0] = is_prime[1] = false;

    // remove even (except 2)
    for(int i=4;i<=MAXP;i+=2) is_prime[i] = false;

    for(int i=3;1LL*i*i<=MAXP;i+=2){
        if(is_prime[i]){
            for(int j=i*i;j<MAXP;j+=i*2) is_prime[j] = false; 
        }
    }

    primes.reserve(664579); // qtt de primos menores que 1e7; precomputado
    primes.push_back(2);

    for(int i=3;i<=MAXP;i+=2){
        if(is_prime[i]) primes.push_back(i);
    }
}

int64 divisors_odd(int64 n){
    while(n%2==0) n >>= 1; // dividindo por 2, mas aproveitando o bitwise pq eh integer

    int64 ans = 1;
    for(int p : primes){
        if(1LL*p*p>n) break;
        if(n%p==0){
            int exp = 0;
            do{
                n /= p;
                ++exp;
            }while(n%p==0);
            ans *= (exp+1);
        }
        if(n==1) break;
    }

    if(n>1) ans <<= 1; // resto é primo
    return ans;
}

int main(){
    sieve();

    int64 N;
    while(scanf("%lld",&N)==1){
        if(N==0) printf("0\n");
        else printf("%lld\n",divisors_odd(N));
    }

    return 0;
}
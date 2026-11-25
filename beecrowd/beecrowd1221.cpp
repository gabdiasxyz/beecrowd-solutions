#include <cstdio>
#include <cmath>
using namespace std;

bool is_prime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;

    // vamos até o 3 pq 6k+1 é uma aprox ok de primos

    for(int i=5;i*i<=n;i+=6) if(n%i==0 || n%(i+2)==0) return false;
    
    return true;
}

int main(){
    int N;
    scanf("%d",&N);
    
    while(N--){
        int x;
        scanf("%d",&x);
        if(is_prime(x)) printf("Prime\n");
        else printf("Not Prime\n");
    }

    return 0;
}
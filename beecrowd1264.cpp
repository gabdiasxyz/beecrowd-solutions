#include "bits/stdc++.h"
using namespace std;

int value(char c){
    if('0'<=c && c<='9') return c-'0';
    if('A'<=c && c<='Z') return c-'A'+10;
    if('a'<=c && c<='z') return c-'a'+36;
    return -1;
}

int mod(const char *s, int base){
    int rem = 0;
    for(int i=0;s[i];i++){
        if(s[i]=='-') continue;
        rem = (rem*base + value(s[i]))%(base-1);
    }
    return rem;
}

int main(){
    char s[1100]; // 1024 digitos + sign + \n
    while(scanf("%s",s)==1){ // nao precisa do &, pq eh uma array, entao é um input em &s[0], &s[1], ...
        int maxv = 0;
        for(int i=0;s[i];i++){
            if(s[i]!='-') maxv = max(maxv,value(s[i]));
        }

        int ans = -1;
        for(int base=max(2,maxv+1);base<=62;++base){
            if(mod(s,base)==0){
                ans = base;
                break;
            }
        }
        if(ans==-1) printf("such number is impossible!\n");
        else printf("%d\n",ans);
    }

    return 0;
}
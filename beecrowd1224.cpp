#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

// no beecrowd1214 eu fiz um i/o rapido de int já, mas esse aqui inclui EOF e é bem mais robusto...
// nao sei o que otimizar mais... acho que do 0.09 ao 0.00 dos amigos é ruido do beecrowd... ou ele sabe de algo que eu nao sei

#define BUFFER 8*1024*1024 // 8mb de buffer
char in_buffer[BUFFER];
int buffer_ptr = 0;
int buffer_len = 0;

inline char read_char(){
    if(buffer_ptr==buffer_len){
        buffer_len = fread(in_buffer,1,BUFFER,stdin);
        buffer_ptr = 0;
        if(buffer_len==0) return EOF;
    }
    return in_buffer[buffer_ptr++];
}
bool read_int(int &n){
    n = 0;
    int sign = 1;
    char c = read_char();

    while(c!=EOF && (c<'0' || c>'9') && c!='-') c = read_char();

    if(c==EOF) return false;
    if(c=='-'){
        sign = -1;
        c = read_char();
    }
    bool read_digit = false;
    while(c>='0' && c<='9'){
        read_digit = true;
        n = (n*10)+(c-'0');
        c = read_char();
    }
    if(!read_digit) return false;

    n *= sign;
    return true;
}

int main(){
    int N;
    while(read_int(N)){
        auto v = make_unique<int[]>(N);
        for(int i=0;i<N;i++){ read_int(v[i]); }

        auto dp = make_unique<int64[]>(N);
        fill_n(dp.get(),N,0LL);

        for(int len=2;len<=N;len++){
            bool alberto = (len%2==0);
            for(int i=0;i<=N-len;i++){
                int j = i+len-1;

                // dp[i+1] = dp[i+1][j] ; dp[i] = dp[i][j-1]
                // dp[i][j] = max(v[i]-dp[i+1][j],v[j]-dp[i][j-1])

                if(alberto){
                    int64 op1 = v[i]+dp[i+1];
                    int64 op2 = v[j]+dp[i];
                    dp[i] = (op1>op2) ? op1 : op2;
                }else dp[i] = (dp[i+1] < dp[i]) ? dp[i+1] : dp[i];
            }
        }
        printf("%lld\n",dp[0]);
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uint64;

uint64 memo[20][11][2][2]; // memoização dimensão posição/prev_digito/eh_restrita/leading_zero
string S;

uint64 lucky_numbers(int pos,int prev_digit,bool restricted,bool is_start){
    // caso base: se todas as posicoes sao preenchidas, encontramos um numero de sorte
    if(pos==S.length()) return 1;

    // se esse estado foi feito antes, retorna o valor
    if(memo[pos][prev_digit][restricted][is_start] != -1) return memo[pos][prev_digit][restricted][is_start];

    uint64 ans = 0;
    int upper_bound = restricted ? (S[pos]-'0') : 9;
    for(int digit=0;digit<=upper_bound;digit++){
        if(digit==4) continue;
        if(prev_digit==1 && digit==3) continue;

        ans += lucky_numbers(pos+1,
                             (is_start || digit>0) ? digit : 10,
                             restricted && (digit==upper_bound),
                             is_start || (digit>0));
    }
    return memo[pos][prev_digit][restricted][is_start] = ans; // memoiza o valor e retorna ele
}

uint64 solve(uint64 n){
    S = to_string(n);
    memset(memo,-1,sizeof(memo));
    return lucky_numbers(0,10,true,false);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint64 N;
    while(cin >> N){
        uint64 low = 1, high = 18000000000000000000ULL, ans = 0;
        while(low<=high){
            uint64 mid = low+(high-low)/2;
            if(mid==0){ // protecao, mas acho que nao devia acontecer...
                low = 1;
                continue;
            }

            uint64 lucky_floors = solve(mid)-1; // -1 pra descontar 0
            
            if(lucky_floors>=N){
                ans = mid; // potencial resposta
                if(mid==0) break; // protecao contra underflow
                high = mid-1;
            }else low = mid+1;
        }
        cout << ans << endl;
    }

    return 0;
}
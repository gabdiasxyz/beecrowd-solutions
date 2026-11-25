#include <bits/stdc++.h>
using namespace std;

/*
seja EV1 a vida do vampiro 1 e EV2 do vampiro 2
S = EV1 + EV2 eh constante. o jogo termina qnd EV1<=0 ou EV2<=0
seja p probabilidade V1 ganhar (AT/6) ; q probabilidade V2 ganhar ((6-AT)/6)

caso 1: p==q (AT==3)
jogo justo -> P(V1) = EV1/S

caso 2: p!=q
a gnt precisa achar a qntt de jogadas pra V1 ganhar e o total de jogadas do jogo.
os estados do jogo sao EV1, EV1 +- D, EV1 +- 2D ...
seja r = q/p
    1. encontrar o primeiro estado > 0 -> t = (EV1-1)%D + 1
    2. encontrar a qtt de estados 'm' de t ate S
    ---> indice k = (EV1-t)/D + 1
o numero total eh N=m+1, e a 'posicao inicial' eh k -> P(V1) = (1-r^k)/(1-r^N)
*/

// pra nao usar o std::pow, que usa logs... a gnt pode fazer isso pq exp eh inteiro
double fast_pow(double base,int exp){
    double res = 1.0;
    while(exp>0){
        if(exp&1) res *= base; // se o bit eh 1 multiplica a base
        base *= base;
        exp >>= 1; // proximo bit
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double ev1,ev2,at,d;
    cout << fixed << setprecision(1);

    while(cin>>ev1>>ev2>>at>>d && (ev1!=0 || ev2!=0 || at!=0 || d!=0)){
        double s = ev1+ev2;
        double p = at/6.0;
        double ans;

        int i_ev1 = static_cast<int>(ev1);
        int i_d = static_cast<int>(d);
        int i_s = static_cast<int>(s);

        int t = (i_ev1-1)%i_d+1; // (t>0)

        // numero de estados m tq t,t+D,...,t+(m-1)D < s
        int m = 0;
        /*int curr = t;
        while(curr<i_s){
            m++;
            curr += i_d;
        }*/
        if(i_s>t) m = (i_s-t+i_d-1)/i_d;

        int k = (i_ev1-t)/i_d+1;
        int N = m+1;

        if(fabs(p-0.5)<1e-9){
            // caso 1: at==3
            ans = static_cast<double>(k)/static_cast<double>(N);
        }else{
            // caso 2: at!=3
            double q = 1.0-p;
            double r = q/p;

            double r_k = fast_pow(r,k);
            double r_N = fast_pow(r,N);

            ans = (1.0-r_k)/(1.0-r_N);
        }

        cout << ans*100.0 << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1,y1,x2,y2;
    while(cin>>x1>>y1>>x2>>y2 && (x1!=0 || y1!=0 || x2!=0 || y2!=0)){
        // caso 0: p1 = p2
        if(x1==x2 && y1==y2) cout << 0 << endl;
        // caso 1: a rainha pode chegar num movimento só
        // entao, as casas estao na mesma linha, coluna, ou diagonal
        else if(x1==x2 || y1==y2 || abs(x1-x2)==abs(y1-y2)) cout << 1 << endl;
        // caso 2: a rainha precisa de 2 movimentos
        // de qlqr posicao, a rainha pode chegar para qlqr outra em 2 movimentos
        // seja p_1 = (x1,y1), p_2 = (x2,y2). a rainha pode se movimentar livremente em linha/coluna
        // entao em um movimento x1->x2 e em outro y1->y2
        else cout << 2 << endl;
    }

    return 0;
}
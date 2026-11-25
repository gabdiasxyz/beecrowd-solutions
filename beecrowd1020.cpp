#include <bits/stdc++.h>
using namespace std;

// esse caso não é tão simples porque as condições iniciais de ano 365 dias, meses 30 dias, 12 meses não batem perfeitamente, sobram 5 dias
// o jeito que eu escolhi tratar essa discrepância é contar os anos primeiro, e considerar meses e dias como o resto
// não é o ideal, pois tem alguns cenários que não faz sentido: 364 dias implica 12 meses e 4 dias, que não faz sentido algum...

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int time;
    cin >> time;

    cout << time/365 << " ano(s)\n" << time%365/30%12 << " mes(es)\n" << time%365%30 << " dia(s)\n";
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool selection(int A,int B,int C,int D){
    if(B>C && D>A && (C+D)>(A+B) && C>0 && D>0 && A%2==0) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A,B,C,D;
    cin >> A >> B >> C >> D;

    if(selection(A,B,C,D)) cout << "Valores aceitos\n";
    else cout << "Valores nao aceitos\n";
    
    return 0;
}
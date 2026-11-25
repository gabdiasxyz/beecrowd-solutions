#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    while(N--){
        string a,b;
        cin >> a >> b;

        int len_a = a.length();
        int len_b = b.length();

        if(len_b > len_a) cout << "nao encaixa\n";
        else{
            string final_a = a.substr(len_a-len_b);
            if(final_a == b) cout << "encaixa\n";
            else cout << "nao encaixa\n";
        }
    }

    return 0;
}
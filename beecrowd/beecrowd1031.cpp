#include <bits/stdc++.h>
using namespace std;

bool check(int N,int m){
    vector<int> regions(N);
    iota(regions.begin(),regions.end(),1); // add o vetor 1,2,3,4 .. N

    regions.erase(regions.begin()); // a qstao fala que a regiao 1 smp apaga primeiro
    int current_pos = 0;
    while(regions.size()>1){
        current_pos = (current_pos+m-1)%regions.size();
        regions.erase(regions.begin()+current_pos);
    }
    return regions[0]==13;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while(cin>>N && N!=0){
        int m=1;
        while(true){
            if(check(N,m)){
                cout << m << '\n';
                break;
            }
            m++;
        }
    }

    return 0;
}
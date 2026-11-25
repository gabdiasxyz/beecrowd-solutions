#include <bits/stdc++.h>
using namespace std;

bool compare_freqs(const pair<int,int>& a,const pair<int,int>& b){
    if(a.second!=b.second) return a.second<b.second;
    return a.first>b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    bool first = true;

    while(getline(cin,line)){
        if(!first) cout << '\n';
        first = false;

        int freq[128];
        memset(freq,0,sizeof(freq));
        for(char c : line){
            int ascii = static_cast<int>(c);
            if(ascii>=32 && ascii<128) freq[ascii]++;
        }
        vector<pair<int,int>> result;
        for(int i=32;i<128;i++){
            if(freq[i]>0) result.push_back({i,freq[i]});
        }

        sort(result.begin(),result.end(),compare_freqs);
        for(const auto& p : result){
            cout << p.first << " " << p.second << '\n';
        }
    }

    return 0;
}
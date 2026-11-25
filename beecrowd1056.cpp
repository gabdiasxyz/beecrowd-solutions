#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> A,B;
vector<vector<int>> adj;
vector<int> matchB;
vector<bool> visited;


bool dfs(int u){
    for(int v : adj[u]){
        if(visited[v]) continue;
        visited[v] = true;

        if(matchB[v]<0 || dfs(matchB[v])){
            matchB[v] = u;
            return true;
        }
    }
    return false;
}

void solve(int case_num){
    cin >> n;
    A.resize(n);
    for(int i=0;i<n;i++) cin >> A[i];

    cin >> m;
    B.resize(m);
    for(int i=0;i<m;i++) cin >> B[i];

    adj.assign(n,vector<int>());
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i]==0){
                if(B[j]==0) adj[i].push_back(j);
            }else if (B[j]%A[i]==0) adj[i].push_back(j);
        }
    }

    matchB.assign(m,-1);
    int max_match = 0;

    for(int i=0;i<n;i++){
        visited.assign(m,false);
        if(dfs(i)) max_match++;
    }

    cout << "Case " << case_num << ": " << max_match << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if(cin >> t){
        for(int i=1;i<=t;i++) solve(i);
    }
    
    return 0;
}
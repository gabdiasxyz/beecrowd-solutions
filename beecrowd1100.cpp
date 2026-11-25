#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string start, end;
    while(cin>>start>>end){
        int start_row = start[1]-'1';
        int start_col = start[0]-'a';
        int end_row = end[1]-'1';
        int end_col = end[0]-'a';

        // Breadth-First Search (BFS)
        queue<pair<int,int>> q;
        // um vetor 2d pra marcar a distancia de uma celula para qlqr outra celula
        vector<vector<int>> distance(8,vector<int>(8,-1));

        q.push({start_row,start_col});
        distance[start_row][start_col] = 0; // distancia dele mesmo eh 0

        // todos os movimentos possiveis dum cavalo, em delta
        int dr[] = {-2,-2,-1,-1,1,1,2,2};
        int dc[] = {-1,1,-2,2,-2,2,-1,1};

        while(!q.empty()){
            pair<int,int> current = q.front();
            q.pop();

            int r = current.first;
            int c = current.second;

            if(r==end_row && c==end_col) break;

            for(int i=0;i<8;i++){
                int next_r = r+dr[i];
                int next_c = c+dc[i];

                if(next_r>=0 && next_r<8 && next_c>=0 && next_c<8 && distance[next_r][next_c]==-1){
                    distance[next_r][next_c] = distance[r][c]+1;
                    q.push({next_r,next_c});
                }
            }
        }
        cout << "To get from " << start << " to " << end << " takes " << distance[end_row][end_col] << " knight moves." << endl;
    }

    return 0;
}
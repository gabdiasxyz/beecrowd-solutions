#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while(cin>>N && N!=0){
        vector<vector<int64>> values(N);
        for(int i=0;i<N;i++){
            values[i].resize(i+1);
            for(int j=0;j<=i;j++) cin >> values[i][j];
        }

        // criar a representação 'diagonalizada' do triangulo
        vector<vector<int64>> tilted(N);
        for(int c=0;c<N;c++){
            tilted[c].resize(N-c);
            for(int r=0;r<N-c;r++) tilted[c][r] = values[r+c][c];
        }

        int64 max_prize = 0;
        // +prev_S armazena S em (i-1)
        vector<int64> prev_S;

        for(int c=0;c<N;c++){
            int col_height = N-c;
            vector<int64> C(col_height); 
            vector<int64> S(col_height);

            C[0] = tilted[c][0];
            for(int r=1;r<col_height;r++) C[r] = C[r-1] + tilted[c][r];

            for(int r=col_height-1;r>=0;r--){
                int64 val;

                if(c==0) val = C[r];
                else val = prev_S[r]+C[r];

                if(r<col_height-1) S[r] = max(val,S[r+1]);
                else S[r] = val;
                
                max_prize = max(max_prize,S[r]);
            }
            prev_S = S;
        }
        cout << max_prize << endl;
    }
    
    return 0;
}
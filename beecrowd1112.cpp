#include <bits/stdc++.h>
using namespace std;

// problema de Binary Indexed Tree
int bit[1005][1005]; // (5 de buffer)
int field_width,field_height,P;

void update(int x,int y,int val){
    x++; y++;
    for(int i=x;i<=field_width;i+=i&-i){ // (i += i&-i soma o LSB de I)
        for(int j=y;j<=field_height;j+=j&-j) bit[i][j] += val;
    }
}
int query(int x,int y){ // soma do retangulo de (0,0) -> (x,y)
    x++; y++;
    int sum = 0;
    for(int i=x;i>0;i-=i&-i){
        for(int j=y;j>0;j-=j&-j) sum += bit[i][j];
    }
    return sum;
}
int range_query(int x1,int y1,int x2,int y2){
    /* soma do retangulo (x1,y1) -> (x2,y2)
        principio inclusao-exclusao: sum(ABCD) = sum(D) + sum(A) - sum(B) - sum(C)
        A = (x1-1,y1-1) ; B = (x1-1,y2) ; C = (x2,y1-1) ; D = (x2,y2)
    */
   return query(x2,y2) - query(x1-1,y2) - query(x2,y1-1) + query(x1-1,y1-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin>>field_width>>field_height>>P && (field_width!=0 || field_height!=0 || P!=0)){
        for(int i=0;i<=field_width;i++) memset(bit[i],0,(field_height+1)*sizeof(int));

        int Q;
        cin >> Q;
        for(int q=0;q<Q;q++){
            char type;
            cin >> type;

            if(type=='A'){
                int N,X,Y;
                cin >> N >> X >> Y;
                update(X,Y,N);
            }else if(type=='P'){
                int X,Y,Z,W;
                cin >> X >> Y >> Z >> W;

                int x1 = min(X,Z);
                int y1 = min(Y,W);
                int x2 = max(X,Z);
                int y2 = max(Y,W);

                long long schweisen = range_query(x1,y1,x2,y2);
                cout << schweisen*P << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}
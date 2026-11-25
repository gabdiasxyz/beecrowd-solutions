#include <bits/stdc++.h>
using namespace std;

struct stone {
    int position;
    char type;

    bool operator<(const stone& other) const {
        return position < other.position;
    }
};

bool is_trip_possible(int max_leap,int D, const vector<stone>& all_stones){
    vector<bool> used(all_stones.size(),false);

    // caminho 0 -> D
    int current_pos = 0;
    while(current_pos<D){
        int next_pos = -1;
        int stone_idx = -1;

        for(int i=0;i<all_stones.size();i++){
            if(all_stones[i].position>current_pos && all_stones[i].position-current_pos<=max_leap){
                if(all_stones[i].position>next_pos){
                    next_pos = all_stones[i].position;
                    stone_idx = i;
                }
            }
        }

        if(next_pos==-1) return false; // o sapo tá preso :(
        current_pos = next_pos;
        if(all_stones[stone_idx].type=='S') used[stone_idx] = true;
    }

    // caminho D -> 0
    current_pos = D;
    while(current_pos>0){
        int next_pos = D+1;

        for(int i=0;i<all_stones.size();i++){
            if(!used[i] && all_stones[i].position<current_pos && current_pos-all_stones[i].position<=max_leap) {
                if(all_stones[i].position < next_pos) next_pos = all_stones[i].position;
            }
        }

        if(next_pos==D+1) return false; // o sapo tá preso dnv :(
        current_pos = next_pos;
    }

    return true;
}

void solve_case(int case_num){
    int N,D;
    cin >> N >> D;

    vector<stone> stones;
    // tratar as margens como duas pedras grandes no começo e no fim
    stones.push_back({0,'B'});
    stones.push_back({D,'B'});

    for(int i=0;i<N;i++){
        char type,dash;
        int pos;
        cin >> type >> dash >> pos;
        stones.push_back({pos,type});
    }

    sort(stones.begin(),stones.end()); // da pra fzr isso porque tem o operator> na struct

    // binary search
    int low = 1, high = D, ans = D;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(is_trip_possible(mid,D,stones)){
            ans = mid;
            high = mid-1;
        }else low = mid+1;
    }

    cout << "Case " << case_num << ": " << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i=1;i<=T;i++) solve_case(i);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while(cin>>N && N!=0){
        vector<int> h(N);
        for(int i=0;i<N;i++) cin >> h[i];

        int peak_count = 0;
        for(int id=0;id<N;id++){
            int prev_id = (id+N-1)%N;
            int next_id = (id+1)%N;

            int current_sample = h[id];
            int prev_sample = h[prev_id];
            int next_sample = h[next_id];

            bool is_local_max = (current_sample>prev_sample && current_sample>next_sample);
            bool is_local_min = (current_sample<prev_sample && current_sample<next_sample);

            if(is_local_max || is_local_min) peak_count++;

        }
        cout << peak_count << endl;
    }
    return 0;
}
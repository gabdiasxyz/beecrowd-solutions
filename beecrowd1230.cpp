#include "bits/stdc++.h"
using namespace std;
typedef long long int64;

const int64 INF = (int64)4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto weight = [&](int i, int n)->int {
        if(i==0 || i==n) return 1;
        return 2;
    };

    int64 n, M, Y;
    while((cin >> n >> M >> Y)){
        map<int64, int64> known;
        for(int64 i = 0; i < M; i++){
            int64 x, f; cin >> x >> f;
            known[x] = f;
        }
        
        if(!known.count(0) || !known.count(n)){
            cout << "N\n";
            continue;
        }

        vector<int64> L(n + 1, -INF), U(n + 1, INF);
        for(auto &p : known) L[p.first] = U[p.first] = p.second;
        
        vector<pair<int64, int64>> segs;
        {
            auto it = known.begin();
            while(next(it) != known.end()){
                auto next_it = next(it);
                int64 a = it->first, b = next_it->first;
                int64 A = it->second, B = next_it->second;
                
                int64 lo = min(A, B), hi = max(A, B);
                for(int64 i = a + 1; i <= b - 1; i++){
                    L[i] = max(L[i], lo);
                    U[i] = min(U[i], hi);
                }
                segs.emplace_back(a, b);
                it = next_it;
            }
        }
        auto weighted_sum = [&](const vector<int64>& arr)-> int64 {
            int64 s = 0;
            for(int64 i=0;i<=n;i++) s += weight(i,n)*(int64)arr[i];
            return s;
        };

        vector<int64> f_min(n+1), f_max(n+1);
        for(auto &p : segs){
            int64 a = p.first, b = p.second;
            int64 A = known[a], B = known[b];
            f_min[a] = f_max[a] = A;
            f_min[b] = f_max[b] = B;
            if(A<=B){ // nao decrescente
                for(int64 i=a+1;i<b;++i) { f_min[i] = A; f_max[i] = B; }
            } else { // nao crescente
                for(int64 i=a+1;i<b;++i) { f_min[i] = B; f_max[i] = A; }
            }
        }

        int64 minSum = weighted_sum(f_min);
        int64 maxSum = weighted_sum(f_max);
        int64 target = 2*Y;

        if(target<minSum || target>maxSum){
            cout << "N\n";
            continue;
        }
        if((target-minSum)%2!=0){
             cout << "N\n";
             continue;
        }

        vector<int64> f(n+1,0);
        for(auto &p : known) f[p.first] = p.second;

        for(auto &p : segs){
            int64 a = p.first, b = p.second;
            int64 A = known[a], B = known[b];
            
            if(A<=B) for(int64 i=a+1;i<=b-1;i++) f[i] = A;
            else for(int64 i=a+1;i<=b-1;i++) f[i] = B;
        }

        int64 curSum = weighted_sum(f);
        int64 delta = target - curSum;

        reverse(segs.begin(), segs.end());

        for(auto &p : segs){
            if(delta==0) break;
            int64 a = p.first, b = p.second;
            int64 A = known[a], B = known[b];

            if(a+1>b-1) continue;

            if(A<=B){
                for(int64 i=b-1;i>=a+1 && delta>0;i--){
                    int w = weight(i,n);
                    // a capacidade eh limitada pelo vizinho da direita.
                    int64 cap = f[i+1]-f[i];
                    if(cap<=0) continue;
                    
                    int64 can_add = delta/w;
                    if(can_add<=0) continue;
                    
                    int64 add = min(cap,can_add);
                    f[i] += add;
                    delta -= add*w;
                }
            }else{
                int64 k = b-a-1;
                if(k<=0) continue;

                int64 current_segment_sum = 0;
                for (int64 i = a+1;i<b;++i) current_segment_sum += f[i];

                int64 max_segment_sum = k*A; // f[i] pode ser no max A

                int64 sum_capacity = max_segment_sum-current_segment_sum;
                int64 delta_capacity = sum_capacity*2;
                
                int64 delta_to_add = min(delta,delta_capacity);
                if (delta_to_add<=0) continue;

                int64 sum_to_add = delta_to_add/2;
                
                int64 avg = sum_to_add/k;
                int64 rem = sum_to_add%k;

                for (int64 i=a+1;i<b;++i) f[i] += avg;
                // manter f[i] >= f[i+1]
                for (int64 i=0;i<rem;++i) f[a+1+i]++;
                delta -= delta_to_add;
            }
        }

        if(delta!=0){
            cout << "N\n";
            continue;
        }

        // checagem de violacao
        bool violation = false;
        for(auto const& p : segs){
            int64 a = p.first, b = p.second;
            int64 A = known[a], B = known[b];
            if (A<=B){
                for(int i=a;i<b;++i) if(f[i]>f[i+1]) violation = true;
            }else{
                for(int i=a;i<b;++i) if(f[i]<f[i+1]) violation = true;
            }
            if(violation) break;
        }

        if(violation){
             cout << "N\n";
             continue;
        }

        cout << "S";
        for(int64 i = 0; i <= n; i++){
            if(!known.count(i)) cout << " " << f[i];
        }
        cout << "\n";
    }

    return 0;
}
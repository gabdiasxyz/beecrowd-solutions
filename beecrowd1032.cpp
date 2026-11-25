#include <bits/stdc++.h>
using namespace std;

// a gnt precisa de N-1 primos. max N eh 3501 -> 3500 primos
// 3500th primo eh 32713 -> sieve até 32800

const int MAX_PRIME_LIMIT = 32800;
const int MAX_N = 3501;

vector<int> primes;
bool is_prime[MAX_PRIME_LIMIT];

void precompute_primes(){
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for(int p=2;p*p<MAX_PRIME_LIMIT;p++){
        if(is_prime[p]) for(int i=p*p;i<MAX_PRIME_LIMIT;i+=p) is_prime[i] = false;
    }
    for(int p=2;p<MAX_PRIME_LIMIT && primes.size()<MAX_N;p++){
        if(is_prime[p]) primes.push_back(p);
    }
}

int solve(int N){
    vector<int> people(N);
    iota(people.begin(),people.end(),1); // 1,2,3 .. N
    int current_pos = 0;
    for(int i=0;i<N-1;i++){
        int remove = (current_pos+primes[i]-1)%people.size();
        people.erase(people.begin()+remove);
        current_pos = remove;
    }
    return people[0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_primes();
    int N;
    while(cin>>N && N!=0){ cout << solve(N) << '\n'; }

    return 0;
}
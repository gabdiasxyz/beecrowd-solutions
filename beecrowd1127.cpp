#include <bits/stdc++.h>
using namespace std;


// coverte uma nota pra sua posicao na escala
int note_position(const string& note) {
    static map<string, int> note_map = {
        {"B#",0}, {"C",0},
        {"C#",1}, {"Db",1},
        {"D",2},
        {"D#",3}, {"Eb",3},
        {"E",4}, {"Fb",4},
        {"E#",5}, {"F",5},
        {"F#",6}, {"Gb",6},
        {"G",7},
        {"G#",8}, {"Ab",8},
        {"A",9},
        {"A#",10}, {"Bb",10},
        {"B",11}, {"Cb",11}
    };
    return note_map[note];
}

// preprocessamento pro KMP
void computeLPS(const vector<int>& pattern,vector<int>& lps){
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while(i<pattern.size()){
        if(pattern[i]==pattern[length]){
            length++;
            lps[i] = length;
            i++;
        }else{
            if(length!=0) length = lps[length-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Knurth-Morris-Pratt search -> checa se a 'pattern' existe no texto
bool KMPsearch(const vector<int>& text,const vector<int>& pattern){
    if(pattern.empty()) return true;
    if(text.size()<pattern.size()) return false;

    vector<int> lps(pattern.size());
    computeLPS(pattern,lps);
    
    int i = 0, j = 0;
    while(i<text.size()){
        if(pattern[j]==text[i]){ i++; j++; }
        if(j==pattern.size()) return true; // pattern found
        else if(i<text.size() && pattern[j]!=text[i]){
            if(j!=0) j = lps[j-1];
            else i++;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M,T;
    while(cin>>M>>T && (M!=0 || T!=0)){
        vector<int> song_notes(M);
        for(int i=0;i<M;i++){
            string note_str;
            cin >> note_str;
            song_notes[i] = note_position(note_str);
        }

        vector<int> snippet_notes(T);
        for(int i=0;i<T;i++){
            string note_str;
            cin >> note_str;
            snippet_notes[i] = note_position(note_str);
        }

        if(T==1){
            cout << 'S' << endl;
            continue;
        }

        // os intervalos sao o numero de semitons pra ir pra proxima nota
        // -> (next_notas - current_notas + 12)%12
        vector<int> song_intervals(M-1);
        for(int i=0;i<M-1;i++) song_intervals[i] = (song_notes[i+1]-song_notes[i]+12)%12;
        vector<int> snippet_intervals(T-1);
        for(int i=0;i<T-1;i++) snippet_intervals[i] = (snippet_notes[i+1]-snippet_notes[i]+12)%12;

        if(KMPsearch(song_intervals,snippet_intervals)) cout << 'S' << endl;
        else cout << 'N' << endl;
    }

    return 0;
}
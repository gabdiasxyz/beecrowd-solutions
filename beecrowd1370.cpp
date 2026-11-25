#include <bits/stdc++.h>
using namespace std;

struct point {
    double x,y;
};
struct segment {
    point p1,p2;
};

double distance(point p1, point p2){ return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)); }

// orientacao da triplicie (p,q,r)
// 0 -> colineares ; 1 -> horario ; 2 -> antihorario
int orientation(point p, point q, point r){
    double val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    if(abs(val)<1e-9) return 0;
    return (val>0) ? 1 : 2;
}

bool on_segment(point p, segment s){ // rounding float error....
    return (p.x<=max(s.p1.x,s.p2.x)+1e-9 && p.x>=min(s.p1.x, s.p2.x)-1e-9 &&
            p.y<=max(s.p1.y,s.p2.y)+1e-9 && p.y>=min(s.p1.y,s.p2.y)-1e-9);
}

bool intersects(segment s1, segment s2){
    point p1 = s1.p1; point q1 = s1.p2;
    point p2 = s2.p1; point q2 = s2.p2;

    int o1 = orientation(p1,q1,p2);
    int o2 = orientation(p1,q1,q2);
    int o3 = orientation(p2,q2,p1);
    int o4 = orientation(p2,q2,q1);

    // caso geral -> eles se cruzam
    if(o1!=o2 && o3!=o4) return true;

    // casos especiais de colinearidade
    if(o1==0 && on_segment(p2,s1)) return true;
    if(o2==0 && on_segment(q2,s1)) return true;
    if(o3==0 && on_segment(p1,s2)) return true;
    if(o4==0 && on_segment(q1,s2)) return true;

    return false;
}

bool shares_endpoint(segment a, segment b) {
    return (distance(a.p1,b.p1)<1e-9 || distance(a.p1,b.p2)<1e-9 ||
            distance(a.p2,b.p1)<1e-9 || distance(a.p2,b.p2)<1e-9);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    point start, finish;
    int n;
    while(cin >> start.x >> start.y >> finish.x >> finish.y >> n && (start.x!=0 || start.y!=0 || finish.x!=0 || finish.y!=0 || n!=0)){
        vector<segment> obstacles(n);
        vector<point> nodes;
        nodes.push_back(start);
        nodes.push_back(finish);

        for(int i=0;i<n;i++){
            cin >> obstacles[i].p1.x >> obstacles[i].p1.y >> obstacles[i].p2.x >> obstacles[i].p2.y;
            nodes.push_back(obstacles[i].p1);
            nodes.push_back(obstacles[i].p2);
        }

        int num_nodes = nodes.size();
        vector<vector<double>> adj(num_nodes,vector<double>(num_nodes,-1.0));

        for(int i=0;i<num_nodes;i++){
            for(int j=i+1;j<num_nodes;j++){
                segment path = {nodes[i],nodes[j]};
                bool clear_path = true;

                for(int k=0;k<n;k++){
                    if(intersects(path,obstacles[k]) && !shares_endpoint(path,obstacles[k])){
                        clear_path = false;
                        break;
                    }
                }

                if(clear_path) adj[i][j] = adj[j][i] = distance(nodes[i],nodes[j]); //  ij = ji pra tornar o grafo nao direcional
            }
        }

        // dijkstra
        vector<double> min_dist(num_nodes,numeric_limits<double>::max());
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;

        min_dist[0] = 0; pq.push({0.0,0});

        while(!pq.empty()){
            double d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d>min_dist[u]) continue;
            if(u==1) break; // chegou no final
            
            for(int v=0;v<num_nodes;v++){
                if(adj[u][v]>=0 && min_dist[u]+adj[u][v]<min_dist[v]){
                    min_dist[v] = min_dist[u]+adj[u][v];
                    pq.push({min_dist[v],v});
                }
            }
        }

        cout << fixed << setprecision(2) << min_dist[1] << endl;
    }

    return 0;
}
#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long int64;

struct point { double x,y; };
double dist_matrix[45][45];
point g_pts[45];
int64 masks[2000];
int64 pruned[2000];
int counts[2000];

inline int popcount(int64 n){ // super fast bit counting
    n = n-((n>>1)&0x5555555555555555LL);
    n = (n&0x3333333333333333LL)+((n>>2)&0x3333333333333333LL);
    return (int)((((n+(n>>4))&0x0F0F0F0F0F0F0F0FLL)*0x0101010101010101LL)>>56);
}

bool can_cover(int N,double R) {
    if(N<=2) return true;

    const double R2 = R*R+1e-9;
    const double diam2 = 4.0*R*R;
    const int64 target = (1LL<<N)-1;
    int mCount = 0;

    for(int i=0;i<N;i++){
        int64 m = 0;
        for(int k=0;k<N;k++){
            if(dist_matrix[i][k]<=R2) m |= (1LL<<k);
        }
        if(m==target) return true;
        if(m>0) masks[mCount++] = m;
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            double d2 = dist_matrix[i][j];
            if(d2>diam2 || d2<1e-9) continue;
            double d = sqrt(d2);
            double midX = (g_pts[i].x+g_pts[j].x)/2.0;
            double midY = (g_pts[i].y+g_pts[j].y)/2.0;
            double h = sqrt(max(0.0,R*R-d2/4.0));
            double vx = (g_pts[j].x-g_pts[i].x)/d;
            double vy = (g_pts[j].y-g_pts[i].y)/d;

            for(double sign : {1.0,-1.0}){
                double cx = midX+sign*h*(-vy);
                double cy = midY+sign*h*vx;
                int64 m = (1LL<<i) | (1LL<<j);
                for(int k=0;k<N;k++){
                    if(k==i || k==j) continue;
                    double dx = cx-g_pts[k].x;
                    double dy = cy-g_pts[k].y;
                    if(dx*dx+dy*dy<=R2) m |= (1LL<<k);
                }
                if(m==target) return true;
                masks[mCount++] = m;
            }
        }
    }

    sort(masks,masks+mCount,greater<int64>());
    int uniqueCount = unique(masks,masks+mCount)-masks;

    int prunedCount = 0;
    for(int i=0;i<uniqueCount;i++){
        int64 m = masks[i];
        bool redundant = false;
        for(int k=0;k<prunedCount;k++){
            if((m&pruned[k])==m){
                redundant = true;
                break;
            }
        }
        if(!redundant){
            pruned[prunedCount] = m;
            counts[prunedCount] = popcount(m);
            prunedCount++;
        }
    }

    for(int i=0;i<prunedCount;i++){
        for(int j=i;j<prunedCount;j++){
            if(counts[i]+counts[j]<N) continue;
            if((pruned[i]|pruned[j])==target) return true;
        }
    }

    return false;
}

int main(){
    int N;
    while(scanf("%d",&N)==1 && N!=0){
        for (int i=0;i<N;i++) scanf("%lf %lf",&g_pts[i].x,&g_pts[i].y);

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                double dx = g_pts[i].x-g_pts[j].x;
                double dy = g_pts[i].y-g_pts[j].y;
                dist_matrix[i][j] = dx*dx+dy*dy;
            }
        }

        // binary search for the minimum radius
        /*
        max x/y = 10000 -> mdist = sqrt(10000^2 + 10000^2) = 14142.14
        error after 30 iter = 14142.14/2^30 = 0.000013
        */
        double low = 0, high = 14200;
        for(int iter=0;iter<30;iter++){
            double mid = (low+high)/2.0;
            if(can_cover(N,mid)) high = mid;
            else low = mid;
        }
        printf("%.2f\n",high);
    }
    return 0;
}
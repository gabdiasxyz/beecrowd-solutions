#include <cstdio>
using namespace std;

int main(){
    double R,H,V,G;
    while(scanf("%lf %lf %lf %lf",&R,&H,&V,&G)==4){
        // formula para x_max de um projetil lançado de altura h com vel inicial v e grav g
        // x_max = (V/G)*sqrt(V*V + 2.0*G*H);
        // elevar ao quadrado pra nao usar sqrt:

        double v_sq = V*V;
        double r_sq = R*R;
        double g_sq = G*G;

        double x_max = (v_sq/g_sq)*(v_sq + 2.0*G*H);

        if(x_max>r_sq) printf("Y\n");
        else printf("N\n");
    }

    return 0;
}
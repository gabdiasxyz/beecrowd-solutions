#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int64 gcd(int64 a,int64 b){
    return std::gcd(std::abs(a),std::abs(b));
}

struct point {
    int u, v;
    int64 val;
};

// node da KD-tree
struct node {
    point pt;
    int64 subtree_gcd;
    node *left = nullptr, *right = nullptr;
    int min_u, max_u, min_v, max_v;

    node() = default;

    node(point p) : pt(p){
        subtree_gcd = p.val;
        min_u = max_u = p.u;
        min_v = max_v = p.v;
    }
};

// usar pool fixa por causa de memory leaks
const int MAX_NODES = 200005; // max Q eh 10^5, multiplicado por 2 por q sao 2 arvores
node node_pool[MAX_NODES];
int node_idx;
node* new_node(point p){
    node_pool[node_idx] = node(p);
    return &node_pool[node_idx++];
}

void update_node(node* nd){
    if(!nd) return;

    nd->min_u = nd->max_u = nd->pt.u;
    nd->min_v = nd->max_v = nd->pt.v;
    nd->subtree_gcd = nd->pt.val;

    if(nd->left){
        nd->min_u = min(nd->min_u,nd->left->min_u);
        nd->max_u = max(nd->max_u,nd->left->max_u);
        nd->min_v = min(nd->min_v,nd->left->min_v);
        nd->max_v = max(nd->max_v,nd->left->max_v);
        nd->subtree_gcd = gcd(nd->subtree_gcd,nd->left->subtree_gcd);
    }
    if(nd->right){
        nd->min_u = min(nd->min_u,nd->right->min_u);
        nd->max_u = max(nd->max_u,nd->right->max_u);
        nd->min_v = min(nd->min_v,nd->right->min_v);
        nd->max_v = max(nd->max_v,nd->right->max_v);
        nd->subtree_gcd = gcd(nd->subtree_gcd,nd->right->subtree_gcd);
    }
}

node* insert(node* nd, point p, int depth){
    if(!nd) return new_node(p);
    if(nd->pt.u==p.u && nd->pt.v==p.v){
        nd->pt.val = p.val;
        update_node(nd);
        return nd;
    }

    bool split_u = (depth%2==0);

    if(split_u){
        if(p.u<nd->pt.u) nd->left = insert(nd->left,p,depth+1);
        else nd->right = insert(nd->right,p,depth+1);
    }else{
        if(p.v<nd->pt.v) nd->left = insert(nd->left,p,depth+1);
        else nd->right = insert(nd->right,p,depth+1);
    }

    update_node(nd);
    return nd;
}

struct QueryBox{ int min_u,max_u,min_v,max_v; };

int64 query(node* nd, const QueryBox& box){
    if(!nd || nd->max_u<box.min_u || nd->min_u>box.max_u || nd->max_v<box.min_v || nd->min_v>box.max_v) return 0; // sem interceção
    if(nd->min_u>=box.min_u && nd->max_u<=box.max_u && nd->min_v>=box.min_v && nd->max_v<=box.max_v) return nd->subtree_gcd; // 100% contida

    int64 result = 0;
    bool in_box = (nd->pt.u>=box.min_u && nd->pt.u<=box.max_u &&
                   nd->pt.v>=box.min_v && nd->pt.v<=box.max_v);

    if(in_box && nd->pt.val!=0) result = nd->pt.val;

    result = gcd(result,query(nd->left,box));
    result = gcd(result,query(nd->right,box));

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    while(cin>>Q){
        node_idx = 0;
        node *root_even = nullptr;
        node *root_odd = nullptr;

        for(int i=0;i<Q;i++){
            string type;
            cin >> type;
            if(type=="SET"){
                int x,y; int64 val;
                cin >> x >> y >> val;
                int u = x+y;
                int v = x-y;
                point p = {u,v,val};
                if(abs(u)%2==0) root_even = insert(root_even,p,0);
                else root_odd = insert(root_odd,p,0);
            }else{ // QUERY
                int x,y,d;
                cin >> x >> y >> d;
                int uc = x+y;
                int vc = x-y;
                QueryBox box = {uc-d,uc+d,vc-d,vc+d};

                int64 gcd_even = query(root_even,box);
                int64 gcd_odd = query(root_odd,box);

                cout << gcd(gcd_even,gcd_odd) << '\n';
            }
        }
    }

    return 0;
}
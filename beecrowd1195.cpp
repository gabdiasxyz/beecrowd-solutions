#include <bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node *left;
    node *right;

    node(int k) : key(k),left(nullptr),right(nullptr) {}
    node() : key(0),left(nullptr),right(nullptr) {} // pro vector<node> funcionar
};

// usar node_pool pra otimizar o insert, e nao precisar de free_tree
void insert(node* &root,int key,vector<node>& node_pool,int& node_idx){
    if(root==nullptr){
        node_pool[node_idx].key = key;
        root = &node_pool[node_idx];
        node_idx++;
        return;
    }
    if(key < root->key) insert(root->left,key,node_pool,node_idx);
    else insert(root->right,key,node_pool,node_idx);
}

void pre_ord(node* root){
    if(root==nullptr) return;
    cout << " " << root->key;
    pre_ord(root->left);
    pre_ord(root->right);
}
void in_ord(node* root){
    if(root==nullptr) return;
    in_ord(root->left);
    cout << " " << root->key;
    in_ord(root->right);
}
void post_ord(node* root){
    if(root==nullptr) return;
    post_ord(root->left);
    post_ord(root->right);
    cout << " " << root->key;
}
/*
void free_tree(node* root){
    if(root==nullptr) return;
    free_tree(root->left);
    free_tree(root->right);
    delete root;
}*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    cin >> C;

    for(int ncase=1;ncase<=C;ncase++){
        node* root = nullptr;
        int N;
        cin >> N;

        vector<node> node_pool(N);
        int node_idx = 0;

        for(int i=0;i<N;i++){
            int key;
            cin >> key;
            insert(root,key,node_pool,node_idx);
        }

        cout << "Case " << ncase << ":\n";

        cout << "Pre.:";
        pre_ord(root);
        cout << '\n';

        cout << "In..:";
        in_ord(root);
        cout << '\n';

        cout << "Post:";
        post_ord(root);
        cout << '\n';

        cout << '\n';
    }

    return 0;
}
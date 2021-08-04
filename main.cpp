#include <bits/stdc++.h>
using namespace std;

const int mxn=1e5+5;
const int Log=18;
vector<int> tree[mxn];
vector<int> depth(mxn,0);
vector<vector<int>> par(mxn,vector<int>(18));

void dfs(int root,int pr){
    for(auto x:tree[root]){
        if(x==pr) continue;
        par[x][0]=root;
        depth[x]=depth[root]+1;
        for(int i=1;i<Log;i++){
            par[x][i]=par[par[x][i-1]][i-1];
        }
        dfs(x,root);
    }
}
int lca(int a,int b){
    if(depth[a]<depth[b]){
        swap(a,b);
    }
    int d=depth[a]-depth[b];
    for(int i=Log-1;i>=0;i--){
        if(d&(1<<i)){
            a=par[a][i];
        }
    }
    if(a==b) return a;
    for(int i=Log-1;i>=0;i--){
        if(par[a][i]!=par[b][i]){
            a=par[a][i];b=par[b][i];
        }
    }
    return par[a][0];
}
int main(){
    // Taking input of number of nodes and number of edges.
    // Adding the edges between nodes in Tree.
    // dfs call : dfs(1,-1).
    // Query call : lca(a,b) returns -> lca of the nodes a and b.
}

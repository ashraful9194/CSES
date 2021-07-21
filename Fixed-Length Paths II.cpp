#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, greater<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
const int mx=2e5;
vector<int>adj[mx+5];
int done[mx+5];
int sub[mx+5];
int fen_tree[mx+5];
int mx_depth;
int n,k1,k2;
int ans;
void add(int idx, int x)
{
    ++idx;
    for(int i=idx; i<=n+1; i+=(i & -i)) fen_tree[i]+=x;
}
int query(int l,int r){
    int sum=0;
    ++r;
    for(int i=r; i; i-=(i & -i)) sum+=fen_tree[i];
    for(int i=l; i; i-=(i & -i)) sum-=fen_tree[i];
    return sum;
}
void dfs(int node,int par)
{

    sub[node]=1;
    for(auto son:adj[node])
    {
        if(son==par || done[son]) continue;
        dfs(son,node);
        sub[node]+=sub[son];
    }
}
void dfs2(int node,int par,int ok,int depth=1)
{

    if(depth>k2) return;
    mx_depth=max(mx_depth,depth);
    if(ok)
    {
        ans+=query(max(0LL,k1-depth),k2-depth);
    }
    else
    {
        add(depth,1);
    }
    for(auto son:adj[node])
    {
        if(son==par || done[son]) continue;
        dfs2(son,node,ok,depth+1);
    }
}
int find_centroid(int node,int par,int root)
{

    for(auto son:adj[node])
    {
        if(son==par || done[son]) continue;
        if(sub[son]>sub[root]/2) return find_centroid(son,node,root);
    }
    return node;
}
void decompose(int node)
{
     dfs(node,-1);
     int centroid=find_centroid(node,-1,node);
     done[centroid]=1;
     mx_depth=0;

     for(auto son:adj[centroid])
     {
         if(done[son]) continue;
         dfs2(son,centroid,1);
         dfs2(son,centroid,0);
     }
    for (int i = 1; i <= mx_depth; i++)
    {
       // cout<<query(i,i)<<endl;
        add(i, -query(i,i));
    }
        for(auto son:adj[centroid])
     {
         if(done[son]) continue;
         decompose(son);
     }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n>>k1>>k2;
     for(int i=0; i<n-1; i++)
     {
         int x,y;
         cin>>x>>y;
         adj[x].pb(y);
         adj[y].pb(x);
     }
     add(0,1);
     decompose(1);
     cout<<ans<<endl;
}

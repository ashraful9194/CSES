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
int n,m;
vector<int>adj[200005];
int LCA[200005][35];
int level[200005];
int ans[200005];
void dfs(int node,int par)
{
    LCA[node][0]=par;
    level[node]=1+level[par];
    for(auto son:adj[node])
    {
        if(son==par) continue;
         dfs(son,node);
    }
}
void init()
{
    dfs(1,0);
    for(int i=1; i<=25; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int ancestor=LCA[j][i-1];
            if(ancestor<=0) continue;
            LCA[j][i]=LCA[ancestor][i-1];///Because 2^i=2^(i-1)+2^(i-1)................
        }
    }
}
int lowest_common_ancestor(int a,int b)
{
   if(level[a]>level[b]) swap(a,b);
   int d=level[b]-level[a];
   while(d)
   {
       int x=log2(d);
       d-=(1<<x);
       b=LCA[b][x];
   }
   if(a==b) return  a;
   for(int i=25; i>=0; i--)
   {
       if(LCA[a][i]<=0 || LCA[a][i]==LCA[b][i]) continue;
       a=LCA[a][i],b=LCA[b][i];
   }
   return  LCA[a][0];
}
void dfs2(int node,int par)
{
    for(auto son:adj[node])
    {
        if(son==par) continue;
        dfs2(son,node);
        ans[node]+=ans[son];
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n>>m;
     for(int i=0; i<n-1; i++)
     {
         int x,y;
         cin>>x>>y;
         adj[x].pb(y);
         adj[y].pb(x);
     }
     init();
     while(m--)
     {
         int x,y;
         cin>>x>>y;
         int lca=lowest_common_ancestor(x,y);
         ++ans[x];
         ++ans[y];
         --ans[lca];
         --ans[LCA[lca][0]];
     }
     dfs2(1,0);
     for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
     cout<<endl;

}


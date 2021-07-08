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
int n;
const int mx=2e5+5;
vector<int>adj[mx];
int ans[mx];
int sub[mx];
///Finding the answer by reroorting the child.
void dfs1(int node,int par,int depth)
{
    ans[1]+=depth;
    sub[node]=1;
    for(auto son:adj[node])
    {
        if(son==par) continue;
        dfs1(son,node,depth+1);
        sub[node]+=sub[son];
    }
}
void dfs2(int node,int par)
{
    for(auto son:adj[node])
    {
        if(son==par) continue;
        ans[son]=ans[node]+n-(2*sub[son]);
        dfs2(son,node);
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     cin>>n;
     for(int i=0; i<n-1; i++)
     {
         int x,y;
         cin>>x>>y;
         adj[x].pb(y);
         adj[y].pb(x);
     }
     dfs1(1,0,0);
     dfs2(1,0);
     for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
     cout<<endl;

}


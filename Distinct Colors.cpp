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
int in_time[mx+5],flattering[mx+5],col[mx+5],sub[mx+5],ans[mx+5],fen_tree[mx+5];
map<int,int>vis;
int n,tme;
vector<pii>v[mx+5];
void dfs(int node,int par)
{
    in_time[node]=++tme;
    flattering[tme]=col[node];
    sub[node]=1;
    for(auto son:adj[node])
    {
        if(son==par) continue;
        dfs(son,node);
        sub[node]+=sub[son];
    }
}
void add(int idx, int x)
{
       while(idx<=n)
       {
             fen_tree[idx]+=x;
             idx += idx & (-idx);
       }
}
int query(int idx){
       int sum=0;
       while(idx>0){
             sum+=fen_tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ///To find the number of distinct values in a range just keep track the last index of every value
     ///And update the BIT with -1/+1 according to the situation................................
     cin>>n;
     for(int i=1; i<=n; i++) cin>>col[i];

     for(int i=0; i<n-1; i++)
     {
         int x,y;
         cin>>x>>y;
         adj[x].pb(y);
         adj[y].pb(x);
     }
     dfs(1,0);
     for(int i=1; i<=n; i++)
     {
         int l=in_time[i];
         int r=l+sub[i]-1;
        v[r].pb({l,i});
     }
     for(int i=1; i<=n; i++)///intime
     {
         if(vis[flattering[i]])  add(vis[flattering[i]],-1);

         add(i,1);
         vis[flattering[i]]=i;
         for(auto j:v[i])
         {
             ans[j.second]=query(i)-query(j.first-1);
         }
     }
     for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
     cout<<endl;
}


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
const int mx=2e5+5;
int a[mx];
vector<int>adj[mx];
int sub[mx];
int timee;
int in[mx];
int fen_tree[mx];
int arr[mx];
void dfs(int node,int par)
{
    sub[node]=1;
    in[node]=++timee;
    arr[timee]=a[node];
    for(auto son:adj[node])
    {
        if(son==par) continue;
        dfs(son,node);
        sub[node]+=sub[son];
    }
}
void add(int idx, int x, int n)
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
     int n,q;
     cin>>n>>q;
     for(int i=1; i<=n; i++) cin>>a[i];
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
          add(in[i],a[i],timee);
     }
     while(q--)
     {
         int op;
         cin>>op;
         if(op==1)
         {
             int node,val;
             cin>>node>>val;
             add(in[node],val-a[node],n);
             a[node]=val;
         }
         else
         {
             int node;
             cin>>node;
             cout<<query(in[node]+sub[node]-1)-query(in[node]-1)<<endl;
         }
     }
}

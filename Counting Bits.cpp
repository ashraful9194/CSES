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
int dp[70][70][2];
int n;
int solve(int pos,int cnt,int is_small)
{
    if(pos==-1) return cnt;
    int &ans=dp[pos][cnt][is_small];
    if(ans!=-1) return ans;
    if(is_small)
    {
        int x=solve(pos-1,cnt+1,is_small);
        int y=solve(pos-1,cnt,is_small);
        return ans=x+y;
    }
    else
    {
        if((1LL<<pos)&n)
        {
             int x=solve(pos-1,cnt+1,0);
             int y=solve(pos-1,cnt,1);
             return ans=x+y;
        }
        else
        {
            return ans=solve(pos-1,cnt,0);
        }
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     cin>>n;
     memset(dp,-1,sizeof dp);
     int pos=0;
     for(int i=55; i>=0; i--)
     {
         if(((1LL<<i)&n))
         {
             pos=i;
             break;
         }
     }
     int ans=solve(pos,0,0);
     cout<<ans<<endl;

}


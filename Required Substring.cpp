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
int dp[1005][105];
int lps[105][26];
int n;
string s;
int sz;
const int p=1e9+7;
int power(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(res*a)%p;
        b>>=1;
        a=(a*a)%p;
    }
    return  res;
}
void lps_func()
{
    for(int i=1; i<sz; i++)
    {
        for(int k=0; k<26; k++)
        {
                char ch=k+'A';
                int j=lps[i-1][s[i-1]-'A'];
                while(j>0 && ch!=s[j])
                   j=lps[j-1][s[j-1]-'A'];
                 if(ch==s[j])
                  ++j;
                 lps[i][k]=j;
        }
    }
}
int solve(int pos,int cnt)
{
    if(cnt==sz) return  0;
    if(pos==n) return  1;
    int &ans=dp[pos][cnt];
    if(ans!=-1) return  ans;
     int res=0;
    for(char ch='A'; ch<='Z'; ch++)
    {
        if(s[cnt]==ch)  res=(res%p+solve(pos+1,cnt+1)%p)%p;

        else res=(res%p+solve(pos+1,lps[cnt][ch-'A'])%p)%p;
    }
    return ans=res;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n>>s;
     memset(dp,-1,sizeof dp);
     sz=s.size();
     lps_func();
     int ans=(power(26,n)-solve(0,0)+p)%p;
     cout<<ans<<endl;
}

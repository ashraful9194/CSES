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

int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     /*
     Suppose we partition the string into k contiguous subsegments such that the letters GCAT all appear at least once each in each partition.
     Then, it is clear that all k-character strings appear as subsequences.

   We can construct such a partition greedily. Find the shortest prefix of the string that contains all characters GCAT,
   make that one subsegment, then recurse on the remaining string. Note that this might actually partition it into k+1 subsegments,
   where the last subsegment is ``incomplete''.
  The last character in each subsegment (besides the incomplete subsegment) also appears exactly once in that subsegment;
   greedily, if it appeared earlier in the subsegment, then we could have ended this partition earlier.

  If k is maximal, then we can show that there exists a k+1 length string that is not a subsequence.
  How? We can explicitly construct it as the last character in each of the partitions,
  plus some character not in the incomplete subsegment (or any character, if there is no incomplete subsegment).
     */
     string s;
     cin>>s;
     string ans;
     set<char>st;
     for(auto i:s)
     {
         st.insert(i);
         if(st.size()==4)
         {
             ans.pb(i);
             st.clear();
         }
     }
     for(auto i:"ATGC")
     {
         if(!st.count(i))
         {
             ans.pb(i);
             break;
         }
     }
     cout<<ans<<endl;

}


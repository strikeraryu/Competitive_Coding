// link of the question https://www.codechef.com/LTIME85B/problems/MAXAND18/

// 100% - all SubTask passed


#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<pair<long long int,int>> dp;
    int bit = 1;
    for(int i=0;i<32;i++){
      long long int sum = 0;
      int x = bit<<i;
      for(int j=0;j<n;j++){
        if((v[j]&(bit<<i))==(bit<<i))sum+=(bit<<i);
      }
      dp.push_back({sum,i});
    }
    sort(dp.begin(),dp.end(),[](pair<long long int,int> a,pair<long long int,int> b){
        if(a.first==b.first)return a.second<b.second;
        else return a.first>b.first;
    });
    int ans = 0;
    for(int i=0;i<k;i++)ans = ans|(bit<<dp[i].second);
    cout<<ans<<endl;
  }
  return 0;
}
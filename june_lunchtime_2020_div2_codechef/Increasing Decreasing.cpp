// link of the question https://www.codechef.com/LTIME85B/problems/INCRDEC/

// 100% - all SubTask passed


#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> v(n);
    set<int> inc,dec;
    set<int>::iterator itr;
    unordered_map<int,int> cnts;
    int max_val = 0;
    bool flg = true;
    for(int i=0;i<n;i++){
      cin>>v[i];
      cnts[v[i]]++;
      if(cnts[v[i]]==1)inc.insert(v[i]);
      else dec.insert(v[i]);
      if(cnts[v[i]]>2)flg = false;
      max_val = max(v[i],max_val);
      }
      if(cnts[max_val]>=2)flg = false;
      if(flg){
        cout<<"YES"<<endl;
        for(itr = inc.begin();itr!=inc.end();itr++)
        cout<<*itr<<" ";
        string ans = "";
        for(itr = dec.end();!dec.empty();itr--){
            if(itr==dec.end())continue;
            cout<<*itr<<" ";
            if(itr==dec.begin())break;
        }
        cout<<endl;
      }
      else cout<<"NO"<<endl;

  }
  return 0;
}
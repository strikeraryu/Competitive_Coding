// link of the question https://www.codechef.com/LTIME85B/problems/CHFMOT18

// 100% - all SubTask passed


#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int s,n,cnt=0;
    cin>>s>>n;
    while(s>1){
      if(s>=n){
        cnt+=s/n;
        s-=(s/n)*n;
      }
      n = min(s,n);
      if(n%2==1)n--;
    }
    if(s==1)cnt++;
    cout<<cnt<<endl;
  }
  return 0;
}   
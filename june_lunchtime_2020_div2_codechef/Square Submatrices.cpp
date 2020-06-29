// link of the problem https://www.codechef.com/LTIME85B/problems/SQRSUBMA/

// 50% - SubTask1 passed


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, x;
        scanf("%d %d",&n,&x);
        vector<int> v(n);
        vector<vector<int>> dp(n, vector<int>(n));
        map<pair<int,int>,int> cnts;
        for(int i=0;i<n;i++)scanf("%d",&v[i]);
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=v[j];
                dp[i][j] = sum;
                cnts[{sum,j-i+1}]++;
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(x%(j-i+1)==0){
                    int tmp = x/(j-i+1) - dp[i][j];
                    cnt+=cnts[{tmp,j-i+1}];
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
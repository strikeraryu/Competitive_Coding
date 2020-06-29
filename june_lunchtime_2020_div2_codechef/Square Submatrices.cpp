// link of the problem https://www.codechef.com/LTIME85B/problems/SQRSUBMA/

// 100% - all SubTask passed


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, x;
        long long int cnt=0;
        scanf("%d %d",&n,&x);
        vector<int> v(n);
        for(int i=0;i<n;i++)scanf("%d",&v[i]);
        vector<int> fcts;
        for(int i=1;i<=sqrt(x);i++){
            if(x%i==0){
                if(x/i!=i) fcts.push_back(x/i);
                fcts.push_back(i);
            }
        }
        for(int fct : fcts){
            int sum = 0;
            unordered_map<long long int, int> cnts;
            vector<long long int> subs;
            for(int i=0;i<n;i++){
                if(i>fct-1) sum-=v[i-fct];
                sum+=v[i];
                if(i>=fct-1 && sum<=x/fct){ 
                    cnts[sum]++; 
                    subs.push_back(sum);
                }
            }
            for(auto sub : subs){
                int tmp = x/fct - sub;
                if(cnts.count(tmp)!=0)
                cnt+=cnts[tmp];
            }
        }
        
        cout<<cnt<<endl;
    }
    return 0;
}
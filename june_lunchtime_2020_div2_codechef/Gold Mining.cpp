// link of the question https://www.codechef.com/LTIME85B/problems/GOLMINE

// 100% - all SubTask passed


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
      int n;
      scanf("%d",&n);
      double p, a, b, gold_a=0, gold_b=0;
      for(int i=0;i<n;i++){
          scanf("%lf %lf %lf",&p, &a, &b);
          gold_a += p*(b/(a+b));
          gold_b += p*(a/(a+b));
      }
      printf("%.5f %.5f\n",gold_a, gold_b);
    }
    return 0;
}
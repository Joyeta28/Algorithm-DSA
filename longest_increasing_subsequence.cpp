#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>res;
    res.push_back(v[0]);
    for(int i=1;i<n;i++){
        int ind = lower_bound(res.begin(),res.end(),v[i]) - res.begin();
        if(v[i]>res.back()){
            res.push_back(v[i]);
        }
        else{
            res[ind] = v[i];
        }
    }

    cout<<res.size()<<endl;
   }
}

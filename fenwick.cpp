#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getsum(vector<int>&bittree,int index){
    index = index+1;
    int sum =0;
    while(index>0){
        sum += bittree[index];
        index -= index & (-index);
    }
    return sum;
}

void updatebit(vector<int>&bittree,int n,int index,int value){
    index = index+1;
    while(index<=n){
        bittree[index] += value;
        index += index & (-index);
    }
}

vector<int> constructBit(vector<int>&fen,int n){
    vector<int>bittree(n+1,0);
    for(int i =0;i<n;i++){
        updatebit(bittree,n,i,fen[i]);
    }
    return bittree;
}


int getrangesum(vector<int>&bittree,int from,int to){
    return getsum(bittree,to) - getsum(bittree,from -1);

 }
int main() {
    vector<int>fen = {1,2,3,5,5,6};
    int n = fen.size();
    int q;
    cin>>q;
    vector<int> bittree = constructBit(fen,n);
    while(q--){
        int a,b;
        cin>>a>>b;
        a--,b--;
        int ans = getrangesum(bittree,a,b);
        cout<<ans<<endl;
    }
    updatebit(bittree,n,1,3);
    cout<<getrangesum(bittree,0,5);

}

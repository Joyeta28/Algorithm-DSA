#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>segmentTree;

void buildSegmentTree(int i,int l,int r,vector<int>&nums){
    if(l == r){
        segmentTree[i] = nums[l];
        return;
    }
    int mid = l+(r-l)/2;
    buildSegmentTree(2*i+1,l,mid,nums);
    buildSegmentTree(2*i+2,mid+1,r,nums);
    segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
}
int querySumSegmentTree(int start,int end,int l,int r,int i){
    if(end<l || start>r){
        return 0;
    }
    if(l>=start && r<=end){
        return segmentTree[i];
    }
    int mid = l+(r-l)/2;
    return querySumSegmentTree(start,end,l,mid,2*i+1) +
            querySumSegmentTree(start,end,mid+1,r,2*i+2);
}
int main() {
    vector<int>nums = {1,2,3,4,5,6,7};
    int n = nums.size();
    segmentTree.resize(4*n);
    buildSegmentTree(0,0,n-1,nums);
    cout<<querySumSegmentTree(2,4,0,n-1,0);
}

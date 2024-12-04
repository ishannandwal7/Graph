#include<bits/stdc++.h>
using namespace std;

int size = 1e5;
int segmentTree[4*size];

void build(int ind,int lo,int hi,vector<int>&arr){
    if(lo==hi){
        seg[ind]=arr[lo];
    }
    int mid=lo+hi;mid/=2;
    build(2*ind+1,lo,mid,arr);
    build(2*ind+2,mid+1,hi,arr);
}
int query(int ind,int lo,int hi,int L,int R){
    if(lo>=L && hi<=R){
        return seg[ind];
    }
    if(lo<L || hi>R){
        return INT_MIN;
    }
    int left = query(2*ind+1,lo,mid,L,R);
    int right = query(2*ind+2,mid+1,hi,L,R);
    return max(left,right);
}

void pointUpdate(int ind,int lo,int hi,int targetInd,int val){
    if(lo==hi && lo==targetInd){
        seg[ind]=val;
        return ;
    }
    int mid=lo+hi;mid/=2;
    if(targetInd<=mid){
        //GO left;
        pointUpdate(2*ind+1,lo,mid,targetInd,val);
    }else{
        // GO Right 
        pointUpdate(2*ind+2,mid+1,hi,targetInd,val);
    }
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
    return ;
}
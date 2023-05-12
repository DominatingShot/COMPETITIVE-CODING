#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;  
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n && k;i++){
        auto m=max_element(v.begin()+1+i,v.end());
        if(*m>v[i]){
            k--;
            swap(v[i],*m);
        }

    }
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
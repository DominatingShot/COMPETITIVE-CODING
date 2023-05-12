#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int minimumAbsoluteDifference(vector<int> arr) {
     sort(arr.begin(),arr.end());
     int d=abs(*(arr.begin())-*(arr.begin()+1));
     for(auto it=arr.begin()+2;it!=arr.end();it++){
        d=min(d,abs(*(it)-*(it-1)));
    }
    return d;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<minimumAbsoluteDifference(arr);
    return 0;
   
}

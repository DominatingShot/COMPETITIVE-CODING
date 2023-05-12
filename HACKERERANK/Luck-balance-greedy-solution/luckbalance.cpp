#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int luckBalance(int k, vector<vector<int>> v) {
           int l=0;
           sort(v.begin(),v.end());
           for(auto it=v.end()-1;it>=v.begin();it--){
         if((*it)[1]==0){
            l=l+(*it)[0];
         }
         else if(k>0){
            l=l+(*it)[0];
            k--;
         }
         else{
            l=l-(*it)[0];
            }
   }
    return l;           
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> v(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>v[i][j];
        }
    }
    int result=luckBalance(k,v);
    cout<<result;
    return 0;
}
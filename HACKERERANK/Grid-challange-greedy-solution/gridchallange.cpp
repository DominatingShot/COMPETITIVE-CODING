#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string gridChallenge(vector<string> v) {
   for(auto it=v.begin();it!=v.end();it++){
       sort(it->begin(),it->end());
   }
   for(int i=0;i<v.size()-1;i++){
       for(int j=0;j<v.size();j++){
           if(v[i][j]>v[i+1][j]){
               return "NO";
           }
       }
   }
    return "YES";
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<string> v(n);
        for(int j=0;j<n;j++){
            cin>>v[j];
        }
        string result=gridChallenge(v);
        cout<<result<<endl;
    }
    return 0;
    
}

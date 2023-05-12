#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> maximumPerimeterTriangle(vector<int> arr) {
      long p=0;
      int a=-1;
      int b=-1;
      int c=-1;
      sort(arr.begin(),arr.end());
      for(int i=0;i<arr.size()-2;i++){
            for(int j=i+1;j<arr.size()-1;j++){
                  for(int k=j+1;k<arr.size();k++){
                        if((long)arr[i]<(long)arr[j]+(long)arr[k] && (long)arr[j]<(long)arr[i]+(long)arr[k] && (long)arr[k]<(long)arr[i]+(long)arr[j]){
                              if((long)arr[i]+(long)arr[j]+(long)arr[k]>p){
                                    p=arr[i]+arr[j]+arr[k];
                                    a=arr[i];
                                    b=arr[j];
                                    c=arr[k];
                              }
                        }

                  }
            }
      }
      if (p!=0){
      vector<int> v1{a,b,c};
      return v1;
      }
      else{
      vector<int> v1{-1};
      return v1;
      }
      
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> result=maximumPerimeterTriangle(arr);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}

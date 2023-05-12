#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int beautifulPairs(vector<int> A, vector<int> B) {
    int count=0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B.size();j++){
            if(A[i]==B[j]){
                count++;
                B[j]=-1;
                break;
            }
        }
    }
    if(count==A.size()){
        return count-1;
    }
    else{
        return count+1;
    }

}
int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    vector<int> B(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    int result=beautifulPairs(A,B);
    cout<<result<<endl;
    return 0;
    
}
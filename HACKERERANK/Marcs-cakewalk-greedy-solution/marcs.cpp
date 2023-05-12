#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long marcsCakewalk(vector<int> calorie) {
   long p=0;
   sort(calorie.rbegin(),calorie.rend());
   for(int i=0;i<calorie.size();i++){
       p=p+(calorie[i]*(long)pow(2,i));
   }
   return p;
}
int main(){
    int n;
    cin>>n;
    vector<int> calorie(n);
    for(int i=0;i<n;i++){
        cin>>calorie[i];
    }
    long result=marcsCakewalk(calorie);
    cout<<result;
    return 0;
}
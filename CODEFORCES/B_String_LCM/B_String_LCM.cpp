#include <iostream>
using namespace std;
int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
int main(){
int t;
cin >> t;
for(int i=0;i<t;i++){
    string a,b;
    cin >> a;
    cin >> b;
    int n=a.size();
    int m=b.size();
    int lcm=(n*m)/gcd(n,m);
    string temp=a;
    string temp2=b;
    while(a.size()<lcm){
        a=a+temp;
    }
    while(b.size()<lcm){
        b=b+temp2;
    }
    if(a==b){
        cout << a << endl;
    }
    else{
        cout << -1 << endl;
    }
}
}


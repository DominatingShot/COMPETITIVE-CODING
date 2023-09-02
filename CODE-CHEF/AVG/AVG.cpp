#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        int n,k,v;
        cin>>n>>k>>v;
        int sum=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            sum+=x;
        }
        int ans=(v*(n+k)-sum)/k;
        if(ans>0 && (v*(n+k)-sum)%k==0){
            cout<<ans<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
	return 0;
}

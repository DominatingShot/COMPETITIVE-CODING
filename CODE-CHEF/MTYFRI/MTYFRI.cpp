#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> v1, v2;
        
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (j % 2 == 0)
                v1.push_back(x);
            else
                v2.push_back(x);
        }
        
        sort(v1.rbegin(), v1.rend());
        sort(v2.begin(), v2.end());
        
        int minsize = min(v1.size(), v2.size());
        int least = min(minsize, k);
        
        for (int j = 0; j < least; j++) {
            if (v1[j] > v2[j]) {
                swap(v1[j], v2[j]);
            } else {
                break;
            }
        }
        
        int sum1 = accumulate(v1.begin(), v1.end(), 0);
        int sum2 = accumulate(v2.begin(), v2.end(), 0);
        
        if (sum2 > sum1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
	
    return 0;
}

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    // Recursive function to find the greatest common divisor (GCD) of two numbers a and b.
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    int t;
    cin >> t;  // Read the number of test cases

    for (int i = 0; i < t; i++) {
        string a, b;
        cin >> a;  // Read the first string a
        cin >> b;  // Read the second string b

        int n = a.size();  // Get the length of string a
        int m = b.size();  // Get the length of string b

        int lcm = (n * m) / gcd(n, m);  // Calculate the least common multiple (LCM) of n and m

        string temp = a;  // Create a copy of string a
        string temp2 = b;  // Create a copy of string b

        // Extend string a to have a length of lcm by repeating its content
        while (a.size() < lcm) {
            a = a + temp;
        }

        // Extend string b to have a length of lcm by repeating its content
        while (b.size() < lcm) {
            b = b + temp2;
        }

        if (a == b) {
            cout << a << endl;  // If strings a and b are equal, output a (they are a match)
        } else {
            cout << -1 << endl;  // If they are not equal, output -1 (no match)
        }
    }
}


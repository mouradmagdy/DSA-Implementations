#include<iostream>
#include<string>
using namespace std;
int main() {
    string s = "145.25@";
    double fraction = 1.0;
    bool decimal = false;
    bool isNegative = false;
    double x = 0.0;
    int i = 0;
    if (s[i] == '-') {
        isNegative = true;
        i++;
    }
    while (i < s.size()) {
        if (s[i] == '.') {
            if (decimal) {
                cout << "Invalid, more than one decimal point found";
                return 0;
            }
            decimal = true;
            i++;
            continue;
        }
        if (s[i] < '0' || s[i] > '9') {
            cout << "Invalid string";
            return 0;
        }
        if (decimal) {
            fraction /= 10.0;
            x = x + (s[i] - '0') * fraction;
        } else {
            double y = s[i] - '0';
            x = x * 10 + y;
        }
        i++;
    }
    double ans = isNegative ? -x : x;
    cout << ans;
}

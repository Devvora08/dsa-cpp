#include <iostream>
using namespace std;

double calculate_power(double x, int n)
{
    long long power = n;   // handle INT_MIN safely
    double ans = 1.0;

    if (power < 0) {
        x = 1.0 / x;
        power = -power;
    }

    while (power > 0)
    {
        if (power % 2 == 1)
            ans *= x;

        x *= x;
        power /= 2;
    }

    return ans;
}

int main()
{
    double x = 2;
    int n = 5;

    double ans = calculate_power(x, n);
    cout << ans << endl;   // Output: 32

    return 0;
}
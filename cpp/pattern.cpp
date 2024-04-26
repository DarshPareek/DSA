#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<char> c = {'.', '*', '+', '='};
    for (int z = 0; z < 10; z++)
    {
        for (int i = 0; i < 2 * n - 1; i++)
        {
            for (int j = 0; j < 2 * n - 1; j++)
            {
                int d = 2 * n - 1 - i - 1;
                int s = 2 * n - 1 - j - 1;
                cout << c[n - min(min(i, j), min(d, s)) - 1];
            }
            cout << endl;
        }
    }
    cin >> n;
}
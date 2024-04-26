#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
int fib2(int n)
{
    vector<int> m = {0, 1};
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    for (int i = 2; i <= n; i++)
    {
        m.push_back(m[i - 2] + m[i - 1]);
    }
    return m[m.size() - 1];
}

int main()
{
    int n;
    cin >> n;
    clock_t tStart = clock();
    cout << fib(n) << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    clock_t tStart1 = clock();
    cout << fib2(n) << endl;
    printf("Time taken lol : %.2fs\n", (double)(clock() - tStart1) / CLOCKS_PER_SEC);
    return 0;
}

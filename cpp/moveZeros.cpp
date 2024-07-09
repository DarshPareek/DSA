#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &a)
{
    int n = a.size();
    int j = -1;
    // place the pointer j:
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }
    // no non-zero elements:
    if (j == -1)
        return;

    // Move the pointers i and j
    // and swap accordingly:
    for (int i = j + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
}
int main()
{
    vector<int> a = {0, 1, 0, 3, 12};
    moveZeroes(a);
    for (auto i : a)
    {
        cout << i << endl;
    }
    return 0;
}
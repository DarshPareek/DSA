#include <bits/stdc++.h>
using namespace std;

vector<int> seconds(vector<int> arr, int n)
{
    vector<int> res;
    if (n < 2)
    {
        return res;
    }
    int small = INT_MAX, second_small = INT_MAX, large = INT_MIN, second_large = INT_MIN;
    for (auto i : arr)
    {
        if (i > large)
        {
            second_large = large;
            large = i;
        }
        else if (i > second_large && i != large)
        {
            second_large = i;
        }
        if (i < small)
        {
            second_small = small;
            small = i;
        }
        else if (i < second_small && i != small)
        {
            second_small = i;
        }
    }
    res.push_back(second_large);
    res.push_back(second_small);
    return res;
}

int main()
{
    vector<int> ques = {4, 5, 3, 6, 7};
    vector<int> ans = seconds(ques, ques.size());
    cout << "Second Largest = " << ans[0] << endl;
    cout << "Second Smallest = " << ans[1] << endl;
    return 0;
}
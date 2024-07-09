#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int res = 1, seen = nums[0], i = 1, del = 0;
    while (i < nums.size())
    {
        // cout << seen << " " << i << " " << nums[i] << endl;
        if (seen == nums[i])
        {
            // cout << "erasing " << 0 + i << endl;
            nums.erase(nums.begin() + i);
            del++;
        }
        else
        {
            seen = nums[i];
            res++;
            i++;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int res = removeDuplicates(nums);
    for (auto i : nums)
    {
        cout << i << endl;
    }
}
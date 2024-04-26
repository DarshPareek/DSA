#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            cnt++;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        cnt++;
    }
    return cnt <= 1;
}
bool check(vector<int> &nums)
{
    vector<int> temp;
    if (nums.size() == 0 || nums.size() == 1)
    {
        return true;
    }
    for (auto i : nums)
    {
        temp.push_back(i);
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < nums.size(); i++)
    {
        int flag = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (temp[(j + i) % nums.size()] == nums[j])
            {
                flag++;
            }
            if (flag == nums.size())
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> ques = {4, 5, 3, 6, 7};
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &nums, int k)
{
    int m = 0;
    int i = 0, j = 0;
    int n = nums.size();
    long long s = nums[0];
    while (j < n)
    {
        while (s > k && i <= j)
        {
            s -= nums[i];
            i++;
        }
        if (s == k)
            m = max(m, (j - i) + 1);
        j++;
        if (j < n)
        {
            s += nums[j];
        }
    }
    return m;
}
int longestSubarray2(vector<int> &nums, int k)
{
    map<long long, int> preMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long rem = sum - k;
        if (preMap.find(rem) != preMap.end())
        {
            int len = i - preMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preMap.find(sum) == preMap.end())
        {
            preMap[sum] = i;
        }
    }
    return maxLen;
}
int longestSubarrayWithSumK(const std::vector<int> &arr, int k)
{
    std::unordered_map<long long, int> prefix_sum_map;
    long long current_sum = 0;
    int max_len = 0;
    prefix_sum_map[0] = -1;
    for (int i = 0; i < arr.size(); ++i)
    {
        current_sum += arr[i];
        long long required_sum = current_sum - k;
        if (prefix_sum_map.count(required_sum))
        {
            int current_length = i - prefix_sum_map[required_sum];
            max_len = std::max(max_len, current_length);
        }
        if (prefix_sum_map.find(current_sum) == prefix_sum_map.end())
        {
            prefix_sum_map[current_sum] = i;
        }
    }

    return max_len;
}

int main()
{
    vector<int> n = {-2, 1};
    cout << longestSubarray2(n, 1) << endl;
    return 0;
}
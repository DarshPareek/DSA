#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;


void printVec(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout<<endl;
}


int main(){
    vector<int> nums = {4,1,2,2,1};
    vector<int> seen, times;
    for(int i = 0; i < nums.size(); i++){
        auto it = find(seen.begin(), seen.end(), nums[i]);\
        int index = distance(seen.begin(), it);
        cout << nums[i] << " HERE " << index << endl;
        if(index < seen.size()){
            times[index] += 1;
        }
        else{
            seen.push_back(nums[i]);
            times.push_back(1);
        }
    }
    printVec(nums);
    printVec(times);
    printVec(seen);
    int i = distance(times.begin(),find(times.begin(), times.end(), *min_element(times.begin(), times.end())));
    cout << seen[i] << endl;
    return 0;
}

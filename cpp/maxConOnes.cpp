#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){

    vector<int> nums = {1,1,0,1,1,1};
    int m = 0, c = 0, i = 0;
    while(i < nums.size()){
        if(nums[i] == 1){
            c = c + 1;
        }else if(nums[i] == 0){
            if(m < c){
                m = c;
            }
            c = 0;
        }
        i = i + 1;
    }
    if(m < c){
        m = c;
    }
    cout << m << endl;
    return 0;
}

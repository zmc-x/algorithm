/* 
首先这题和判断是否为质数一样，采用试除法来实现；
首先求较小的因子（< sqrt(n）的；然后求其另一个因子，
当然也需要判断是否为sqrt(n)，避免出现重复的数字
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n{0}, m{0};
    cin >> n;
    while(n--){
        vector<int> nums;
        cin >> m;
        for(int i = 1; i <= m / i; i++){
            if(m % i == 0) {
                nums.push_back(i);
                if(i != m / i) nums.push_back(m / i);
            }
        }
        sort(nums.begin(), nums.end());
        for(auto i : nums) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
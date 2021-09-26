/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Constraints:

    2 <= nums.length <= 10^4
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9
    Only one valid answer exists.

Follow-up: Can you come up with an algorithm that is less than O(n^2) time complexity?

*/


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    //  Method 1: Brute Force     Time : O(n^2)    Space : O(1)
    vector<int> twoSum_1(vector<int> &nums, int target){
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }

    //  Method 2: Using Hash maps       Time : O(n)    Space : O(n)
    vector<int> twoSum_2(vector<int> &nums, int target){
        vector<int> res;
        unordered_map<int, int> myMap;

        for(int i=0; i<nums.size(); i++){
            int dif = target - nums[i];
            if(myMap.count(dif) == 0){
                pair<int, int> p(nums[i], i);
                myMap.insert(p);
            }
            else{
                res.push_back(myMap.at(dif));
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    int n, target, temp;;
    vector<int> arr, sol;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> target;

    // sol = s.twoSum_1(arr, target);        // Brute Force     O(n^2)
    sol = s.twoSum_2(arr, target);         // Using Hash Maps  

    for(int x: sol){
        cout << x << " ";
    }

    return 0;
}
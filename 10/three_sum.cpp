#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> brute_force(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> ans;
    set<vector<int>> s;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] != nums[j] &&
                    nums[j] != nums[k] &&
                    nums[i] != nums[k] &&
                    nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    sort(trip.begin(), trip.end());

                    if (s.find(trip) == s.end())
                    {
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }

    return ans;
}

vector<vector<int>> slightly_optimal(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> uniqueTrip;

    for (int i = 0; i < n; i++)
    {
        int target = -nums[i];
        set<int> s;

        for (int j = i + 1; j < n; j++)
        {
            int third = target - nums[j];
            if (s.find(third) != s.end())
            {
                if (nums[i] != nums[j] &&
                    nums[j] != third &&
                    nums[i] != third)
                {
                    // triplet found
                    vector<int> trip = {nums[i], nums[j], third};
                    sort(trip.begin(), trip.end());

                    uniqueTrip.insert(trip);
                }
            }
            s.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(uniqueTrip.begin(), uniqueTrip.end());
    return ans;
}

vector<vector<int>> two_pointer(vector<int>&nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++) {
        int j = i+1, k = n-1;
        if(i > 0 && nums[i] == nums[i-1]) continue;
        while(j < k) {
            if(nums[i] + nums[j] + nums[k] == 0) {
                vector<int> curr = {nums[i], nums[j], nums[k]};
                ans.push_back(curr);
                j++; k--;

                while(j < k && nums[j] == nums[j-1]) j++;
            } else if(nums[i] + nums[j] + nums[k] < 0) {
                j++;
            } else {
                k--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4, 3};
    vector<vector<int>> result = two_pointer(nums);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//暴力求解
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = -1, end = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                start = i;
                //在排序数组中查找元素的第一个和最后一个位置
                for (int j = nums.size() - 1; j >= 0; j--)
                {
                    if (nums[j] == target && start <= j)
                    {
                        end = j;
                        break;
                    }
                }
                break;
            }
        }
        return vector<int>{start, end};
    }
};
//二分查找
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = left_bound(nums, target);
        int last = right_bound(nums, target);
        return vector<int>{first, last};
    }
    int left_bound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                right = mid - 1;
            }
            else if (target < nums[mid])
            {
                right = mid - 1;
            }
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
        }
        if (left >= nums.size() || nums[left] != target)
            return -1;
        return left;
    }
    int right_bound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                left = mid + 1;
            }
            else if (target < nums[mid])
            {
                right = mid - 1;
            }
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
        }
        if (right < 0 || nums[right] != target)
            return -1;
        return right;
    }
};
//二分查找
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return vector<int>{-1, -1};
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target) - 1;
        if (lower == nums.size() || nums[lower] != target)
        {
            return vector<int>{-1, -1};
        }
        return vector<int>{lower, upper};
    }
    int lower_bound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(), mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
    int upper_bound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(), mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
//照着java语言写的代码敲的，超时了
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return vector<int>{-1, -1};
        int first = findFirstPosition(nums, target);
        if (first == -1)
        {
            return vector<int>{-1, -1};
        }
        int last = findLastPosition(nums, target);
        return vector<int>{first, last};
    }
    int findFirstPosition(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                //下一轮搜索的区间是[left,right]
                right = mid;
            }
            else if (nums[mid] > target)
            {
                //下一轮搜索的区间是[left,mid-1]
                right = mid - 1;
            }
            else
            {
                //下一轮搜索的区间是[mid+1,right]
                left = mid + 1;
            }
        }
        if (nums[left] == target)
            return left;
        return -1;
    }
    int findLastPosition(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                //下一轮搜索的区间是[mid,right]
                left = mid;
            }
            else if (nums[mid] > target)
            {
                //下一轮搜索的区间是[left,mid-1]
                right = mid - 1;
            }
            else
            {
                //下一轮搜索的区间是[mid+1,right]
                left = mid + 1;
            }
        }
        return left;
    }
};

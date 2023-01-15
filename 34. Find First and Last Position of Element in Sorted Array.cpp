class Solution
{
public:
    vector<int> searchRange(vector<int> &num, int target)
    {
        const int l = lower_bound(begin(num), end(num), target) - begin(num);
        if (l == num.size() || num[l] != target)
            return {-1, -1};
        const int r = upper_bound(begin(num), end(num), target) - begin(num) - 1;
        return {l, r};
    }
};
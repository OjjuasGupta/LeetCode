class Solution
{
public:
    int minimumDifference(vector<int> &num)
    {
        const int n = num.size() / 2;
        const int sum = accumulate(begin(num), end(num), 0);
        const int goal = sum / 2;
        const vector<int> lnum(begin(num), begin(num) + n);
        const vector<int> rnum(begin(num) + n, end(num));
        int ans = INT_MAX;
        vector<vector<int>> lSums(n + 1);
        vector<vector<int>> rSums(n + 1);

        dfs(lnum, 0, 0, 0, lSums);
        dfs(rnum, 0, 0, 0, rSums);

        for (int lCount = 0; lCount <= n; ++lCount)
        {
            auto &l = lSums[lCount];
            auto &r = rSums[n - lCount];
            sort(begin(r), end(r));
            for (const int lSum : l)
            {
                const int i = firstGreaterEqual(r, goal - lSum);
                if (i < r.size())
                {
                    const int sumPartOne = sum - lSum - r[i];
                    const int sumPartTwo = sum - sumPartOne;
                    ans = min(ans, abs(sumPartOne - sumPartTwo));
                }
                if (i > 0)
                {
                    const int sumPartOne = sum - lSum - r[i - 1];
                    const int sumPartTwo = sum - sumPartOne;
                    ans = min(ans, abs(sumPartOne - sumPartTwo));
                }
            }
        }

        return ans;
    }

private:
    void dfs(const vector<int> &A, int i, int count, int path,
             vector<vector<int>> &sums)
    {
        if (i == A.size())
        {
            sums[count].push_back(path);
            return;
        }
        dfs(A, i + 1, count + 1, path + A[i], sums);
        dfs(A, i + 1, count, path, sums);
    }

    int firstGreaterEqual(const vector<int> &A, int target)
    {
        return lower_bound(begin(A), end(A), target) - begin(A);
    }
};
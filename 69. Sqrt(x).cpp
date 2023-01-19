class Solution
{
public:
    long long int binarySearch(int n)
    {
        int s = 0;
        int e = n;
        long long int k = s + (e - s) / 2;
        long long int ans = -1;
        while (s <= e)
        {
            long long int sq = k * k;
            if (sq == n)
            {
                return k;
            }
            else if (sq < n)
            {
                ans = k;
                s = k + 1;
            }
            else
            {
                e = k - 1;
            }

            k = s + (e - s) / 2;
        }
        return ans;
    }

    int mySqrt(int x)
    {
        return binarySearch(x);
    }
};
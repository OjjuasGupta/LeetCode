#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// boolean function to check if the num
// pages is valid partition or not
bool isValid(ll book[], ll n, ll sum, ll B)
{
    // if number of books is less than number of student.
    if (n < B)
        return false;
    else
    {
        // initiailse cur for number of pages
        // that student can have.
        ll cur = 0;
        // initialise number student count for
        // assigned number of pages.
        ll cnt = 1;

        for (ll i = 0; i < n; i++)
        {
            cur += book[i];
            // if(cur number of pages is greater than num number
            // of pages that one student can have then we incrase
            // the number of student by one and start again with
            // current number of pages.
            if (cur > sum)
            {
                cnt++;
                cur = book[i];
                // if number of student is greater than B than
                // return false.
                if (cnt > B)
                    return false;
            }
        }
        // if allocation is possible then return true.
        if (cnt <= B)
            return true;
    }
    return false;
}

int main()
{
    ll t;

    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--)
    {
        ll n;

        cout << "Enter number of books: ";
        cin >> n;

        ll book[n];

        cout << "Enter book pages: ";
        for (ll i = 0; i < n; i++)
            cin >> book[i];

        ll B;

        cout << "Enter number of students: ";
        cin >> B;

        // initialise st for binary search as
        // the maximum value among the book.
        ll st = *max_element(book, book + n);

        // initialisze end for binary search as
        // the sum of all the values of books.
        ll end = accumulate(book, book + n, 0);
        ll ans = INT_MAX;

        while (st <= end)
        {
            // find mid of binary search.
            ll mid = st + (end - st) / 2;
            // check for valid condition then assign the answer.
            if (isValid(book, n, mid, B))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                st = mid + 1;
        }

        if (ans == INT_MAX)
        {
            cout << "Allocation not possible: ";
            cout << -1 << "\n";
        }
        else
        {
            cout << "Minimum number of pages: ";
            cout << ans << "\n";
        }
    }

    return 0;
}

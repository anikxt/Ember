#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
typedef long long int ll;
#define gc getchar_unlocked
#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define clr(x, y) memset(x, y, sizeof(x))
#define sortall(x) sort(all(x))
#define vll vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;

const int MOD = 1e9 + 7;
//=======================

int n;

int rec(int level) // return -> number of way to N if we are at stair level.
{
    // level -> stair i am at

    // pruning
    if (level > n)
    {
        return 0;
    }

    // base case
    if (level == n)
    {
        return 1;
    }

    int ans = 0;
    // loop over choice
    for (int step = 1; step <= 3; ++step)
    {
        // check -> is a valid choice
        if (level + step <= n)
        {
            // move
            int ways = rec(level + step);
            ans += ways;
        }
    }

    return ans; // for this level.
}

void solve()
{
    cin >> n;
    cout << rec(1) << endl;
    return;
}

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
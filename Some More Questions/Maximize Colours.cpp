#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define ff first
#define ss second
#define sortvec(v) sort(v.begin(), v.end())
#define revvec(v) reverse(v.begin(), v.end())

void solve()
{
    int a[3], ans = 0;
    cin >> a[0] >> a[1] >> a[2];
    if (a[0] > 0)
    {
        ans++;
        a[0]--;
    }
    if (a[1] > 0)
    {
        ans++;
        a[1]--;
    }
    if (a[2] > 0)
    {
        ans++;
        a[2]--;
    }
    sort(a, a + 3);
    reverse(a, a + 3);
    if (a[0] > 0 && a[1] > 0)
    {
        a[0]--;
        a[1]--;
        ans++;
    }
    if (a[2] > 0 && a[1] > 0)
    {
        a[2]--;
        a[1]--;
        ans++;
    }
    if (a[0] > 0 && a[2] > 0)
    {
        a[0]--;
        a[2]--;
        ans++;
    }
    cout << ans << endl;
}

int main()
{
    ll tc = 1;
    cin >> tc;

    for (ll i = 1; i <= tc; i++)
    {

        solve();
    }

    return 0;
}
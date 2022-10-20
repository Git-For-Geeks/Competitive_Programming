#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;

int main()
{
    //     ios::sync_with_stdio(0);
    //     cin.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ll tc;
    cin >> tc;

    while (tc--)
    {
        ll n;
        cin >> n;// taking input
        ll a[n]; // input array for boy's height.
        ll b[n];// input array for girl's height.
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n); // sorted array for boy's height using inbuild sort of cpp.
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(b, b + n, greater<>());// sorted array for girl's height using inbuild sort of cpp.

        ll solutionn = 0;
        for (int i = 0; i < n; i++)
        {
            solutionn = max(a[i] + b[i], solutionn); // determining max LIKENESS VALUE
        }
        cout << solutionn << endl;
    }

    return 0;
}
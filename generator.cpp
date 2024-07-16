#include<bits/stdc++.h>
using namespace std;

#define ll long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    ll n= 1 + rng()%((long long)1e4);
    cout<<n<<"\n";
    ll x = 1 + rng()%(19);
    cout<<x<<"\n";

    for(ll i=0;i<n;i++)
    {
        cout<<1 + rng()%((long long)1e18)<<" ";
    }

    cout<<"\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","w",stdout);

    ll t=1;
    cout<<t<<"\n";
    // cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}
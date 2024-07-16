#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifndef ONLINE_JUDGE
#ifdef _WIN32
#include "C:/Users/ariha/Desktop/Programs/Debug/debug.h"
#endif
#else
#define debug(...) 468
#endif

#define cin std::cin
#define cout std::cout
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update>
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);
// #define int ll
#define ll long long
#define ld double
#define vi vector<ll>
#define vvi vector<vi>
#define vpi vector<pi>
#define pi pair<ll, ll>
#define pb push_back
#define sqrt sqrtl
#define pow powl
#define __builtin_popcount __builtin_popcountll
#define MOD 1000000007LL
#define inf 1000000000000000000LL
#define all(x) x.begin(), x.end()
#define abs llabs

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(pair<uint64_t,uint64_t> x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
	}
};

ll min(ll a, ll b)
{
    if (a < b)
        return a;

    return b;
}

ll max(ll a, ll b)
{
    if (a > b)
        return a;

    return b;
}

ll hcf(ll a, ll b)
{
    if (b == 0LL)
        return a;

    return hcf(b, a % b);
}

ll lcm(ll a, ll b) { return ((a * b) / hcf(a, b)); };

string binary(ll n)
{
    string s = bitset<64>(n).to_string();
    const auto loc1 = s.find('1');
    if (loc1 != string::npos)
    {
        return s.substr(loc1);
    }
    return "0";
}

ll decimal(string s) { return stoll(s); }

//

ll modinv(ll p, ll q)
{
    p %= MOD;
    q %= MOD;
    ll expo = MOD - 2;
    while (expo)
    {
        if (expo & 1)
            p = (p * q) % MOD;
        q = (q * q) % MOD;
        expo >>= 1;
    }
    return p;
}

ll binexp(ll a, ll b)
{
    a %= MOD;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

//

ll kmp(string txt, string pat)
{
    vector<ll> ans;

    ll n = txt.size(), m = pat.size();

    ll prefix[m], q = 0, len = 0, curr = 1;

    prefix[0] = 0;

    while (curr < m)
    {
        if (pat[curr] == pat[len])
        {
            len++;
            prefix[curr] = len;
            curr++;
        }
        else if (len != 0)
        {
            len = prefix[len - 1];
        }
        else
        {
            prefix[curr] = 0;
            curr++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        while (q > 0 && pat[q] != txt[i])
            q = prefix[q - 1];

        if (pat[q] == txt[i])
            q++;

        if (q == m)
        {
            ans.push_back(i - m + 1);
            q = prefix[q - 1];
        }
    }

    return ans.size();
}

//

const ll N = 100005;
vector<bool> VISI;
vvi divisors;
vi primes;

void Sieve()
{
    VISI.assign(N, 1);

    VISI[0] = VISI[1] = false;
    for (ll i = 4; i < N; i += 2)
        VISI[i] = false;
    for (ll i = 3; i < N / i; i += 2)
    {
        if (!VISI[i])
            continue;
        for (ll j = i * i; j < N; j += i + i)
            VISI[j] = false;
    }
}

void Gen()
{
    for (ll i = 2; i < N; i++)
        if (VISI[i])
            primes.pb(i);

    // divisors.assign(N, {});
    // for (ll i = 1; i < N; i++)
    //     for (ll j = i; j < N; j += i)
    //         divisors[j].pb(i);
}

//

vi fact, facti;

void Fact()
{
    fact.resize(N);
    facti.resize(N);

    fact[0] = 1;
    for (ll i = 1; i < N; i++)
        fact[i] = (i * fact[i - 1]) % MOD;

    facti[N - 1] = modinv(1, fact[N - 1]);
    for (ll i = N - 2; i >= 0; i--)
        facti[i] = ((i + 1) * facti[i + 1]) % MOD;
}

ll ncr(ll n, ll r)
{
    if (r > n)
        return 0;

    ll temp = fact[n] * facti[r] % MOD;
    temp = temp * facti[n - r] % MOD;
    return temp;
}

//

vi parentt, siz;

void make_set(int n)
{
    parentt.assign(n + 1, 0);
    siz.assign(n + 1, 1);

    for (ll i = 0; i <= n; i++)
        parentt[i] = i;
}

ll find_set(int v)
{
    if (v == parentt[v])
        return v;
    return parentt[v] = find_set(parentt[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (siz[a] < siz[b])
            swap(a, b);
        parentt[b] = a;
        siz[a] += siz[b];
    }
}

//

// vvi adj;
// vi vis1;
// // vi vis2;
// // vi par1;
// // vi par2;
// // vi dist1;
// // vi dist2;

// void create_graph(ll n)
// {
//     adj.assign(n + 1, {});
//     vis1.assign(n + 1, 0);
//     // vis2.assign(n + 1, 0);
//     // par1.assign(n + 1, -1);
//     // par2.assign(n + 1, -1);
//     // dist1.assign(n + 1, inf);
//     // dist2.assign(n + 1, inf);
// }

// void dfs(ll curr, vi &vis)
// {
//     if (vis[curr] == 1)
//         return;

//     vis[curr] = 1;

//     for (auto x : adj[curr])
//     {
//         if (!vis[x])
//         {
//             dfs(x, vis);
//         }
//     }

//     return;
// }

// void bfs(ll curr, vi &vis, vi &par, vi &dist)
// {
//     queue<ll> q;

//     vis[curr] = 1;
//     dist[curr] = 0;
//     q.push(curr);

//     while (!q.empty())
//     {
//         auto u = q.front();
//         q.pop();

//         for (auto x : adj[u])
//         {
//             if (!vis[x])
//             {
//                 vis[x] = 1;
//                 par[x] = u;
//                 dist[x] = 1 + dist[u];
//                 q.push(x);
//             }
//         }
//     }
// }

// void djikstra(ll curr)
// {
//     dist2[curr]=0;

//     priority_queue<pi,vector<pi>,greater<pi>> pq;

//     pq.push({0,curr});

//     while(!pq.empty())
//     {
//         int u=pq.top().second;
//         int distance=pq.top().first;

//         pq.pop();

//         if(dist2[u]==distance)
//         {
//             for(auto [x,weight]:adj[u])
//             {
//                 if(dist2[x]>dist2[u]+weight)
//                 {
//           ,          dist2[x]=dist2[u]+weight;
//                     par2[x]=u;

//                     pq.push({dist2[x],x});
//                 }
//             }
//         }
//     }
// }

//

/*                  CODE      STARTS       HERE        */

// Inclusive ranges for all queries
class PointQueryRangeSumSegmentTree
{
public:
    vector<ll> seg;
    ll n;

    PointQueryRangeSumSegmentTree(ll n)
    {
        this->n = n;
        seg.assign(4 * n, 0);
    }

    void build(vi &a, ll v, ll tl, ll tr)
    {
        if (tl == tr)
        {
            seg[v] = a[tl];
        }
        else
        {
            ll tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            seg[v] = seg[2 * v] + seg[2 * v + 1];
        }
    }

    ll sum(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return seg[v];
        ll tm = (tl + tr) / 2;
        return sum(2 * v, tl, tm, l, min(r, tm)) + sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(ll v, ll tl, ll tr, ll pos, ll new_val)
    {
        if (tl == tr)
        {
            seg[v] = new_val;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                update(2 * v, tl, tm, pos, new_val);
            else
                update(2 * v + 1, tm + 1, tr, pos, new_val);
            seg[v] = seg[2 * v] + seg[2 * v + 1];
        }
    }

    ll sum(ll l, ll r)
    {
        return sum(1, 0, n - 1, l, r);
    }

    void update(ll pos, ll new_val)
    {
        update(1, 0, n - 1, pos, new_val);
    }

    void build(vi &a)
    {
        build(a, 1, 0, n - 1);
    }

    void print()
    {
        for (ll i = 0; i < n; i++)
            cout << sum(i, i) << " ";
        cout << "\n";
    }
};

void solve()
{
    ll n,x;
    cin>>n>>x;

    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];

    //

    vpi v(n);
    vi pos(n);

    for(ll i=0;i<n;i++)
        v[i]={a[i],i};

    sort(all(v));

    for(ll i=0;i<n;i++)
        pos[v[i].second]=i;

    vi seg(n);
    vi temp(n);
    for(ll i=0;i<n;i++)
    {
        temp[i]=v[i].first;
        seg[i]=n-v[i].second;
    }

    PointQueryRangeSumSegmentTree st(n);

    st.build(seg);
    
    // st.print();

    //

    ll ans=0;
    ll small=powl(10,x-1);
    ll big=powl(10,x);

    for(ll l=0;l<n;l++)
    {
        st.update(pos[l],0);

        ll l1=lower_bound(all(temp),small-a[l])-temp.begin();
        ll r1=lower_bound(all(temp),big-a[l])-temp.begin();

        ans+=(l+1)*st.sum(l1,r1-1);
        // st.print();
    }

    //

    cout<<ans;

    cout << "\n";
}

signed main()
{
    fast_io;

    freopen("input.txt","r",stdin);
    freopen("bruteforce.txt","w",stdout);

    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
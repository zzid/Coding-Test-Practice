//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define forn(i, n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define sz(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

struct town
{
    int x, y, h, p;

    bool operator < (const town &o) const
    {
        return h < o.h;
    }
};

struct segtree
{
    vll vals;
    int tsz;

    segtree ()
    {
        vals.clear();
        tsz = 0;
    }

    segtree (int n)
    {
        tsz = 1;
        while (tsz <= n)
            tsz *= 2;

        vals.assign(2 * tsz, 0);
    }

    void put (int pos, ll what)
    {
        for (pos += tsz; pos > 0; pos >>= 1)
            vals[pos] = max(vals[pos], what);
    }

    ll query (int l, int r)
    {
        ll ans = 0;
        for (l += tsz, r += tsz; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ans = max(ans, vals[l++]);
            if (r & 1)
                ans = max(ans, vals[--r]);
        }
        return ans;
    }
};

struct segtree2d
{
    vvi who;
    vector<segtree> data;
    int tsz;

    segtree2d (const vii &ps)
    {
        int X = 0;
        const int n = sz(ps);
        forn (i, n) X = max(X, ps[i].fst);

        tsz = 1;
        while (tsz <= X)
            tsz *= 2;

        data.resize(2 * tsz);
        who.resize(2 * tsz);
        forn (i, n)
            who[ps[i].fst + tsz].pb(ps[i].snd);

        for (int i = tsz; i < 2 * tsz; i++)
            data[i] = segtree(sz(who[i]));

        for (int i = tsz - 1; i >= 1; i--)
        {
            who[i].resize(sz(who[2 * i]) + sz(who[2 * i + 1]));
            merge(ALL(who[2 * i]), ALL(who[2 * i + 1]), who[i].begin());
            data[i] = segtree(sz(who[i]));
        }
    }

    ll query (int v, int d, int u)
    {
        int rd = lower_bound(ALL(who[v]), d) - who[v].begin();
        int ru = lower_bound(ALL(who[v]), u) - who[v].begin();
        return data[v].query(rd, ru);
    }

    ll query (int l, int r, int d, int u)
    {
        r = min(r, tsz);
        ll ans = 0;
        for (l += tsz, r += tsz; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ans = max(ans, query(l++, d, u));
            if (r & 1)
                ans = max(ans, query(--r, d, u));
        }
        return ans;
    }

    void putnode (int v, int pos, ll what)
    {
        int cur = lower_bound(ALL(who[v]), pos) - who[v].begin();
        assert(cur != sz(who[v]) && who[v][cur] == pos);
        data[v].put(cur, what);
    }

    void put (int x, int y, ll what)
    {
        for (x += tsz; x > 0; x >>= 1)
            putnode(x, y, what);
    }
};

void solve (int n)
{
    int mx, my;
    cin >> mx >> my;

    vector<town> v(n);
    forn (i, n)
        cin >> v[i].x >> v[i].y >> v[i].h >> v[i].p;

    sort(ALL(v));
    vii ps(n);
    forn (i, n) ps[i] = mp(v[i].x, v[i].y);

    segtree2d data(ps);
    vll dp(n);

    forn (i, n)
    {
        int cx = v[i].x, cy = v[i].y;
        int lx = max(0, cx - mx), ly = max(0, cy - my);
        int rx = cx + mx, ry = cy + my;
        dp[i] = data.query(lx, rx + 1, ly, ry + 1) + v[i].p;
        data.put(cx, cy, dp[i]);
    }

    ll ans = max(0LL, *max_element(ALL(dp)));
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n)
        solve(n);
}
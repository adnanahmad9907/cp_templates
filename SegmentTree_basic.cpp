
// segment tree template created by Adnan ahmad.. cf-adnanahmad
function<ll(ll, ll)> F = [](ll a, ll b)
{ return a + b; };
ll Ne = 0LL;

struct SegmentTree
{
    ll n;
    vector<ll> tree;

    SegmentTree(vector<ll> &a)
    {
        n = a.size();
        tree.assign(4 * n, Ne);
        build(a, 1, 0, n - 1);
    }

    void build(const vector<ll> &a, ll v, ll tl, ll tr)
    {
        if (tl == tr)
        {
            tree[v] = a[tl];
        }
        else
        {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            tree[v] = F(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    void upd(ll v, ll tl, ll tr, ll ind, ll val)
    {
        if (tl == tr)
        {
            tree[v] = val;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            if (ind <= tm)
                upd(v * 2, tl, tm, ind, val);
            else
                upd(v * 2 + 1, tm + 1, tr, ind, val);
            tree[v] = F(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void upd(ll ind, ll val)
    {
        upd(1, 0, n - 1, ind, val);
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return Ne;
        if (l == tl && r == tr)
            return tree[v];
        ll tm = (tl + tr) / 2;
        return F(
            query(v * 2, tl, tm, l, min(r, tm)),
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    ll query(ll l, ll r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

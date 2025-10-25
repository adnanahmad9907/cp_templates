function<ll(ll, ll)> F = [](ll a, ll b)
{ return a + b; }; 
ll Ne = 0LL;       

struct LazySegTree
{

private:
    ll n;
    vector<ll> tree, lazy;
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

    void push(ll v, ll tl, ll tr)
    {
        if (lazy[v] != 0)
        {
            tree[v] += (tr - tl + 1) * lazy[v];

            if (tl != tr)
            {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            }

            lazy[v] = 0;
        }
    }

    void upd(ll v, ll tl, ll tr, ll l, ll r, ll add)
    {
        push(v, tl, tr);
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            lazy[v] += add;
            push(v, tl, tr);
        }
        else
        {
            ll tm = (tl + tr) / 2;
            upd(v * 2, tl, tm, l, min(r, tm), add);
            upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
            tree[v] = F(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r)
    {
        push(v, tl, tr);
        if (l > r)
            return Ne;
        if (l == tl && r == tr)
            return tree[v];
        ll tm = (tl + tr) / 2;
        return F(
            query(v * 2, tl, tm, l, min(r, tm)),
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

public:
    LazySegTree(vector<ll> &a)
    {
        n = a.size();
        tree.assign(4 * n, Ne);
        lazy.assign(4 * n, 0LL);
        build(a, 1, 0, n - 1);
    }
    void upd(ll l, ll r, ll add)
    {
        upd(1, 0, n - 1, l, r, add);
    }
    ll query(ll l, ll r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

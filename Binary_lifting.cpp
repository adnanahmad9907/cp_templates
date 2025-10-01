class BinaryLifting
{
public:
    ll timer, L, n;
    vector<ll> tin, tout;
    vector<vector<ll>> up, adj;
    BinaryLifting(vector<vector<ll>> &adj2, ll root = 0)
    {
        n = adj2.size();
        adj = adj2;
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        L = (ll)log2(n) + 1;
        up.assign(n, vector<ll>(L + 1, -1));
        dfs(root, -1);
    }
    void dfs(ll u, ll par)
    {
        tin[u] = ++timer;
        up[u][0] = par;
        for (int i = 1; i <= L; i++)
        {
            if (up[u][i - 1] != -1)
            {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
            else
            {
                up[u][i] = -1;
            }
        }
        for (auto v : adj[u])
        {
            if (v != par)
            {
                dfs(v, u);
            }
        }
        tout[u] = ++timer;
    }

    bool is_ancestor(ll u, ll v)
    {
        // if u is ancestor of v
        return (tin[u] <= tin[v] && tout[u] >= tout[v]);
    }
    ll lca(ll u, ll v)
    {
        if (is_ancestor(u, v))
        {
            return u;
        }
        if (is_ancestor(v, u))
        {
            return v;
        }

        for (int i = L; i >= 0; i--)
        {
            if (up[u][i] != -1 && !is_ancestor(up[u][i], v))
            {
                u = up[u][i];
            }
        }
        return up[u][0];
    }
    ll kth_ancestor(ll u, ll k)
    {
        if (k == 0)
        {
            return u;
        }
        for (ll i = 0; i <= L && u != -1; i++)
        {
            if (k >> i & 1LL)
            {
                u = up[u][i];
            }
        }
        return u;
    }
    ll which_ancestor(ll u, ll ancestor)
    {
        if (u == ancestor)
        {
            return 0;
        }
        ll ans = 0;
        for (int i = L; i >= 0; i--)
            if (up[u][i] != -1 && !is_ancestor(up[u][i], ancestor))
            {
                u = up[u][i];
                ans += (1LL << i);
            }
        return ans + 1;
    }
};

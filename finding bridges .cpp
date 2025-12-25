

vector<pair<ll, ll>> get_bridges(ll n, vector<vector<ll>> &adj)
{
    vector<ll> tin(n, -1), low(n, -1);
    vector<pair<ll, ll>> bridges;
    ll timer = 0;

    function<void(ll, ll)> dfs = [&](ll u, ll parent)
    {
        tin[u] = low[u] = timer++;

        for (ll v : adj[u])
        {
            if (v == parent)
                continue;

            if (tin[v] != -1)
            {
                low[u] = min(low[u], tin[v]);
            }
            else
            {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > tin[u])
                {
                    bridges.emplace_back(u, v);
                }
            }
        }
    };

    for (ll i = 0; i < n; i++)
    {
        if (tin[i] == -1)
            dfs(i, -1);
    }

    return bridges;
}

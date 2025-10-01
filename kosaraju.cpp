void dfs1(ll u, vector<vector<ll>> &adj, vector<ll> &vis, stack<ll> &st)
{
    vis[u] = 1;
    for (ll v : adj[u])
    {
        if (!vis[v])
        {
            dfs1(v, adj, vis, st);
        }
    }
    st.push(u);
}

void dfs2(ll u, vector<vector<ll>> &radj, vector<ll> &vis, vector<ll> &comp, ll id)
{
    vis[u] = 1;
    comp[u] = id;
    for (ll v : radj[u])
    {
        if (!vis[v])
        {
            dfs2(v, radj, vis, comp, id);
        }
    }
}

vector<ll> kosaraju(vector<vector<ll>> &adj)
{
    ll n = adj.size();

    vector<vector<ll>> radj(n);
    for (ll u = 0; u < n; u++)
    {
        for (ll v : adj[u])
        {
            radj[v].push_back(u);
        }
    }

    vector<ll> vis(n, 0);
    stack<ll> st;
    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs1(i, adj, vis, st);
        }
    }
    fill(vis.begin(), vis.end(), 0);
    vector<ll> comp(n, -1);
    ll scc_id = 0;

    while (!st.empty())
    {
        ll u = st.top();
        st.pop();
        if (!vis[u])
        {
            dfs2(u, radj, vis, comp, scc_id++);
        }
    }

    return comp;
}

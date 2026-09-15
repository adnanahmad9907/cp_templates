vector<vector<pair<ll, ll>>> edmondsKarp(vector<vector<pair<ll, ll>>> &adj, ll s, ll t)
{
    ll n = adj.size();
    vector<vector<ll>> capacity(n, vector<ll>(n, 0));
    vector<vector<ll>> original(n, vector<ll>(n, 0));

    for (ll u = 0; u < n; u++)
    {
        for (auto [v, cap] : adj[u])
        {
            capacity[u][v] += cap;
            original[u][v] += cap;
        }
    }

    ll maxFlow = 0;

    while (true)
    {
        vector<ll> parent(n, -1);

        queue<ll> q;
        q.push(s);
        parent[s] = s;
        while (!q.empty() && parent[t] == -1)
        {

            ll u = q.front();
            q.pop();

            for (ll v = 0; v < n; v++)
            {

                if (parent[v] == -1 && capacity[u][v] > 0)
                {
                    parent[v] = u;
                    q.push(v);

                    if (v == t)
                        break;
                }
            }
        }

        if (parent[t] == -1)
            break;

        ll pushed = LLONG_MAX;

        for (ll v = t; v != s; v = parent[v])
        {
            ll u = parent[v];
            pushed = min(pushed, capacity[u][v]);
        }

        for (ll v = t; v != s; v = parent[v])
        {
            ll u = parent[v];

            capacity[u][v] -= pushed;
            capacity[v][u] += pushed;
        }

        maxFlow += pushed;
    }

    vector<vector<ll>> flow(n, vector<ll>(n, 0));

    for (ll u = 0; u < n; u++)
    {
        for (ll v = 0; v < n; v++)
        {

            if (original[u][v] > 0)
            {
                flow[u][v] =
                    max(0LL, original[u][v] - capacity[u][v]);
            }
        }
    }

    vector<vector<pair<ll, ll>>> flowGraph(n);

    for (ll u = 0; u < n; u++)
    {
        for (ll v = 0; v < n; v++)
        {

            if (flow[u][v] > 0)
            {
                flowGraph[u].push_back({v, flow[u][v]});
            }
        }
    }

    return flowGraph;
}

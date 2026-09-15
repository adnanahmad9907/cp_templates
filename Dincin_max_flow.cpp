
struct Dinic
{

    struct Edge
    {
        ll to;
        ll cap;
        ll rev;

        ll original;
    };

    ll n;
    vector<vector<Edge>> adj;
    vector<ll> level, ptr;

    Dinic(ll n) : n(n)
    {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    ll addEdge(ll u, ll v, ll cap)
    {

        ll idx = adj[u].size();
        ll ridx = adj[v].size();

        adj[u].push_back({v, cap, ridx, cap});

        adj[v].push_back({u, 0, idx, 0});

        return idx;
    }

    bool bfs(ll s, ll t)
    {

        fill(level.begin(), level.end(), -1);

        queue<ll> q;
        q.push(s);
        level[s] = 0;

        while (!q.empty())
        {

            ll u = q.front();
            q.pop();

            for (auto &e : adj[u])
            {

                if (e.cap > 0 && level[e.to] == -1)
                {

                    level[e.to] = level[u] + 1;

                    if (e.to == t)
                        return true;

                    q.push(e.to);
                }
            }
        }

        return false;
    }

    ll dfs(ll u, ll t, ll pushed)
    {

        if (u == t)
            return pushed;

        for (ll &i = ptr[u]; i < (ll)adj[u].size(); i++)
        {

            Edge &e = adj[u][i];

            if (e.cap <= 0 ||
                level[e.to] != level[u] + 1)
                continue;

            ll flow = dfs(
                e.to,
                t,
                min(pushed, e.cap));

            if (flow == 0)
                continue;

            e.cap -= flow;
            adj[e.to][e.rev].cap += flow;

            return flow;
        }

        return 0;
    }

    ll maxFlow(ll s, ll t)
    {

        ll ans = 0;

        while (bfs(s, t))
        {

            fill(ptr.begin(), ptr.end(), 0);

            while (ll pushed = dfs(s, t, LLONG_MAX))
            {
                ans += pushed;
            }
        }

        return ans;
    }

    vector<vector<pair<ll, ll>>> getFlow()
    {

        vector<vector<pair<ll, ll>>> flow(n);

        for (ll u = 0; u < n; u++)
        {

            for (auto &e : adj[u])
            {

                if (e.original == 0)
                    continue;

                ll used = e.original - e.cap;

                if (used > 0)
                {
                    flow[u].push_back({e.to, used});
                }
            }
        }

        return flow;
    }
   vector<pair<ll, ll>> getMinCut(ll s)
    {
        vector<ll> vis(n, 0);

        queue<ll> q;
        q.push(s);
        vis[s] = 1;
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();

            for (auto &e : adj[u])
            {
                if (e.cap > 0 && !vis[e.to])
                {
                    vis[e.to] = 1;
                    q.push(e.to);
                }
            }
        }

        vector<pair<ll, ll>> cut;
        for (ll u = 0; u < n; u++)
        {
            if (!vis[u])
                continue;

            for (auto &e : adj[u])
            {
                if (e.original > 0 && !vis[e.to])
                {
                    cut.push_back({u, e.to});
                }
            }
        }
        return cut;
    }
};

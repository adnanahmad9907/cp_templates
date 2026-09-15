struct TwoSAT
{
    int n;
    vector<vector<int>> adj, radj;
    vector<int> vis, comp, order, assignment;

    TwoSAT(int n) : n(n)
    {
        adj.resize(2 * n);
        radj.resize(2 * n);
        assignment.resize(n);
    }
    int node(int x, bool val)
    {
        return 2 * x + (!val);
    }

    void add_implication(int u, int v)
    {
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    void add_clause(int a, bool va, int b, bool vb)
    {
        int A = node(a, va);
        int B = node(b, vb);
        add_implication(A ^ 1, B);
        add_implication(B ^ 1, A);
    }

    void dfs1(int u)
    {
        vis[u] = 1;

        for (int v : adj[u])
            if (!vis[v])
                dfs1(v);

        order.push_back(u);
    }

    void dfs2(int u, int id)
    {
        vis[u] = 1;
        comp[u] = id;

        for (int v : radj[u])
            if (!vis[v])
                dfs2(v, id);
    }

    bool solve()
    {
        int N = 2 * n;

        vis.assign(N, 0);
        order.clear();

        for (int i = 0; i < N; i++)
            if (!vis[i])
                dfs1(i);

        vis.assign(N, 0);
        comp.assign(N, -1);

        int scc = 0;

        for (int i = N - 1; i >= 0; i--)
        {
            int u = order[i];

            if (!vis[u])
                dfs2(u, scc++);
        }

        for (int i = 0; i < n; i++)
        {
            // x and !x in same SCC => impossible
            if (comp[2 * i] == comp[2 * i + 1])
                return false;

            // Important for THIS Kosaraju implementation
            assignment[i] = comp[2 * i] > comp[2 * i + 1];
        }

        return true;
    }
};

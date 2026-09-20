vector<int> adj[maxn];

int col[maxn];
int sz[maxn];

vector<int> *vec[maxn];
int cnt[maxn];

void dfs_sz(int v, int p)
{
    sz[v] = 1;

    for (auto u : adj[v])
    {
        if (u == p)
            continue;

        dfs_sz(u, v);
        sz[v] += sz[u];
    }
}

void dfs(int v, int p, bool keep)
{
    int mx = -1;
    int bigChild = -1;

    // Find the biggest child
    for (auto u : adj[v])
    {
        if (u == p)
            continue;

        if (sz[u] > mx)
        {
            mx = sz[u];
            bigChild = u;
        }
    }

    // Process all small children first
    for (auto u : adj[v])
    {
        if (u == p || u == bigChild)
            continue;

        dfs(u, v, false);
    }

    // Process biggest child and keep its data
    if (bigChild != -1)
    {
        dfs(bigChild, v, true);
        vec[v] = vec[bigChild];
    }
    else
    {
        vec[v] = new vector<int>();
    }

    // Add v itself
    vec[v]->push_back(v);
    cnt[col[v]]++;

    // Add all small children's data
    for (auto u : adj[v])
    {
        if (u == p || u == bigChild)
            continue;

        for (auto x : *vec[u])
        {
            cnt[col[x]]++;
            vec[v]->push_back(x);
        }
    }

    /*
        Now:

        cnt[c] = number of vertices with color c
                 in subtree of v.

        vec[v] = all vertices in subtree of v.
    */

    // If parent doesn't want to keep this subtree
    if (!keep)
    {
        for (auto u : *vec[v])
        {
            cnt[col[u]]--;
        }
    }
}

// dfs_sz(0, -1);
// dfs(0, -1, true);
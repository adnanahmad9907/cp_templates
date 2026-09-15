vector<ll> eulerTour(ll start, vector<vector<ll>> adj)
{
  // write your own checker first!! 
  // that it is connected
  // every vertex has degree even or 2 has odd degree vertex 
    vector<ll> path;

    function<void(ll)> dfs = [&](ll u)
    {
        while (!adj[u].empty())
        {
            ll v = adj[u].back();
            adj[u].pop_back();

            dfs(v);
        }

        path.push_back(u);
    };

    dfs(start);

    reverse(path.begin(), path.end());

    return path;
}

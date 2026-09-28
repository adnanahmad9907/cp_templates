map<vector<ll>, ll> hasher;

ll hashify(vector<ll> x)
{
    sort(x.begin(), x.end());
    if (!hasher[x])
    {
        hasher[x] = hasher.size();
    }
    return hasher[x];
}

ll f(ll i, ll par, vector<vector<ll>> &adj)
{
    ll ans = 1;
    debug(i, par, adj);
    vector<ll> arr;
    for (auto j : adj[i])
    {
        if (j == par)
            continue;
        arr.push_back(f(j, i, adj));
    }
    return hashify(arr);
}

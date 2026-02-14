void floydWarshall(vector<vector<ll>> &dist)
{
    ll n = dist.size();

    for (ll k = 0; k < n; k++)
    {

        for (ll i = 0; i < n; i++)
        {

            for (ll j = 0; j < n; j++)
            {
                if (dist[i][k] != 1e8 && dist[k][j] != 1e8)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

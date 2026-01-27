
vector<vector<ll>> mat_mul(const vector<vector<ll>> &A,
                           const vector<vector<ll>> &B,
                           ll mod)
{
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (A[i][k] == 0)
                continue;
            for (int j = 0; j < n; j++)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

vector<vector<ll>> mat_pow(vector<vector<ll>> base,
                           ll exp,
                           ll mod = mod)
{
    int n = base.size();
    vector<vector<ll>> result(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        result[i][i] = 1;

    while (exp > 0)
    {
        if (exp & 1)
            result = mat_mul(result, base, mod);
        base = mat_mul(base, base, mod);
        exp >>= 1;
    }
    return result;
}

const ll MAXN = 2 * 1e5 + 5;
ll spf[MAXN];
void sieve()
{
    for (ll i = 2; i < MAXN; i++)
    {
        if (spf[i] == 0)
        {
            for (ll j = i; j < MAXN; j += i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}
vector<ll> fac(ll x)
{
    vector<ll> factors;
    while (x > 1)
    {
        ll p = spf[x];
        factors.push_back(p);
        x /= p;
    }
    return factors;
}


const ll max_n = 1e5 + 1;
ll fac[max_n];
void pre()
{
    fac[0] = 1;
    for (int i = 1; i < max_n; i++)
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }
}
ll pow(ll a, ll b, ll mod = mod)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll modinv(ll a)
{
    return pow(a, mod - 2, mod);
}

ll ncr(ll n, ll r)
{
    if (r < 0 || r > n)
    {
        return 0;
    }
    ll num = fac[n];
    ll denom = (fac[r] * fac[n - r]) % mod;

    return (num * modinv(denom)) % mod;
}

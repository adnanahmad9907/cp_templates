const ll MAXN = 1e6;
vector<ll> arr;
vector<bool> pri(MAXN + 1, true);
void sieve()
{
    
    pri[0] = pri[1] = false;

    for (ll i = 2; i * i <= MAXN; i++)
    {
        if (pri[i])
        {
            for (ll j = i * i; j <= MAXN; j += i)
                pri[j] = false;
        }
    }
    for (ll i = 2; i <= MAXN; i++)
    {
        if (pri[i])
            arr.push_back(i);
    }
}

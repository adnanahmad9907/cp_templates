vector<ll> mobius(ll N)
{
    vector<ll> mu(N + 1), primes;
    vector<bool> comp(N + 1);

    mu[1] = 1;

    for (ll i = 2; i <= N; i++)
    {
        if (!comp[i])
        {
            primes.push_back(i);
            mu[i] = -1;
        }

        for (ll p : primes)
        {
            if (1LL * i * p > N)
                break;

            comp[i * p] = true;

            if (i % p == 0)
            {
                mu[i * p] = 0;
                break;
            }
            else
            {
                mu[i * p] = -mu[i];
            }
        }
    }

    return mu;
}

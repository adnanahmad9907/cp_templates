struct PrefixArray
{
    ll n;
    vector<ll> arr, pref, diff;

    PrefixArray(vector<ll> _arr)
    {
        n = _arr.size();
        arr = _arr;
        pref.assign(n + 1, 0);
        diff.assign(n + 1, 0);
        build();
    }
    void build()
    {
        pref[0] = 0;
        for (ll i = 0; i < n; i++)
        {
            pref[i + 1] = pref[i] + arr[i];
        }
    }

    ll query(ll l, ll r)
    {
        return pref[r + 1] - pref[l];
    }

    void update(ll l, ll r, ll x)
    {
        diff[l] += x;
        if (r + 1 < n)
        {
            diff[r + 1] -= x;
        }
    }

    void propagate()
    {
        ll cur = 0;
        for (ll i = 0; i < n; i++)
        {
            cur += diff[i];
            arr[i] += cur;
        }
        build();
        fill(diff.begin(), diff.end(), 0);
    }
};

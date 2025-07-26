vector<ll> kmp(string s)
{
    // knuth morris pratt
    ll n = (ll)s.length();
    vector<ll> kmp(n);
    for (ll i = 1; i < n; i++)
    {
        ll j = kmp[i - 1];
        while (j > 0 && s[i] != s[j])
            j = kmp[j - 1];
        if (s[i] == s[j])
            j++;
        kmp[i] = j;
    }
    return kmp;
}

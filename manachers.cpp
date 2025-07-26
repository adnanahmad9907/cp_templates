
// Manacher's Algorithm
vector<ll> manacher(string &s)
{
    string t = "#";
    for (char c : s)
    {
        t += c;
        t += '#';
    }
    ll n = t.size();
    vector<ll> p(n, 0);
    ll l = 0, r = 0;
    for (ll i = 1; i < n; ++i)
    {
        if (i < r)
            p[i] = max(0ll, min(r - i, p[l + r - i]));

        while (i + p[i] < n && i - p[i] >= 0 && t[i + p[i]] == t[i - p[i]])
            p[i]++;

        if (i + p[i] > r)
        {
            l = i - p[i];
            r = i + p[i];
        }
    }
    s = t;
    return p;
}

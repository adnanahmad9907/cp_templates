string hee(ll x)
{
    if (x == 0)
        return "0";

    string s;
    while (x)
    {
        s += char('0' + (x & 1));
        x >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}
ll bee(const string &s)
{
    ll x = 0;
    for (char c : s)
    {
        x = x * 2 + (c - '0');
    }
    return x;
}

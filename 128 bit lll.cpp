typedef __int128 lll;

istream &operator>>(istream &in, lll &x)
{
    string s;
    in >> s;

    x = 0;
    int sign = 1;
    int i = 0;

    if (s[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for (; i < (int)s.size(); i++)
        x = x * 10 + (s[i] - '0');

    x *= sign;
    return in;
}
ostream &operator<<(ostream &out, lll x)
{
    if (x == 0)
    {
        out << 0;
        return out;
    }

    if (x < 0)
    {
        out << '-';
        x = -x;
    }

    string s;

    while (x > 0)
    {
        s += char('0' + x % 10);
        x /= 10;
    }

    reverse(s.begin(), s.end());

    out << s;
    return out;
}

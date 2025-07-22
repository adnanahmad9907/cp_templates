
ll modinv(ll x)
{
    return pow(x, mod - 2);
}

struct F
{
    ll nu, den;

    F(ll _nu = 0, ll _den = 1)
    {
        nu = (_nu % mod + mod) % mod;
        den = (_den % mod + mod) % mod;
    }

    ll value() const
    {
        return nu * modinv(den) % mod;
    }

    F operator*(const F &other) const
    {
        return F((nu * other.nu) % mod, (den * other.den) % mod);
    }

    F operator+(const F &other) const
    {
        ll lcm_den = (den * other.den) % mod;
        ll new_nu = (nu * other.den + other.nu * den) % mod;
        return F(new_nu, lcm_den);
    }

    F operator-(const F &other) const
    {
        ll lcm_den = (den * other.den) % mod;
        ll new_nu = (nu * other.den - other.nu * den + mod * mod) % mod;
        return F(new_nu, lcm_den);
    }
    F operator/(const F &other) const
    {
        return F((nu * other.den) % mod, (den * other.nu) % mod);
    }
};

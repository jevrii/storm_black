// MOD nCr from factorial formula

#define MOD 1000000007
long long fact[MAXN], minv[MAXN], finv[MAXN];

void init_ncr() {
    fact[0] = fact[1] = minv[0] = minv[1] = finv[0] = finv[1] = 1;
    for (long long i = 2; i < MAXN; i++){
        fact[i] = i * fact[i-1] % MOD;
        minv[i] = minv[MOD % i] * (MOD - MOD / i) % MOD;
        finv[i] = minv[i] * finv[i - 1] % MOD;
    }
}

int ncr(int n, int r) {
    if (r > n) return 0;
    return fact[n] * finv[r] % MOD * finv[n - r] % MOD;
}

// Pascal's triangle from nCr recursion: O(n^2) init, exact

void init_pas() {
	for (int i = 0; i < MAXN; i++) { // pas[n][r] stores C(n, r)
		pas[i][0] = pas[i][i] = 1;
		for (int j = 1; j < i; j++) {
			pas[i][j] = (pas[i - 1][j] + pas[i - 1][j - 1]);
		}
	}
}

// Large approximate without mod (binomial probabilities): log
long double binomial_prob (int n, int r, long double p, long double q) {
    return expl(lgamma(n+1) - lgamma(r+1) - lgamma(n-r+1) + r*logl(p) + (n-r) * logl(q));
}

// TODO: Lucas's Theorem

long long mpow(long long a, long long p) {
    if (p == 0) {
        return 1;
    }
    if (p == 1) {
        return a % MOD;
    }
    if (p % 2 == 0) {
        auto x = mpow(a, p / 2);
        return x * x % MOD;
    }
    return a * mpow(a, p - 1) % MOD;
}
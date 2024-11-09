#define MX 10000007
int min_prime_factor[MX + 5];
vector<int> primes;

void sieve(){
	for (long long i = 2; i <= MX; i++) {
		if(!min_prime_factor[i]) min_prime_factor[i] = i, primes.pb(i);
		for (long long j = 0; i * primes[j] <= MX; j++){
			min_prime_factor[i * primes[j]] = primes[j];
			if(i % primes[j] == 0) break;
		}
	}
}

vector<int> factorize(int x){
	vector<int> a;
	for(int j = x; j > 1;)
		a.pb(min_prime_factor[j]), j /= min_prime_factor[j];
	return a;
}

void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
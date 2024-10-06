mt19937 rng;

long long rand(long long l, long long r) { // closed interval [l, r]
    return uniform_int_distribution<int>(l, r)(rng);
}

// shuffle(a.begin(), a.end(), rng);

rng = mt19937 (chrono::steady_clock::now().time_since_epoch().count());
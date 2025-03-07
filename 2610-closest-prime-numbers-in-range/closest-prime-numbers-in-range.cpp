class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
    if (right < 2) return {-1, -1};

    int N = right + 1;
    vector<bool> isPrime(N, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = max(2, left); i <= right; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    int num1 = -1, num2 = -1, minDiff = INT_MAX;
    for (size_t i = 1; i < primes.size(); i++) {
        int diff = primes[i] - primes[i - 1];
        if (diff < minDiff) {
            num1 = primes[i - 1];
            num2 = primes[i];
            minDiff = diff;
        }
    }

    return {num1, num2};
    }
};
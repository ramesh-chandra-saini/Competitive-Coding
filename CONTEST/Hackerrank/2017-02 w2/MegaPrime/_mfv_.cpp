#include<bits/stdc++.h>
using namespace std;

inline bool hasPrimeDigitsOnly(long long n) {
    while (n > 0) {
        int d = int(n % 10);
        if (d != 2 && d != 3 && d != 5 && d != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

vector<int> getPrimesTill(int max) {
    vector<int> primes;
    vector<bool> isPrime(1 + max, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= max; i++)
        if (isPrime[i])
            for (int j = i * i; j <= max; j += i)
                isPrime[j] = false;
    for (int i = 2; i < isPrime.size(); i++)
        if(isPrime[i])
            primes.push_back(i);
    return primes;
}

const int MAX_ROOT = (int)sqrt(1e15);

int countMegaPrimes(long long first, long long last) {
    if (first > last) {
        return 0;
    }
    static vector<int> primes = getPrimesTill(MAX_ROOT);
    vector<bool> isPrime(last - first + 1, true); // isPrime[i] <-> (i + first) is prime
    for (int p : primes) {
        long long p2 = 1LL * p * p;
        if (p2 > last)
            break;
        long long from = max(1LL * p, (first + p - 1) / p) * p;
        int fromShifted = (int)(from - first);
        int lastShifted = (int)(last - first);
        for (int i = fromShifted; i <= lastShifted; i += p)
            isPrime[i] = false;
    }
    int count = 0;
    for (int i = 0; i < (int)isPrime.size(); i++) {
        if (isPrime[i] && hasPrimeDigitsOnly(i + first)) {
            count++;
        }
    }
    return count;
}

int main() {
    long long first, last;
    scanf("%lld %lld", &first, &last);
    const int CHUNK = 10 * 1000 * 1000;
    const int CHUNK_FIRST = 2222222; // 7 digits
    const int CHUNK_LAST = 7777777; // 7 digits
    const int LAST_BEFORE_CHUNK = 777777; // 6 digits
    long long count = 0;
    if (last <= LAST_BEFORE_CHUNK) {
        count = countMegaPrimes(first, last);
    } else {
        if (first <= LAST_BEFORE_CHUNK) {
            count = countMegaPrimes(first, LAST_BEFORE_CHUNK);
            first = LAST_BEFORE_CHUNK + 1;
        }
        for (long long partFirst = first / CHUNK * CHUNK + CHUNK_FIRST; partFirst <= last; partFirst += CHUNK) {
            if (hasPrimeDigitsOnly(partFirst)) {
                long long partLast = partFirst - CHUNK_FIRST + CHUNK_LAST;
                count += countMegaPrimes(max(first, partFirst), min(last, partLast));
            }
        }
    }
    printf("%lld", count);
    return 0;
}

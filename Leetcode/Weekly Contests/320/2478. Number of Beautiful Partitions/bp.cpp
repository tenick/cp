#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <math.h>

using namespace std;

typedef long long ll;

const int MAX_ANS = (int)(pow(10, 9) + 7);

ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll nCr(ll n, ll r){
    ll a = 1, b = 1;
    
    if (n - r < r){
        r = n - r;
    }

    if (r != 0){
        while (r){
            a = a * n;
            b = b * r;

            ll g = gcd(a, b);
            a = a/g;
            b = b/g;

            n--;
            r--;
        }
    }
    else {
        a = 1;
    }

    return a;
}

int beautifulPartitions(string s, int k, int minLength) {
    int countPartitions = 0;
    unordered_set<char> primes {'2', '3', '5', '7'};

    auto isPrime = [](char c, unordered_set<char>& primes){
        return primes.find(c) != primes.end();
    };

    // handle edge case
    if (!isPrime(s[0], primes) || isPrime(s[s.size()], primes))
        return 0;

    // get all parts
    vector<string> parts;
    bool buildingString = true, waitForPrime = false;
    string currPart = "";
    for (int i = 0; i < s.size(); i++){
        if (isPrime(s[i], primes)){
            if (waitForPrime && currPart.size() >= minLength){
                parts.push_back(currPart);
                currPart = {s[i]};
                waitForPrime = false;
                continue;
            }
        }
        else waitForPrime = true;
        currPart.push_back(s[i]);
    }
    parts.push_back(currPart);

    // count possible combinations
    int n = k;
    int r = parts.size() - k;

    // logging
    cout << "parts: " << parts.size() << '\n';
    for (string part : parts){
        cout << part << '\n';
    }

    return nCr(r + n - 1, r) % MAX_ANS;
}

int main(){
    string s = "3312958";
    s = "242538614532395749146912679859";
    int k = 3, minLength = 1;
    k = 1;
    minLength = 6;

    s = "783938233588472343879134266968";
    k = 4;
    minLength = 6;

    int ans = beautifulPartitions(s, k, minLength);
    cout << "beautiful partitions: " << ans << '\n';
}
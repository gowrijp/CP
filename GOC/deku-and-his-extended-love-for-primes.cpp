/*
https://www.hackerrank.com/contests/goc-cdc-series-6/challenges/deku-prime-love


*/

#include <bits/stdc++.h> 
using namespace std; 
  
// To store the prime numbers 
unordered_set<int> allPrimes; 
  
// Function that find prime numbers till limit 
void simpleSieve(int limit, vector<int> &prime) { 
    bool mark[limit + 1]; 
    memset(mark, false, sizeof(mark));  
    // Find primes using Sieve of Eratosthenes 
    for (int i = 2; i <= limit; ++i) { 
        if (mark[i] == false) { 
            prime.push_back(i); 
            for (int j = i; j <= limit; j += i){ 
                mark[j] = true; 
            } 
        } 
    } 
} 
  
// Function that finds all prime numbers in given range using Segmented Sieve 
void primesInRange(int low, int high) {  
    int limit = floor(sqrt(high)) + 1;  
    vector<int> prime; 
    // Compute all primes less than or equals to sqrt(high) using Simple Sieve 
    simpleSieve(limit, prime);   //prime=[2,3]
    int n = high - low + 1; 
    bool mark[n + 1]; 
    memset(mark, false, sizeof(mark)); 
 
    for (int i = 0; i < prime.size(); i++){ 
        int loLim = floor(low / prime[i]); 
        loLim *= prime[i]; 
        // Find the minimum number in [low..high] that is a multiple of prime[i] 
        if (loLim < low) { 
            loLim += prime[i]; 
        } 
        if (loLim == prime[i]) { 
            loLim += prime[i]; 
        }   
        // Mark the multiples of prime[i] in [low, high] as true 
        for (int j = loLim; j <= high; j += prime[i]) 
            mark[j - low] = true; 
    }   
    // Element which are not marked in range are Prime 
    for (int i = low; i <= high; i++) { 
        if (!mark[i - low]) { 
            allPrimes.insert(i); 
        } 
    } 
} 
  
// Function that finds longest subarray of prime numbers 
int maxPrimeSubarray(int arr[], int n) { 
    int current_max = 0; 
    int max_so_far = 0;  
    for (int i = 0; i < n; i++) {  
        // If element is Non-prime then updated current_max to 0 
        if (!allPrimes.count(arr[i]) || arr[i]==1) 
            current_max = 0; 
  
        // If element is prime, then update current_max and max_so_far 
        else { 
            current_max++; 
            max_so_far = max(current_max,max_so_far); 
        } 
    } 
    return max_so_far; 
} 


int main() { 
    allPrimes.clear();
    int n; cin>>n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max_el = *max_element(arr, arr + n); 
    int min_el = *min_element(arr, arr + n); 
  
    // Find prime in the range [min_el, max_el] 
    primesInRange(min_el, max_el); 
    cout << maxPrimeSubarray(arr, n)<<endl; 
    return 0; 
  
}

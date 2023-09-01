#include <iostream>
#include <cstring> // For memset

class Solution {
public:
    // Method 1: Recursive Solution
    // Time Complexity (TC): O(2^n)
    // Space Complexity (SC): O(n)
    long long int RecursiveSolution(long long int n){
        if(n <= 1) return n;
        return RecursiveSolution(n-1) + RecursiveSolution(n-2);
    }
    
    /* Method 2:
    DP-Memoization
    TC: O(n)
    SC: O(n)
    */
    int dp[1001]; // Memoization table to store computed values
    
    long long int Memoization(long long int n){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n]; // If value is already computed, return it
        return dp[n] = (Memoization(n-1) + Memoization(n-2)) % 1000000007;
    }
    
    /* Method 3:
    DP - Tabulation
    TC: O(n)
    SC: O(n)
    */
    long long int Tabulation(long long int n){
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }
        
        return dp[n];
    }
    
    /* Method 4:
    More Optimized Solution
    TC: O(n)
    SC: O(1)
    */
    long long int Optimized(long long int n){
        int prevFirst = 0;
        int prevSecond = 1;
        
        for(int i=2; i<=n; i++){
            int CurrentNum = (prevFirst + prevSecond) % 1000000007;
            prevFirst = prevSecond;
            prevSecond = CurrentNum;
        }
        
        return prevSecond;
    }
    
    // Wrapper function to select method based on user's choice
    long long int nthFibonacci(long long int n){
        // Uncomment the desired method to calculate nth Fibonacci number
        
        // Method 1: Recursive Solution
        // return RecursiveSolution(n);
        
        // Method 2: DP-Memoization
        // memset(dp, -1, sizeof(dp));
        // return Memoization(n);
        
        // Method 3: DP-Tabulation
        // return Tabulation(n);
        
        // Method 4: Optimized Solution
        return Optimized(n);
    }
};

int main() {
    Solution solution;
    long long int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    
    long long int result = solution.nthFibonacci(n);
    std::cout << "The " << n << "th Fibonacci number is: " << result << std::endl;
    
    return 0;
}

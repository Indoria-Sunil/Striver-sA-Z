class Solution {

    // =========================================================
    // Approach 1: Brute Force
    // Time: O(n)
    // Space: O(1)
    // =========================================================
    public double myPowBrute(double x, int n) {
        long nn = Math.abs((long) n);
        double ans = 1.0;

        for (long i = 0; i < nn; i++) {
            ans = ans * x;
        }

        if (n < 0) {
            ans = 1.0 / ans;
        }

        return ans;
    }

    // =========================================================
    // Approach 2: Optimal - Binary Exponentiation
    // Time: O(log n)
    // Space: O(1)
    // =========================================================
    public double myPowOptimal(double x, int n) {
        double ans = 1.0;

        long nn = n;

        // Handle negative exponent
        if (nn < 0) {
            nn = -nn;
        }

        while (nn > 0) {

            // If exponent is odd
            if (nn % 2 == 1) {
                ans = ans * x;
                nn = nn - 1;
            }

            // If exponent is even
            else {
                x = x * x;
                nn = nn / 2;
            }
        }

        // x^(-n) = 1 / x^n
        if (n < 0) {
            ans = 1.0 / ans;
        }

        return ans;
    }

    public double myPowOptimalRecursive(double x, int n) {
        long nn = Math.abs((long) n);

        double ans = power(x, nn);

        // Handle negative exponent
        if (n < 0) {
            ans = 1.0 / ans;
        }

        return ans;
    }

    private double power(double x, long n) {
        // Base case
        if (n == 0)
            return 1.0;

        // Recursive case
        double half = power(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }

    }

    public static void main(String[] args) {

        Solution s = new Solution();

        double x = 2.00000;
        int n = 10;

        System.out.println("Brute Force: " + s.myPowBrute(x, n));
        System.out.println("Optimal: " + s.myPowOptimal(x, n));
        System.out.println("Optimal Recursive: " + s.myPowOptimalRecursive(x, n));
    }
}
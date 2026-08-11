#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <numeric>

using namespace std;

/*
===============================================================================
    MASTER GUIDE: TIME & SPACE COMPLEXITY IN DATA STRUCTURES & ALGORITHMS
===============================================================================

 TABLE OF CONTENTS:
 ------------------
  1. Asymptotic Notations (Big-O, Big-Ω, Big-Θ)
  2. Cases Analysis (Best, Average, Worst Case)
  3. Rules for Calculating Complexity
  4. Common Code Patterns to Recognize
  5. Multiple Input Variables (O(N + M) vs O(N * M))
  6. Understanding Logarithms in DSA
  7. Algorithmic Time Complexities:
     - O(1)       Constant
     - O(log n)   Logarithmic
     - O(sqrt n)  Square Root
     - O(n)       Linear
     - O(n log n) Linearithmic
     - O(n^2)     Quadratic
     - O(n^3)     Cubic
     - O(2^n)     Exponential
     - O(3^n)     Exponential
     - O(n!)      Factorial
  8. Recursion, Recurrence Relations & Master Theorem
  9. Space Complexity Taxonomy (Input vs Auxiliary vs Output Space)
 10. Amortized Complexity Analysis
 11. Ultimate Complexity Cheat Sheet & Growth Hierarchy
 12. Practice Snippets for Self-Testing
===============================================================================
*/


// ============================================================================
// 1. ASYMPTOTIC NOTATIONS: Big-O, Big-Omega (Ω), Big-Theta (Θ)
// ============================================================================
/*
    Asymptotic analysis describes the behavior of code as input size 'n' 
    approaches infinity.

    1. Big-O Notation (O) -> ASYMPTOTIC UPPER BOUND
       - Definition: Big-O describes an asymptotic upper bound on how the 
         running time grows.
       - Clarification: Big-O does NOT automatically mean "worst case". 
         Best, average, and worst cases are distinct scenarios that can each 
         be expressed using Big-O (e.g., linear search has best-case O(1) 
         and worst-case O(n)).

    2. Big-Omega Notation (Ω) -> ASYMPTOTIC LOWER BOUND
       - Definition: Big-Ω describes an asymptotic lower bound on how the 
         running time grows.
       - Clarification: Best/average/worst case and O/Ω/Θ are two separate 
         concepts. Big-Ω simply means the growth rate is AT LEAST this fast as n scales.

    3. Big-Theta Notation (Θ) -> TIGHT BOUND (Exact Growth Rate)
       - Definition: Used when Upper Bound (O) and Lower Bound (Ω) match.
       - f(n) = Θ(g(n)) if and only if f(n) = O(g(n)) AND f(n) = Ω(g(n)).
       - Example: Iterating through an array of size n to compute sum is Θ(n) 
         because it ALWAYS takes exactly n steps (both best and worst cases are n).
*/


// ============================================================================
// 2. BEST, AVERAGE, AND WORST CASE ANALYSIS
// ============================================================================

// Linear Search Demonstration
//
// Array: [10, 20, 30, 40, 50]
// - Best Case:    Search 10 -> Element at index 0 -> O(1) time
// Average Case Example: Search 30 -> 3 comparisons -> O(n)
// (Under a typical uniform-position assumption, average linear search is O(n).)
// - Worst Case:   Search 50 or 99 -> Element at end / not present -> O(n) time
int linearSearchDemo(const vector<int>& arr, int target, string& caseType) {
    int comparisons = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == target) {
            if (i == 0) caseType = "Best Case";
            else caseType = "Average Case";
            cout << "  [Linear Search] Found " << target << " in " << comparisons << " comparison(s). (" << caseType << ")\n";
            return i;
        }
    }
    caseType = "Worst Case";
    cout << "  [Linear Search] " << target << " not found after " << comparisons << " comparison(s). (" << caseType << ")\n";
    return -1;
}


// ============================================================================
// 3. RULES FOR CALCULATING COMPLEXITY FROM CODE
// ============================================================================
/*
    RULE 1: Drop Constants
            O(2n + 5) ---> O(n)
            O(100)    ---> O(1)

    RULE 2: Keep the Dominant Term (Drop non-dominant terms)
            O(n^2 + 5n + 100) ---> O(n^2)
            O(n + log n)      ---> O(n)

    RULE 3: Sequential Operations ADD Complexity
            Statement 1: O(A)
            Statement 2: O(B)
            Total Time = O(A + B)

    RULE 4: Nested Operations MULTIPLY Complexity
            Loop 1 (runs A times):
                Loop 2 (runs B times):
            Total Time = O(A * B)
*/

void demonstrateCalculationRules(int n) {
    // Sequential Code: O(n) + O(n) = O(2n) -> Rule 1 -> O(n)
    cout << "  1. Sequential loops: O(n) + O(n) = O(n)\n";
    for (int i = 0; i < n; i++) { /* O(1) work */ }
    for (int i = 0; i < n; i++) { /* O(1) work */ }

    // Nested Code: O(n) * O(n) = O(n^2)
    cout << "  2. Nested loops: O(n) * O(n) = O(n^2)\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            /* O(1) work */
        }
    }

    // Dominant Term Code: Loop 1 is O(n^2), Loop 2 is O(n).
    // Total = O(n^2 + n) -> Rule 2 -> O(n^2)
    cout << "  3. Dominant term selection: O(n^2 + n) = O(n^2)\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { /* O(1) */ }
    }
    for (int i = 0; i < n; i++) { /* O(1) */ }
}


// ============================================================================
// 4. COMMON CODE PATTERNS TO RECOGNIZE
// ============================================================================
/*
    Pattern matching is the fastest way to estimate complexity in interviews.
    
    1. Linear Time: O(n)
       for (int i = 0; i < n; i++) { ... }
       
    2. Logarithmic Time: O(log n)
       for (int i = 1; i < n; i *= 2) { ... }
       
    3. Quadratic Time: O(n^2)
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++) { ... }
       }
       
    4. Linearithmic Time: O(n log n)
       for (int i = 0; i < n; i++) {
           for (int j = 1; j < n; j *= 2) { ... }
       }
*/


// ============================================================================
// 5. DIFFERENT INPUT SIZES (MULTIPLE VARIABLES)
// ============================================================================
/*
    When code depends on TWO OR MORE distinct inputs (e.g., n and m), 
    do NOT reduce them to a single variable.

    Example A: Sequential loops over different inputs
        for (int i = 0; i < n; i++) ...
        for (int j = 0; j < m; j++) ...
        Time Complexity: O(n + m)

    Example B: Nested loops over different inputs
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) ...
        Time Complexity: O(n * m)
*/

void multipleInputsDemo(int n, int m) {
    cout << "  a. Sequential over inputs n=" << n << ", m=" << m << " -> Time: O(n + m)\n";
    for (int i = 0; i < n; i++) {}
    for (int j = 0; j < m; j++) {}

    cout << "  b. Nested over inputs n=" << n << ", m=" << m << " -> Time: O(n * m)\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {}
    }
}


// ============================================================================
// 6. UNDERSTANDING LOGARITHMS IN DSA
// ============================================================================
/*
    What is a logarithm?
        log_b(n) = k  <===>  b^k = n
        
        Example: log_2(8) = 3 because 2^3 = 8.

    Why does O(log n) appear in algorithms?
        Whenever an algorithm repeatedly DIVIDES the problem size by a constant 
        factor (usually 2) at each step, its time complexity is O(log_2 n).

    Why is the base ignored in Big-O (e.g., log_2 vs log_10)?
        By logarithmic change-of-base formula:
        log_a(n) = log_b(n) / log_b(a)

        Since 1 / log_b(a) is a CONSTANT, by Rule 1 (Drop Constants):
        O(log_2 n) = O(log_10 n) = O(log_e n) = O(log n)
*/

void logarithmicDoublingDemo(int n) {
    cout << "  Loop halving problem size from n = " << n << ": ";
    int steps = 0;
    while (n > 0) {
        cout << n << " ";
        n /= 2;
        steps++;
    }
    cout << "\n  Total iterations required = " << steps << " (~log2(n))\n";
}


// ============================================================================
// 7. STANDARD ALGORITHMIC TIME COMPLEXITY CLASSES
// ============================================================================

// --- O(1) CONSTANT TIME ---
// Formula-based computation. Execution count is independent of n.
long long sumOfNumbers(int n) {
    return 1LL * n * (n + 1) / 2; // Time: O(1), Space: O(1)
}

// --- O(log n) LOGARITHMIC TIME ---
// Binary Search (Iterative)
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target)  left = mid + 1;
        else                    right = mid - 1;
    }
    return -1; // Time: O(log n), Space: O(1)
}

// Euclidean GCD Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; // Time: O(log(min(a, b))), Space: O(1)
}

// --- O(sqrt n) SQUARE ROOT TIME ---
// Prime Checker & Divisors Finder
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true; // Time: O(sqrt n), Space: O(1)
}

// --- O(n) LINEAR TIME ---
// Kadane's Algorithm for Maximum Subarray Sum
int maxSubarraySum(const vector<int>& arr) {
    if (arr.empty()) return 0;
    int currentSum = arr[0], answer = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        answer = max(answer, currentSum);
    }
    return answer; // Time: O(n), Space: O(1)
}

// --- O(n log n) LINEARITHMIC TIME ---
// Merge Sort Helper
void mergeArrays(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else                  temp.push_back(arr[j++]);
    }
    while (i <= mid)   temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);
    for (size_t k = 0; k < temp.size(); k++) arr[left + k] = temp[k];
}

// Merge Sort Implementation
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeArrays(arr, left, mid, right); // Time: O(n log n), Space: O(n)
}

// --- O(n^2) QUADRATIC TIME ---
// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    } // Time: O(n^2), Space: O(1)
}

// --- O(n^3) CUBIC TIME ---
// Matrix Multiplication
void matrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    } // Time: O(n^3), Space: O(n^2)
}

// --- O(2^n) EXPONENTIAL TIME ---
// Power Set Generation (All Subsets)
// Note: Generation tree structure cost is O(2^n). Since printing each subset takes up to O(n) time,
// total runtime of this print loop is O(n * 2^n).
void generateSubsets(const vector<int>& arr, int index, vector<int>& current) {
    if (index == (int)arr.size()) {
        cout << "{ ";
        for (int x : current) cout << x << " ";
        cout << "} ";
        return;
    }
    current.push_back(arr[index]);
    generateSubsets(arr, index + 1, current); // Choice 1: Include
    current.pop_back();
    generateSubsets(arr, index + 1, current); // Choice 2: Exclude
} // Generation Cost: O(2^n) | Total Execution (with printing): O(n * 2^n) | Space: O(n) call stack

// --- O(3^n) EXPONENTIAL TIME ---
// 3-Branch Call Tree
void threeBranchRecursion(int n) {
    if (n <= 0) return;
    threeBranchRecursion(n - 1);
    threeBranchRecursion(n - 1);
    threeBranchRecursion(n - 1);
} // Time: O(3^n), Space: O(n)

// --- O(n!) FACTORIAL TIME ---
// Permutations Generation
// Note: Generation tree structure cost is O(n!). Since printing each permutation takes O(n) time,
// total runtime of this print loop is O(n * n!).
void generatePermutations(vector<int>& arr, int index) {
    if (index == (int)arr.size()) {
        cout << "[ ";
        for (int x : arr) cout << x << " ";
        cout << "] ";
        return;
    }
    for (int i = index; i < (int)arr.size(); i++) {
        swap(arr[index], arr[i]);
        generatePermutations(arr, index + 1);
        swap(arr[index], arr[i]); // Backtrack
    }
} // Generation Cost: O(n!) | Total Execution (with printing): O(n * n!) | Space: O(n) call stack


// ============================================================================
// 8. RECURSION, RECURRENCE RELATIONS & MASTER THEOREM
// ============================================================================
/*
    RECURRENCE RELATIONS:
    --------------------
    Mathematical equations defining a function in terms of its smaller inputs.

    Common Recurrence Patterns:
    1. T(n) = T(n - 1) + O(1)    ---> O(n)      [e.g., Linear Recursion / Factorial]
    2. T(n) = T(n - 1) + O(n)    ---> O(n^2)    [e.g., Recursive Selection Sort]
    3. T(n) = T(n / 2) + O(1)    ---> O(log n)  [e.g., Recursive Binary Search]
    4. T(n) = 2T(n / 2) + O(n)   ---> O(n log n)[e.g., Merge Sort]
    5. T(n) = 2T(n - 1) + O(1)   ---> O(2^n) 

    THE MASTER THEOREM (For Divide and Conquer):
    --------------------------------------------
    Applies to recurrences of the form:
        T(n) = a * T(n / b) + f(n)
        Where:
          a >= 1  (number of subproblems generated)
          b > 1   (factor by which problem size is divided)
          f(n) = O(n^c) (work done outside recursive calls)

    Compare n^(log_b(a)) with f(n) = O(n^c):
      - Case 1: If log_b(a) > c  ===> T(n) = O( n^(log_b(a)) )
      - Case 2: If log_b(a) == c ===> T(n) = O( n^c * log n )
      - Case 3: If log_b(a) < c  ===> T(n) = O( n^c )

    EXAMPLES:
      - Binary Search: T(n) = 1*T(n/2) + O(1)
        a=1, b=2, c=0. log_2(1) = 0 == c (Case 2) ===> T(n) = O(n^0 * log n) = O(log n)
      - Merge Sort:    T(n) = 2*T(n/2) + O(n^1)
        a=2, b=2, c=1. log_2(2) = 1 == c (Case 2) ===> T(n) = O(n^1 * log n) = O(n log n)
*/


// ============================================================================
// 9. SPACE COMPLEXITY TAXONOMY
// ============================================================================
/*
    TOTAL SPACE = INPUT SPACE + AUXILIARY SPACE + OUTPUT SPACE + CALL STACK SPACE

    1. Input Space:
       Space occupied by parameters passed into the function.
       (e.g., vector<int> input of size n -> Input space O(n)).

    2. Auxiliary Space:
       EXTRA temporary memory allocated by the algorithm during execution.
       (e.g., temp variables, hash maps, intermediate arrays).
       *Note: When asked for Space Complexity in interviews, interviewers 
        usually refer specifically to AUXILIARY SPACE.*

    3. Output Space:
       Space required to construct and return the final answer.
       (e.g., returning all subset vectors of size 2^n -> Output space O(2^n * n)).

    4. Call Stack Space (Recursion Depth):
       Memory used by function call frames in recursive calls.
       (e.g., recursion tree depth of max depth d -> Stack space O(d)).
*/

// Example demonstrating Space Taxonomy distinction:
vector<int> spaceTaxonomyDemo(const vector<int>& inputArr) { // Input Space: O(n)
    
    int tempMax = INT_MIN; // Auxiliary Space: O(1)
    
    // Output vector creation
    vector<int> result; // Output Space: O(k) where k is filtered size
    
    for (int x : inputArr) {
        if (x > 0) {
            result.push_back(x);
        }
    }
    return result; 
    // Total Auxiliary Space = O(1)
    // Total Space = Input O(n) + Output O(k) = O(n)
}


// ============================================================================
// 10. AMORTIZED COMPLEXITY ANALYSIS
// ============================================================================
/*
    What is Amortized Analysis?
    ---------------------------
    Amortized analysis calculates the AVERAGE time taken per operation over a 
    sequence of operations, especially when a rare, expensive operation occurs 
    infrequently alongside many cheap operations.

    Classic Example: Dynamic Array (std::vector::push_back)
    - Most push_back operations take O(1) time.
    - When capacity is full (1, 2, 4, 8, 16...), push_back doubles capacity:
        Allocates new memory block of size 2 * N -> Copies N elements -> O(N) time.

    Aggregate Intuition:
    - To insert N elements into an initially empty vector:
      * Cheap insertions: N operations at O(1) each = N work.
      * Resizing costs: 1 + 2 + 4 + 8 + ... + N = 2N work.
      * Total Work for N insertions = N + 2N = 3N work.
      * Average (Amortized) cost per push_back = (3N) / N = 3 operations = O(1).
*/

void amortizedAnalysisDemo() {
    vector<int> v;
    cout << "  Demonstrating Dynamic Array Capacity Resizing:\n";
    for (int i = 1; i <= 9; i++) {
        size_t oldCap = v.capacity();
        v.push_back(i);
        if (v.capacity() != oldCap) {
            cout << "  --> CAPACITY DOUBLED! Old: " << oldCap << " -> New: " << v.capacity() 
                 << " (Cost of copying elements: O(" << v.size() - 1 << "))\n";
        } else {
            cout << "      Pushed " << i << " | Capacity: " << v.capacity() << " (Normal O(1) insertion)\n";
        }
    }
}


// ============================================================================
// 11. ULTIMATE COMPLEXITY CHEAT SHEET & GROWTH RATE HIERARCHY
// ============================================================================
/*
    GROWTH RATE HIERARCHY (From Fastest/Best to Slowest/Worst):
    ----------------------------------------------------------
    
    O(1) < O(log n) < O(sqrt n) < O(n) < O(n log n) < O(n^2) < O(n^3) < O(2^n) < O(n!)
    
    * Note: The '<' symbol here means "grows more slowly than", 
      not strict mathematical inequality for all specific values of n.

    [BEST / SLOW GROWTH]                                        [WORST / EXPLOSIVE]
    
    Visual Value Comparison for Large Inputs:
    +---------------+----------+------------+------------+---------------+---------------+
    | Notation      | n = 10   | n = 100    | n = 1,000  | n = 10,000    | Standard Name |
    +---------------+----------+------------+------------+---------------+---------------+
    | O(1)          | 1        | 1          | 1          | 1             | Constant      |
    | O(log n)      | ~3       | ~7         | ~10        | ~13           | Logarithmic   |
    | O(sqrt n)     | ~3       | 10         | ~31        | 100           | Square Root   |
    | O(n)          | 10       | 100        | 1,000      | 10,000        | Linear        |
    | O(n log n)    | ~33      | ~664       | ~9,965     | ~132,877      | Linearithmic  |
    | O(n^2)        | 100      | 10,000     | 1,000,000  | 100,000,000   | Quadratic     |
    | O(2^n)        | 1,024    | ~1.26*10^30| Impossible | Impossible    | Exponential   |
    | O(n!)         | 3,628,800| Impossible | Impossible | Impossible    | Factorial     |
    +---------------+----------+------------+------------+---------------+---------------+
*/


// ============================================================================
// 12. PRACTICE CORNER: TEST YOURSELF WITH SNIPPETS
// ============================================================================
/*
    SNIPPET 1:
        for (int i = 0; i < n; i += 2) {
            // O(1) work
        }
        Answer: Time: O(n) [n/2 steps -> drop constant 1/2 -> O(n)] | Space: O(1)

    SNIPPET 2:
        for (int i = 1; i <= n; i *= 3) {
            // O(1) work
        }
        Answer: Time: O(log3 n) = O(log n) | Space: O(1)

    SNIPPET 3:
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // O(1) work
            }
        }
        Answer: Time: O(n^2) [n + (n-1) + ... + 1 = n(n+1)/2 -> O(n^2)] | Space: O(1)

    SNIPPET 4:
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j *= 2) {
                // O(1) work
            }
        }
        Answer: Time: O(n log n) [Outer loop n times * Inner loop log n times] | Space: O(1)

    SNIPPET 5:
        void solve(int n) {
            if (n <= 1) return;
            solve(n - 1);
        }
        Answer: Time: O(n) | Space: O(n) call stack space

    SNIPPET 6:
        void solve(int n) {
            if (n <= 1) return;
            solve(n / 2);
            solve(n / 2);
        }
        Answer: Recurrence T(n) = 2T(n/2) + O(1) -> Master Theorem Case 1 -> Time: O(n) | Space: O(log n)
*/


// ============================================================================
// MAIN FUNCTION - EXECUTABLE DEMONSTRATION DRIVER
// ============================================================================

int main() {
    cout << "===================================================================\n";
    cout << "   DSA PRACTICE: TIME AND SPACE COMPLEXITY MASTER REFERENCE GUIDE   \n";
    cout << "===================================================================\n\n";

    // 1. Cases Demo
    cout << "=== 1. BEST, AVERAGE & WORST CASE DEMONSTRATION ===\n";
    vector<int> searchArr = {10, 20, 30, 40, 50};
    string caseLabel;
    linearSearchDemo(searchArr, 10, caseLabel); // Best
    linearSearchDemo(searchArr, 30, caseLabel); // Average
    linearSearchDemo(searchArr, 99, caseLabel); // Worst
    cout << "\n";

    // 2. Calculation Rules Demo
    cout << "=== 2. COMPLEXITY CALCULATION RULES DEMO ===\n";
    demonstrateCalculationRules(3);
    cout << "\n";

    // 3. Multiple Inputs Demo
    cout << "=== 3. MULTIPLE INPUT VARIABLES DEMO ===\n";
    multipleInputsDemo(3, 4);
    cout << "\n";

    // 4. Logarithm Intuition Demo
    cout << "=== 4. LOGARITHMIC REDUCTION DEMO ===\n";
    logarithmicDoublingDemo(16);
    cout << "\n";

    // 5. Standard Algorithm Demos
    cout << "=== 5. STANDARD COMPLEXITY CLASS EXAMPLES ===\n";
    cout << "  O(1) Gauss Sum(10): " << sumOfNumbers(10) << "\n";
    cout << "  O(sqrt n) Prime Check(29): " << (isPrime(29) ? "Prime" : "Not Prime") << "\n";
    
    vector<int> kadaneArr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "  O(n) Kadane's Max Subarray Sum: " << maxSubarraySum(kadaneArr) << "\n";

    vector<int> mArr = {7, 2, 9, 1, 5};
    mergeSort(mArr, 0, mArr.size() - 1);
    cout << "  O(n log n) Merge Sort Result: ";
    for (int x : mArr) cout << x << " ";
    cout << "\n";

    cout << "  O(2^n) Subsets of {1, 2}: ";
    vector<int> subArr = {1, 2};
    vector<int> curSub;
    generateSubsets(subArr, 0, curSub);
    cout << "\n";

    cout << "  O(n!) Permutations of {1, 2}: ";
    vector<int> permArr = {1, 2};
    generatePermutations(permArr, 0);
    cout << "\n\n";

    // 6. Amortized Analysis Demo
    cout << "=== 6. AMORTIZED ANALYSIS DEMO ===\n";
    amortizedAnalysisDemo();
    cout << "\n";

    return 0;
}
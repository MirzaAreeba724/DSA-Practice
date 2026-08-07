#include <iostream>
using namespace std;

int main() {
    // Standard dimension size for patterns
    int n = 4;
    int num = 1;

    // =====================================================
    // Pattern 1: Square Pattern (Same Number)
    // Output:
    // 1 1 1 1
    // 1 1 1 1
    // 1 1 1 1
    // 1 1 1 1
    // =====================================================
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 2: Square Pattern (Continuous Numbers)
    // Output:
    // 1  2  3  4
    // 5  6  7  8
    // 9 10 11 12
    // 13 14 15 16
    // =====================================================
    num = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 3: Square Pattern (Repeated Numbers per Row)
    // Output:
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4
    // =====================================================
    for(int i = 0; i < n; i++) {
        num = 1; // Reset starting number for each row
        for(int j = 0; j < n; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 4: Triangle Pattern (Same Number)
    // Output:
    // 1
    // 1 1
    // 1 1 1
    // 1 1 1 1
    // =====================================================
    num = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 5: Triangle Pattern (Increasing Numbers)
    // Output:
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // =====================================================
    for(int i = 0; i < n; i++) {
        num = 1;
        for(int j = 0; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 6: Triangle Pattern (Repeated Row Number)
    // Output:
    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4
    // =====================================================
    num = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << num << " ";
        }
        cout << endl;
        num++; // Increment number after completing each row
    }
    cout << endl;


    // =====================================================
    // Pattern 7: Floyd's Triangle
    // Output:
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // =====================================================
    num = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 8: Reverse Triangle (Stars)
    // Output:
    // * * * *
    // * * *
    // * *
    // *
    // =====================================================
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 9: Reverse Triangle (Same Number)
    // Output:
    // 1 1 1 1
    // 1 1 1
    // 1 1
    // 1
    // =====================================================
    num = 1;
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 10: Reverse Triangle (Increasing Numbers)
    // Output:
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1
    // =====================================================
    for(int i = n; i > 0; i--) {
        num = 1;
        for(int j = 0; j < i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 11: Reverse Triangle (Continuous Numbers)
    // Output:
    // 1 2 3 4
    // 5 6 7
    // 8 9
    // 10
    // =====================================================
    num = 1;
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 12: Reverse Triangle (Repeated Row Number)
    // Output:
    // 1 1 1 1
    // 2 2 2
    // 3 3
    // 4
    // =====================================================
    for(int i = n; i > 0; i--) {
        num = n - i + 1; // Formula to calculate current row value
        for(int j = 0; j < i; j++) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 13: Right-Aligned Triangle (Stars)
    // Output:
    //       *
    //     * *
    //   * * *
    // * * * *
    // =====================================================
    for(int i = 0; i < n; i++) {
        // Print leading spaces
        for(int j = 0; j < n - i - 1; j++) {
            cout << "  ";
        }
        // Print stars
        for(int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 14: Right-Aligned Triangle (Numbers)
    // Output:
    //       1
    //     1 2
    //   1 2 3
    // 1 2 3 4
    // =====================================================
    for(int i = 0; i < n; i++) {
        num = 1;
        // Print leading spaces
        for(int j = 0; j < n - i - 1; j++) {
            cout << "  ";
        }
        // Print values
        for(int j = 0; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 15: Inverted Right Triangle (Repeated Row Number)
    // Output:
    // 1111
    //  222
    //   33
    //    4
    // =====================================================
    for(int i = 0; i < n; i++) {
        // Print leading spaces
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        // Print row number
        for(int j = 0; j < n - i; j++) {
            cout << i + 1;
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 16: Inverted Right Triangle (Fixed Number)
    // Output:
    // 4 4 4 4
    //  4 4 4
    //   4 4
    //    4
    // =====================================================
    num = 4;
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < n - i; j++) {
            cout << " ";
        }
        for(int j = 0; j < i; j++) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 17: Inverted Right Triangle (Sequential Row Numbers)
    // Output:
    // 1 1 1 1
    //  2 2 2
    //   3 3
    //    4
    // =====================================================
    num = 1;
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < n - i; j++) {
            cout << " ";
        }
        for(int j = 0; j < i; j++) {
            cout << num << " ";
        }
        cout << endl;
        num++;
    }
    cout << endl;


    // =====================================================
    // Pattern 18: Full Pyramid (Stars)
    // Output:
    //       *
    //     * * *
    //   * * * * *
    // * * * * * * *
    // =====================================================
    for(int i = 0; i < n; i++) {
        // Print spaces
        for(int j = 0; j < n - i - 1; j++) {
            cout << "  ";
        }
        // Print left half including center
        for(int j = 0; j <= i; j++) {
            cout << "* ";
        }
        // Print right half
        for(int j = i; j > 0; j--) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 19: Full Pyramid (Palindromic Numbers)
    // Output:
    //       1
    //     1 2 1
    //   1 2 3 2 1
    // 1 2 3 4 3 2 1
    // =====================================================
    for(int i = 0; i < n; i++) {
        // Spaces
        for(int j = 0; j < n - i - 1; j++) {
            cout << "  ";
        }
        // Ascending numbers
        for(int j = 0; j <= i; j++) {
            cout << j + 1 << " ";
        }
        // Descending numbers
        for(int j = i; j > 0; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 20: Hollow Square
    // Output:
    // * * * *
    // *     *
    // *     *
    // * * * *
    // =====================================================
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // Print star on boundaries, spaces inside
            if(i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 21: Hollow Rectangle
    // Output:
    // * * * * *
    // *       *
    // *       *
    // * * * * *
    // =====================================================
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n + 1; j++) {
            if(i == 0 || i == n - 1 || j == 0 || j == n) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 22: Hollow Pyramid
    // Output:
    //    *
    //   * *
    //  *   *
    // * * * *
    // =====================================================
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        if(i == n - 1) {
            // Base row: alternating star/space
            for(int j = 0; j < 2 * n - 1; j++) {
                cout << (j % 2 == 0 ? "*" : " ");
            }
        } else {
            cout << "*";
            if(i != 0) {
                for(int j = 0; j < 2 * i - 1; j++) {
                    cout << " ";
                }
                cout << "*";
            }
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 23: Diamond Pattern
    // Output:
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    // =====================================================
    // Top half
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (n - i - 1); j++) {
            cout << " ";
        }
        for(int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    // Bottom half
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < (n - i - 1); j++) {
            cout << " ";
        }
        for(int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 24: Hollow Diamond
    // Output:
    //     *
    //    * *
    //   *   *
    //  *     *
    //   *   *
    //    * *
    //     *
    // =====================================================
    // Top half
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (n - i - 1) + 1; j++) {
            cout << " ";
        }
        cout << "*";

        if(i != 0) {
            for(int j = 0; j < 2 * i - 1; j++) {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
    // Bottom half
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < (n - i - 1) + 1; j++) {
            cout << " ";
        }
        cout << "*";

        if(i != 0) {
            for(int j = 0; j < 2 * i - 1; j++) {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;


    // =====================================================
    // Pattern 25: Butterfly Pattern
    // Output:
    // *             *
    // * *         * *
    // * * *     * * *
    // * * * * * * * *
    // * * *     * * *
    // * *         * *
    // *             *
    // =====================================================
    // Upper wing section
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << "* ";
        }
        for(int j = 0; j < 2 * (n - i - 1); j++) {
            cout << "  ";
        }
        for(int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    // Lower wing section
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            cout << "* ";
        }
        for(int j = 0; j < 2 * (n - i - 1); j++) {
            cout << "  ";
        }
        for(int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
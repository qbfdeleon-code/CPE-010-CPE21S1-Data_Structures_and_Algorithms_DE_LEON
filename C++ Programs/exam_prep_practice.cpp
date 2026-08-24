#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// ==========================================
// 1. BASIC CONTROL FLOW
// ==========================================

// Check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Check if a year is a leap year
bool isLeapYear(int year) {
    // A year is leap if divisible by 4, except end-of-century years which must be divisible by 400.
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

// Generate Fibonacci sequence up to N terms using loops
void generateFibonacci(int n) {
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return;
    }
    long long t1 = 0, t2 = 1;
    cout << "Fibonacci Sequence (" << n << " terms): ";
    for (int i = 1; i <= n; ++i) {
        cout << t1 << (i == n ? "" : ", ");
        long long nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    cout << endl;
}

// ==========================================
// 2. STRING MANIPULATION
// ==========================================

// Check if a string is a palindrome (ignoring case)
bool isPalindrome(const string& str) {
    int start = 0;
    int end = str.length() - 1;
    while (start < end) {
        while (start < end && !isalnum(str[start])) start++;
        while (start < end && !isalnum(str[end])) end--;
        if (tolower(str[start]) != tolower(str[end])) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Count vowels and consonants in a string
void countVowelsAndConsonants(const string& str, int& vowels, int& consonants) {
    vowels = 0;
    consonants = 0;
    for (char c : str) {
        if (isalpha(c)) {
            char lowerC = tolower(c);
            if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
}

// Reverse a string without using built-in methods (e.g., std::reverse)
string reverseStringCustom(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
    return str;
}

// ==========================================
// 3. ARRAY OPERATIONS
// ==========================================

// Find largest, smallest, and second-largest element in an array
void findMinMaxSecondMax(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "Array is empty." << endl;
        return;
    }
    int smallest = arr[0];
    int largest = arr[0];
    int secondLargest = -1; // Flag for uninitialized if all elements equal
    bool hasSecond = false;

    for (int num : arr) {
        if (num < smallest) smallest = num;
        if (num > largest) {
            secondLargest = largest;
            largest = num;
            hasSecond = true;
        } else if (num < largest && (!hasSecond || num > secondLargest)) {
            secondLargest = num;
            hasSecond = true;
        }
    }

    cout << "Smallest element: " << smallest << endl;
    cout << "Largest element: " << largest << endl;
    if (hasSecond) {
        cout << "Second Largest element: " << secondLargest << endl;
    } else {
        cout << "Second Largest element: None (all elements are equal)" << endl;
    }
}

// Reverse an array in-place
void reverseArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Bubble Sort algorithm
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break; // Array is already sorted
    }
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    cout << endl;
}

// ==========================================
// 4. BASIC MATRIX MATH
// ==========================================

// Add two 2D matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> C(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Multiply two 2D matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    vector<vector<int>> C(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Transpose a 2D matrix
vector<vector<int>> transposeMatrix(const vector<vector<int>>& A) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> At(cols, vector<int>(rows, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            At[j][i] = A[i][j];
        }
    }
    return At;
}

// Utility function to print matrix
void printMatrix(const vector<vector<int>>& M) {
    for (const auto& row : M) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

// ==========================================
// MAIN FUNCTION / DEMONSTRATION DRIVER
// ==========================================

int main() {
    cout << "==========================================" << endl;
    cout << " 1. BASIC CONTROL FLOW EXAMPLES" << endl;
    cout << "==========================================" << endl;
    
    int primeNum = 29;
    cout << primeNum << " is prime? " << (isPrime(primeNum) ? "Yes" : "No") << endl;
    
    int year = 2024;
    cout << year << " is leap year? " << (isLeapYear(year) ? "Yes" : "No") << endl;
    
    generateFibonacci(10);
    cout << endl;

    cout << "==========================================" << endl;
    cout << " 2. STRING MANIPULATION EXAMPLES" << endl;
    cout << "==========================================" << endl;
    
    string testStr = "A man, a plan, a canal: Panama";
    cout << "\"" << testStr << "\" is palindrome? " << (isPalindrome(testStr) ? "Yes" : "No") << endl;
    
    string sampleStr = "Computer Engineering";
    int v = 0, c = 0;
    countVowelsAndConsonants(sampleStr, v, c);
    cout << "In \"" << sampleStr << "\": Vowels = " << v << ", Consonants = " << c << endl;
    
    string orig = "Hello World";
    cout << "Original: " << orig << " | Reversed: " << reverseStringCustom(orig) << endl;
    cout << endl;

    cout << "==========================================" << endl;
    cout << " 3. ARRAY OPERATIONS EXAMPLES" << endl;
    cout << "==========================================" << endl;
    
    vector<int> numbers = {12, 45, 7, 89, 23, 89, 34};
    cout << "Original Array: ";
    printArray(numbers);
    
    findMinMaxSecondMax(numbers);
    
    vector<int> revNumbers = numbers;
    reverseArray(revNumbers);
    cout << "Reversed Array: ";
    printArray(revNumbers);
    
    vector<int> sortedNumbers = numbers;
    bubbleSort(sortedNumbers);
    cout << "Sorted Array (Bubble Sort): ";
    printArray(sortedNumbers);
    cout << endl;

    cout << "==========================================" << endl;
    cout << " 4. BASIC MATRIX MATH EXAMPLES" << endl;
    cout << "==========================================" << endl;
    
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    
    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << "Matrix B:" << endl;
    printMatrix(B);
    
    cout << "Matrix Addition (A + B):" << endl;
    printMatrix(addMatrices(A, B));
    
    cout << "Matrix Multiplication (A * B):" << endl;
    printMatrix(multiplyMatrices(A, B));
    
    cout << "Transpose of Matrix A:" << endl;
    printMatrix(transposeMatrix(A));
    
    cout << "==========================================" << endl;
    return 0;
}

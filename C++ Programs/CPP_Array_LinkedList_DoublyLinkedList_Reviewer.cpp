#include <iostream>
#include <string>
using namespace std;

/*
    C++ DATA STRUCTURES PRACTICE REVIEWER

    Topics:
    1. Basic Control Flow
       - Prime number
       - Leap year
       - Fibonacci

    2. String Manipulation
       - Palindrome
       - Reverse string
       - Vowels/consonants

    3. Array Operations
       - Largest
       - Smallest
       - Second largest
       - Reverse
       - Bubble sort

    4. Matrix Math
       - Addition
       - Multiplication
       - Transpose

    Data structures:
       - Array
       - Singly Linked List
       - Doubly Linked List

    Note:
    Control-flow and matrix problems naturally use arrays/2D arrays.
    String and array-processing problems below are shown with all
    three representations where practical.
*/


// ============================================================
// BASIC CONTROL FLOW
// ============================================================

bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool isLeapYear(int year) {
    return (year % 400 == 0) ||
           (year % 4 == 0 && year % 100 != 0);
}

void fibonacciArray(int n) {
    int arr[100];

    if (n <= 0) return;

    arr[0] = 0;

    if (n > 1)
        arr[1] = 1;

    for (int i = 2; i < n; i++)
        arr[i] = arr[i - 1] + arr[i - 2];

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}


// ============================================================
// SINGLY LINKED LIST
// ============================================================

class SinglyList {
private:
    struct Node {
        char data;
        Node* next;

        Node(char value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;

public:
    SinglyList() {
        head = nullptr;
    }

    ~SinglyList() {
        clear();
    }

    void insertEnd(char value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr)
            current = current->next;

        current->next = newNode;
    }

    int size() {
        int count = 0;
        Node* current = head;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    char get(int index) {
        Node* current = head;

        for (int i = 0; i < index && current != nullptr; i++)
            current = current->next;

        return current->data;
    }

    void display() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


// ============================================================
// DOUBLY LINKED LIST
// ============================================================

class DoublyList {
private:
    struct Node {
        char data;
        Node* next;
        Node* prev;

        Node(char value) {
            data = value;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyList() {
        clear();
    }

    void insertEnd(char value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    int size() {
        int count = 0;
        Node* current = head;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    char get(int index) {
        Node* current;

        if (index < size() / 2) {
            current = head;

            for (int i = 0; i < index; i++)
                current = current->next;
        }
        else {
            current = tail;

            for (int i = size() - 1; i > index; i--)
                current = current->prev;
        }

        return current->data;
    }

    void displayForward() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void displayBackward() {
        Node* current = tail;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }

        cout << endl;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
    }
};


// ============================================================
// ARRAY STRING FUNCTIONS
// ============================================================

bool palindromeArray(string text) {
    int left = 0;
    int right = text.length() - 1;

    while (left < right) {
        if (text[left] != text[right])
            return false;

        left++;
        right--;
    }

    return true;
}

string reverseArrayString(string text) {
    string result = text;

    int left = 0;
    int right = result.length() - 1;

    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;

        left++;
        right--;
    }

    return result;
}


// ============================================================
// SINGLY LINKED LIST STRING FUNCTIONS
// ============================================================

SinglyList makeSinglyList(string text) {
    SinglyList list;

    for (int i = 0; i < text.length(); i++)
        list.insertEnd(text[i]);

    return list;
}

bool palindromeSingly(SinglyList& list) {
    int left = 0;
    int right = list.size() - 1;

    while (left < right) {
        if (list.get(left) != list.get(right))
            return false;

        left++;
        right--;
    }

    return true;
}

string reverseSingly(SinglyList& list) {
    string result = "";

    for (int i = list.size() - 1; i >= 0; i--)
        result += list.get(i);

    return result;
}


// ============================================================
// DOUBLY LINKED LIST STRING FUNCTIONS
// ============================================================

DoublyList makeDoublyList(string text) {
    DoublyList list;

    for (int i = 0; i < text.length(); i++)
        list.insertEnd(text[i]);

    return list;
}

bool palindromeDoubly(DoublyList& list) {
    int left = 0;
    int right = list.size() - 1;

    while (left < right) {
        if (list.get(left) != list.get(right))
            return false;

        left++;
        right--;
    }

    return true;
}

string reverseDoubly(DoublyList& list) {
    string result = "";

    for (int i = list.size() - 1; i >= 0; i--)
        result += list.get(i);

    return result;
}


// ============================================================
// VOWELS AND CONSONANTS
// ============================================================

bool isVowel(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        ch = ch + 32;

    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u';
}

void countVCArray(string text) {
    int vowels = 0;
    int consonants = 0;

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        if (ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        if (ch >= 'a' && ch <= 'z') {
            if (isVowel(ch))
                vowels++;
            else
                consonants++;
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
}

void countVCSingly(SinglyList& list) {
    int vowels = 0;
    int consonants = 0;

    for (int i = 0; i < list.size(); i++) {
        char ch = list.get(i);

        if (ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        if (ch >= 'a' && ch <= 'z') {
            if (isVowel(ch))
                vowels++;
            else
                consonants++;
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
}

void countVCDoubly(DoublyList& list) {
    int vowels = 0;
    int consonants = 0;

    for (int i = 0; i < list.size(); i++) {
        char ch = list.get(i);

        if (ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        if (ch >= 'a' && ch <= 'z') {
            if (isVowel(ch))
                vowels++;
            else
                consonants++;
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
}


// ============================================================
// INTEGER SINGLY LINKED LIST
// ============================================================

class IntSinglyList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;

public:
    IntSinglyList() {
        head = nullptr;
    }

    ~IntSinglyList() {
        clear();
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr)
            current = current->next;

        current->next = newNode;
    }

    int size() {
        int count = 0;
        Node* current = head;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    int get(int index) {
        Node* current = head;

        for (int i = 0; i < index; i++)
            current = current->next;

        return current->data;
    }

    void set(int index, int value) {
        Node* current = head;

        for (int i = 0; i < index; i++)
            current = current->next;

        current->data = value;
    }

    void display() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


// ============================================================
// INTEGER DOUBLY LINKED LIST
// ============================================================

class IntDoublyList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int value) {
            data = value;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    IntDoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    ~IntDoublyList() {
        clear();
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    int size() {
        int count = 0;
        Node* current = head;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    int get(int index) {
        int n = size();

        if (index < n / 2) {
            Node* current = head;

            for (int i = 0; i < index; i++)
                current = current->next;

            return current->data;
        }
        else {
            Node* current = tail;

            for (int i = n - 1; i > index; i--)
                current = current->prev;

            return current->data;
        }
    }

    void set(int index, int value) {
        int n = size();

        if (index < n / 2) {
            Node* current = head;

            for (int i = 0; i < index; i++)
                current = current->next;

            current->data = value;
        }
        else {
            Node* current = tail;

            for (int i = n - 1; i > index; i--)
                current = current->prev;

            current->data = value;
        }
    }

    void displayForward() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void displayBackward() {
        Node* current = tail;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }

        cout << endl;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
    }
};


// ============================================================
// INTEGER ARRAY OPERATIONS
// ============================================================

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int largestArray(int arr[], int n) {
    int largest = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > largest)
            largest = arr[i];

    return largest;
}

int smallestArray(int arr[], int n) {
    int smallest = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] < smallest)
            smallest = arr[i];

    return smallest;
}

bool secondLargestArray(int arr[], int n, int& answer) {
    if (n < 2)
        return false;

    int largest = arr[0];
    bool found = false;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            answer = largest;
            largest = arr[i];
            found = true;
        }
        else if (arr[i] < largest &&
                 (!found || arr[i] > answer)) {
            answer = arr[i];
            found = true;
        }
    }

    return found;
}

void reverseArray(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

void bubbleSortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


// ============================================================
// INTEGER LINKED-LIST OPERATIONS
// ============================================================

int largestSingly(IntSinglyList& list) {
    int largest = list.get(0);

    for (int i = 1; i < list.size(); i++)
        if (list.get(i) > largest)
            largest = list.get(i);

    return largest;
}

int smallestSingly(IntSinglyList& list) {
    int smallest = list.get(0);

    for (int i = 1; i < list.size(); i++)
        if (list.get(i) < smallest)
            smallest = list.get(i);

    return smallest;
}

void reverseSinglyInt(IntSinglyList& list) {
    int left = 0;
    int right = list.size() - 1;

    while (left < right) {
        int temp = list.get(left);
        list.set(left, list.get(right));
        list.set(right, temp);

        left++;
        right--;
    }
}

void bubbleSortSingly(IntSinglyList& list) {
    int n = list.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list.get(j) > list.get(j + 1)) {
                int temp = list.get(j);
                list.set(j, list.get(j + 1));
                list.set(j + 1, temp);
            }
        }
    }
}


// ============================================================
// DOUBLY LINKED-LIST OPERATIONS
// ============================================================

int largestDoubly(IntDoublyList& list) {
    int largest = list.get(0);

    for (int i = 1; i < list.size(); i++)
        if (list.get(i) > largest)
            largest = list.get(i);

    return largest;
}

int smallestDoubly(IntDoublyList& list) {
    int smallest = list.get(0);

    for (int i = 1; i < list.size(); i++)
        if (list.get(i) < smallest)
            smallest = list.get(i);

    return smallest;
}

void reverseDoublyInt(IntDoublyList& list) {
    int left = 0;
    int right = list.size() - 1;

    while (left < right) {
        int temp = list.get(left);
        list.set(left, list.get(right));
        list.set(right, temp);

        left++;
        right--;
    }
}

void bubbleSortDoubly(IntDoublyList& list) {
    int n = list.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list.get(j) > list.get(j + 1)) {
                int temp = list.get(j);
                list.set(j, list.get(j + 1));
                list.set(j + 1, temp);
            }
        }
    }
}


// ============================================================
// MATRIX OPERATIONS
// ============================================================

void displayMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << "\t";

        cout << endl;
    }
}

void addMatrices(
    int A[][10],
    int B[][10],
    int result[][10],
    int rows,
    int cols
) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
    }
}

void transposeMatrix(
    int A[][10],
    int result[][10],
    int rows,
    int cols
) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            result[j][i] = A[i][j];
    }
}

void multiplyMatrices(
    int A[][10],
    int B[][10],
    int result[][10],
    int rowsA,
    int colsA,
    int colsB
) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;

            for (int k = 0; k < colsA; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
    }
}


// ============================================================
// MAIN
// ============================================================

int main() {

    // --------------------------------------------------------
    // 1. BASIC CONTROL FLOW
    // --------------------------------------------------------

    int number;

    cout << "===== BASIC CONTROL FLOW =====" << endl;

    cout << "Enter number for prime check: ";
    cin >> number;

    if (isPrime(number))
        cout << "Prime" << endl;
    else
        cout << "Not prime" << endl;

    int year;

    cout << "Enter year: ";
    cin >> year;

    if (isLeapYear(year))
        cout << "Leap year" << endl;
    else
        cout << "Not a leap year" << endl;

    int terms;

    cout << "Enter Fibonacci terms: ";
    cin >> terms;

    cout << "Fibonacci: ";
    fibonacciArray(terms);


    // --------------------------------------------------------
    // 2. STRING MANIPULATION
    // --------------------------------------------------------

    cout << "\n===== STRING MANIPULATION =====" << endl;

    string word;

    cout << "Enter a word: ";
    cin >> word;

    // ARRAY
    cout << "\nARRAY VERSION" << endl;
    cout << "Reversed: " << reverseArrayString(word) << endl;

    if (palindromeArray(word))
        cout << "Palindrome" << endl;
    else
        cout << "Not palindrome" << endl;

    countVCArray(word);

    // SINGLY LINKED LIST
    cout << "\nSINGLY LINKED LIST VERSION" << endl;

    SinglyList singly = makeSinglyList(word);

    cout << "List: ";
    singly.display();

    cout << "Reversed: " << reverseSingly(singly) << endl;

    if (palindromeSingly(singly))
        cout << "Palindrome" << endl;
    else
        cout << "Not palindrome" << endl;

    countVCSingly(singly);

    // DOUBLY LINKED LIST
    cout << "\nDOUBLY LINKED LIST VERSION" << endl;

    DoublyList doubly = makeDoublyList(word);

    cout << "Forward: ";
    doubly.displayForward();

    cout << "Backward: ";
    doubly.displayBackward();

    cout << "Reversed: " << reverseDoubly(doubly) << endl;

    if (palindromeDoubly(doubly))
        cout << "Palindrome" << endl;
    else
        cout << "Not palindrome" << endl;

    countVCDoubly(doubly);


    // --------------------------------------------------------
    // 3. ARRAY / LINKED LIST OPERATIONS
    // --------------------------------------------------------

    cout << "\n===== ARRAY OPERATIONS =====" << endl;

    int arr[10];
    int n;

    cout << "Enter array size (1-10): ";
    cin >> n;

    cout << "Enter values:" << endl;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original: ";
    displayArray(arr, n);

    cout << "Largest: " << largestArray(arr, n) << endl;
    cout << "Smallest: " << smallestArray(arr, n) << endl;

    int second;

    if (secondLargestArray(arr, n, second))
        cout << "Second largest: " << second << endl;
    else
        cout << "No distinct second largest." << endl;

    int reversedArr[10];

    for (int i = 0; i < n; i++)
        reversedArr[i] = arr[i];

    reverseArray(reversedArr, n);

    cout << "Reversed: ";
    displayArray(reversedArr, n);

    int sortedArr[10];

    for (int i = 0; i < n; i++)
        sortedArr[i] = arr[i];

    bubbleSortArray(sortedArr, n);

    cout << "Bubble sorted: ";
    displayArray(sortedArr, n);


    // --------------------------------------------------------
    // SINGLY LINKED LIST INTEGER VERSION
    // --------------------------------------------------------

    cout << "\n===== SINGLY LINKED LIST INTEGER =====" << endl;

    IntSinglyList intSingly;

    for (int i = 0; i < n; i++)
        intSingly.insertEnd(arr[i]);

    cout << "Original: ";
    intSingly.display();

    cout << "Largest: " << largestSingly(intSingly) << endl;
    cout << "Smallest: " << smallestSingly(intSingly) << endl;

    reverseSinglyInt(intSingly);

    cout << "Reversed: ";
    intSingly.display();

    bubbleSortSingly(intSingly);

    cout << "Bubble sorted: ";
    intSingly.display();


    // --------------------------------------------------------
    // DOUBLY LINKED LIST INTEGER VERSION
    // --------------------------------------------------------

    cout << "\n===== DOUBLY LINKED LIST INTEGER =====" << endl;

    IntDoublyList intDoubly;

    for (int i = 0; i < n; i++)
        intDoubly.insertEnd(arr[i]);

    cout << "Original forward: ";
    intDoubly.displayForward();

    cout << "Original backward: ";
    intDoubly.displayBackward();

    cout << "Largest: " << largestDoubly(intDoubly) << endl;
    cout << "Smallest: " << smallestDoubly(intDoubly) << endl;

    reverseDoublyInt(intDoubly);

    cout << "Reversed: ";
    intDoubly.displayForward();

    bubbleSortDoubly(intDoubly);

    cout << "Bubble sorted: ";
    intDoubly.displayForward();


    // --------------------------------------------------------
    // 4. MATRIX ADDITION
    // --------------------------------------------------------

    cout << "\n===== MATRIX ADDITION =====" << endl;

    int A[10][10];
    int B[10][10];
    int sum[10][10];

    int rows, cols;

    cout << "Enter matrix rows: ";
    cin >> rows;

    cout << "Enter matrix columns: ";
    cin >> cols;

    cout << "Enter Matrix A:" << endl;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> A[i][j];

    cout << "Enter Matrix B:" << endl;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> B[i][j];

    addMatrices(A, B, sum, rows, cols);

    cout << "A + B:" << endl;
    displayMatrix(sum, rows, cols);


    // --------------------------------------------------------
    // 5. MATRIX TRANSPOSE
    // --------------------------------------------------------

    int transposed[10][10];

    transposeMatrix(A, transposed, rows, cols);

    cout << "\nTranspose of A:" << endl;
    displayMatrix(transposed, cols, rows);


    // --------------------------------------------------------
    // 6. MATRIX MULTIPLICATION
    // --------------------------------------------------------

    cout << "\n===== MATRIX MULTIPLICATION =====" << endl;

    int M1[10][10] = {
        {1, 2},
        {3, 4}
    };

    int M2[10][10] = {
        {5, 6},
        {7, 8}
    };

    int product[10][10];

    multiplyMatrices(M1, M2, product, 2, 2, 2);

    cout << "M1:" << endl;
    displayMatrix(M1, 2, 2);

    cout << "M2:" << endl;
    displayMatrix(M2, 2, 2);

    cout << "M1 x M2:" << endl;
    displayMatrix(product, 2, 2);


    cout << "\n===== END =====" << endl;

    return 0;
}

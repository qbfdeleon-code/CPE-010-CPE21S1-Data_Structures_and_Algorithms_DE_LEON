#include <iostream>
#include <string>

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
        std::cout << arr[i] << " ";

    std::cout << std::endl;
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
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
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
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    void displayBackward() {
        Node* current = tail;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }

        std::cout << std::endl;
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

bool palindromeArray(std::string text) {
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

std::string reverseArrayString(std::string text) {
    std::string result = text;

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

SinglyList makeSinglyList(std::string text) {
    SinglyList list;

    for (size_t i = 0; i < text.length(); i++)
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

std::string reverseSingly(SinglyList& list) {
    std::string result = "";

    for (int i = list.size() - 1; i >= 0; i--)
        result += list.get(i);

    return result;
}


// ============================================================
// DOUBLY LINKED LIST STRING FUNCTIONS
// ============================================================

DoublyList makeDoublyList(std::string text) {
    DoublyList list;

    for (size_t i = 0; i < text.length(); i++)
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

std::string reverseDoubly(DoublyList& list) {
    std::string result = "";

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

void countVCArray(std::string text) {
    int vowels = 0;
    int consonants = 0;

    for (size_t i = 0; i < text.length(); i++) {
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

    std::cout << "Vowels: " << vowels << std::endl;
    std::cout << "Consonants: " << consonants << std::endl;
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

    std::cout << "Vowels: " << vowels << std::endl;
    std::cout << "Consonants: " << consonants << std::endl;
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

    std::cout << "Vowels: " << vowels << std::endl;
    std::cout << "Consonants: " << consonants << std::endl;
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
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
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
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    void displayBackward() {
        Node* current = tail;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }

        std::cout << std::endl;
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
        std::cout << arr[i] << " ";

    std::cout << std::endl;
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
            std::cout << matrix[i][j] << "\t";

        std::cout << std::endl;
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

    std::cout << "===== BASIC CONTROL FLOW =====" << std::endl;

    std::cout << "Enter number for prime check: ";
    std::cin >> number;

    if (isPrime(number))
        std::cout << "Prime" << std::endl;
    else
        std::cout << "Not prime" << std::endl;

    int year;

    std::cout << "Enter year: ";
    std::cin >> year;

    if (isLeapYear(year))
        std::cout << "Leap year" << std::endl;
    else
        std::cout << "Not a leap year" << std::endl;

    int terms;

    std::cout << "Enter Fibonacci terms: ";
    std::cin >> terms;

    std::cout << "Fibonacci: ";
    fibonacciArray(terms);


    // --------------------------------------------------------
    // 2. STRING MANIPULATION
    // --------------------------------------------------------

    std::cout << "\n===== STRING MANIPULATION =====" << std::endl;

    std::string word;

    std::cout << "Enter a word: ";
    std::cin >> word;

    // ARRAY
    std::cout << "\nARRAY VERSION" << std::endl;
    std::cout << "Reversed: " << reverseArrayString(word) << std::endl;

    if (palindromeArray(word))
        std::cout << "Palindrome" << std::endl;
    else
        std::cout << "Not palindrome" << std::endl;

    countVCArray(word);

    // SINGLY LINKED LIST
    std::cout << "\nSINGLY LINKED LIST VERSION" << std::endl;

    SinglyList singly = makeSinglyList(word);

    std::cout << "List: ";
    singly.display();

    std::cout << "Reversed: " << reverseSingly(singly) << std::endl;

    if (palindromeSingly(singly))
        std::cout << "Palindrome" << std::endl;
    else
        std::cout << "Not palindrome" << std::endl;

    countVCSingly(singly);

    // DOUBLY LINKED LIST
    std::cout << "\nDOUBLY LINKED LIST VERSION" << std::endl;

    DoublyList doubly = makeDoublyList(word);

    std::cout << "Forward: ";
    doubly.displayForward();

    std::cout << "Backward: ";
    doubly.displayBackward();

    std::cout << "Reversed: " << reverseDoubly(doubly) << std::endl;

    if (palindromeDoubly(doubly))
        std::cout << "Palindrome" << std::endl;
    else
        std::cout << "Not palindrome" << std::endl;

    countVCDoubly(doubly);


    // --------------------------------------------------------
    // 3. ARRAY / LINKED LIST OPERATIONS
    // --------------------------------------------------------

    std::cout << "\n===== ARRAY OPERATIONS =====" << std::endl;

    int arr[10];
    int n;

    std::cout << "Enter array size (1-10): ";
    std::cin >> n;

    std::cout << "Enter values:" << std::endl;

    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::cout << "Original: ";
    displayArray(arr, n);

    std::cout << "Largest: " << largestArray(arr, n) << std::endl;
    std::cout << "Smallest: " << smallestArray(arr, n) << std::endl;

    int second;

    if (secondLargestArray(arr, n, second))
        std::cout << "Second largest: " << second << std::endl;
    else
        std::cout << "No distinct second largest." << std::endl;

    int reversedArr[10];

    for (int i = 0; i < n; i++)
        reversedArr[i] = arr[i];

    reverseArray(reversedArr, n);

    std::cout << "Reversed: ";
    displayArray(reversedArr, n);

    int sortedArr[10];

    for (int i = 0; i < n; i++)
        sortedArr[i] = arr[i];

    bubbleSortArray(sortedArr, n);

    std::cout << "Bubble sorted: ";
    displayArray(sortedArr, n);


    // --------------------------------------------------------
    // SINGLY LINKED LIST INTEGER VERSION
    // --------------------------------------------------------

    std::cout << "\n===== SINGLY LINKED LIST INTEGER =====" << std::endl;

    IntSinglyList intSingly;

    for (int i = 0; i < n; i++)
        intSingly.insertEnd(arr[i]);

    std::cout << "Original: ";
    intSingly.display();

    std::cout << "Largest: " << largestSingly(intSingly) << std::endl;
    std::cout << "Smallest: " << smallestSingly(intSingly) << std::endl;

    reverseSinglyInt(intSingly);

    std::cout << "Reversed: ";
    intSingly.display();

    bubbleSortSingly(intSingly);

    std::cout << "Bubble sorted: ";
    intSingly.display();


    // --------------------------------------------------------
    // DOUBLY LINKED LIST INTEGER VERSION
    // --------------------------------------------------------

    std::cout << "\n===== DOUBLY LINKED LIST INTEGER =====" << std::endl;

    IntDoublyList intDoubly;

    for (int i = 0; i < n; i++)
        intDoubly.insertEnd(arr[i]);

    std::cout << "Original forward: ";
    intDoubly.displayForward();

    std::cout << "Original backward: ";
    intDoubly.displayBackward();

    std::cout << "Largest: " << largestDoubly(intDoubly) << std::endl;
    std::cout << "Smallest: " << smallestDoubly(intDoubly) << std::endl;

    reverseDoublyInt(intDoubly);

    std::cout << "Reversed: ";
    intDoubly.displayForward();

    bubbleSortDoubly(intDoubly);

    std::cout << "Bubble sorted: ";
    intDoubly.displayForward();


    // --------------------------------------------------------
    // 4. MATRIX ADDITION
    // --------------------------------------------------------

    std::cout << "\n===== MATRIX ADDITION =====" << std::endl;

    int A[10][10];
    int B[10][10];
    int sum[10][10];

    int rows, cols;

    std::cout << "Enter matrix rows: ";
    std::cin >> rows;

    std::cout << "Enter matrix columns: ";
    std::cin >> cols;

    std::cout << "Enter Matrix A:" << std::endl;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            std::cin >> A[i][j];

    std::cout << "Enter Matrix B:" << std::endl;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            std::cin >> B[i][j];

    addMatrices(A, B, sum, rows, cols);

    std::cout << "A + B:" << std::endl;
    displayMatrix(sum, rows, cols);


    // --------------------------------------------------------
    // 5. MATRIX TRANSPOSE
    // --------------------------------------------------------

    int transposed[10][10];

    transposeMatrix(A, transposed, rows, cols);

    std::cout << "\nTranspose of A:" << std::endl;
    displayMatrix(transposed, cols, rows);


    // --------------------------------------------------------
    // 6. MATRIX MULTIPLICATION
    // --------------------------------------------------------

    std::cout << "\n===== MATRIX MULTIPLICATION =====" << std::endl;

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

    std::cout << "M1:" << std::endl;
    displayMatrix(M1, 2, 2);

    std::cout << "M2:" << std::endl;
    displayMatrix(M2, 2, 2);

    std::cout << "M1 x M2:" << std::endl;
    displayMatrix(product, 2, 2);


    std::cout << "\n===== END =====" << std::endl;

    return 0;
}
#include <iostream>
using namespace std;

//dz1 - 1
/* 
int main() {

    int M, N;
    cout << "Enter size of A: ";
    cin >> M;
    cout << "Enter size of B: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Enter elements of A: ";
    for (int i = 0; i < M; i++) cin >> A[i];
    cout << "Enter elements of B: ";
    for (int i = 0; i < N; i++) cin >> B[i];

    int* C = new int[M];
    int k = 0;

    for (int i = 0; i < M; i++) {
        bool found = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            bool exists = false;
            for (int x = 0; x < k; x++) {
                if (C[x] == A[i]) {
                    exists = true;
                    break;
                }
            }
            if (!exists) C[k++] = A[i];
        }
    }

    cout << "Result Array C: ";
    for (int i = 0; i < k; i++) cout << C[i] << " ";

    delete[] A;
    delete[] B;
    delete[] C;
}
*/

//dz1 - 2 
/* 
int main()
{
    int m, n;
    cout << "Enter size of A: ";
    cin >> m;
    cout << "Enter size of B: ";
    cin >> n;

    int* A = new int[m];
    int* B = new int[n];
    cout << "Enter elements of A:\n";
    for (int i = 0; i < m; i++) cin >> A[i];
    cout << "Enter elements of B:\n";
    for (int i = 0; i < n; i++) cin >> B[i];

    int* C = new int[m + n];
    int k = 0;

    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            bool unique = true;
            for (int x = 0; x < k; x++) {
                if (C[x] == A[i]) {
                    unique = false;
                    break;
                }
            }
            if (unique) C[k++] = A[i];
        }
    }

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            bool unique = true;
            for (int x = 0; x < k; x++) {
                if (C[x] == B[i]) {
                    unique = false;
                    break;
                }
            }
            if (unique) C[k++] = B[i];
        }
    }

    cout << "Unique elements not common to A and B:\n";
    for (int i = 0; i < k; i++) cout << C[i] << " ";
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;
}
*/

//dz2 - 1
/* 
int* allocateArray(int size) {
    return new int[size];
}

void initializeArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteArray(int* arr) {
    delete[] arr;
}

int* addElement(int* arr, int& size, int element) {
    int* newArr = allocateArray(size + 1);
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = element;
    size++;
    deleteArray(arr);
    return newArr;
}

int* insertElement(int* arr, int& size, int index, int element) {
    int* newArr = allocateArray(size + 1);
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    newArr[index] = element;
    for (int i = index; i < size; i++) {
        newArr[i + 1] = arr[i];
    }
    size++;
    deleteArray(arr);
    return newArr;
}

int* deleteElement(int* arr, int& size, int index) {
    int* newArr = allocateArray(size - 1);
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }
    size--;
    deleteArray(arr);
    return newArr;
}

int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int* arr = allocateArray(size);
    initializeArray(arr, size);

    cout << "Original array: ";
    printArray(arr, size);

    int newElement = 10;
    arr = addElement(arr, size, newElement);
    cout << "Array after adding element " << newElement << ": ";
    printArray(arr, size);

    int insertIndex = 2;
    int insertElementVal = 20;
    arr = insertElement(arr, size, insertIndex, insertElementVal);
    cout << "Array after inserting element " << insertElementVal << " at index " << insertIndex << ": ";
    printArray(arr, size);

    int deleteIndex = 1;
    arr = deleteElement(arr, size, deleteIndex);
    cout << "Array after deleting element at index " << deleteIndex << ": ";
    printArray(arr, size);

    deleteArray(arr);
}
*/

//dz2 - 2
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int* removePrimes(int* arr, int& size) {
    int newSize = 0;

    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newSize++;
        }
    }

    int* newArr = new int[newSize];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArr[j++] = arr[i];
        }
    }

    size = newSize;
    delete[] arr; 
    return newArr; 
}

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter elements of array:\n";
    for (int i = 0; i < size; i++) cin >> arr[i];

    arr = removePrimes(arr, size);

    cout << "Array after removing primes:\n";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr; 
}
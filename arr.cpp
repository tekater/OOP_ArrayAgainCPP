#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Array {
    int* arr;
    int size;
    int realsize;
public:
    Array(int size = 5) {
        arr = new int[5];
        for (int i = 0; i < 5; i++) {
            arr[i] = -1;
        }
        realsize = 0;
    }

    int GetSize() {
        return size;
    }

    void SetSize(int usize) {
        usize--;
        int* uarr = new int[usize];
        //uarr = arr;
        if (size > usize) {
            for (int i = 0; i < usize; i++) {
                uarr[i] = arr[i];
            }
        }
        else {
            for (int i = 0; i < size; i++) {
                uarr[i] = arr[i];
            }
        }

        if (size < usize) {
            for (int i = 0; i < usize; i++) {
                if (uarr[i] < 0) {
                    uarr[i] = 0;
                }
            }
        }
        delete[]arr;

        arr = new int[usize];
        for (int i = 0; i < usize; i++) {
            arr[i] = uarr[i];
        }

        size = usize;
        /*for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }*/
    }

    int GetUpperBound() {
        if (!isEmpty) {
            return realsize - 1;
        }
        else {
            return 0;
        }
    }

    void FreeExtra() {
        if (!isEmpty) {
            SetSize(realsize + 1);
        }
    }

    void RemoveAll() {
        realsize = 0;
    }

    int GetAt(int ind) {
        return arr[ind];
    }

    void SetAt(int ind, int x) {
        if (ind < size) {
            if (ind > realsize) {
                realsize++;
            }
            arr[ind] = x;
        }
    }

    void Add(int x) {
        if (realsize == size) {
            SetSize(size + 2);
            arr[realsize] = x;
            realsize++;
        }
        else {
            arr[realsize] = x;
            realsize++;
        }
    }

    bool isEmpty() {
        if (realsize == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    int operator[](int n)const {
        if (n < size) {
            return arr[n];
        }
        else {
            return -1;
        }
        
    }

    int& operator[](int n) {
        int a = -1;
        if (n < size) {
            return arr[n];
        }
        else {
            return a;
        }
    }

    Array Append(const Array& ar1) {
        Array ar2;
        ar2.SetSize(size + ar1.size);
        for (int i = 0; i < size; i++) {
            ar2.Add(arr[i]);
        }
        for (int i = 0; i < ar1.size; i++) {
            ar2.Add(ar1.arr[i]);
        }
        return ar2;
    }

    Array& operator=(const Array& ar1) {
        SetSize(size + ar1.size);
        for (int i = 0; i < size; i++) {
            Add(arr[i]);
        }
        for (int i = 0; i < ar1.size; i++) {
            Add(ar1.arr[i]);
        }
        return *this;
    }

    int* GetData() {
        return arr;
    }

    void Insert(int ind, int x) {
        SetSize(size + 2);
        for (int i = ind; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        SetAt(ind,x);
    }

    void RemoveAt(int ind) {
        for (int i = ind; i < size; i++) {
            arr[i] = 0;
        }
        if (realsize > ind) {
            realsize = ind;
        }
    }

    ~Array() {
        delete[] arr;
    }
};



int main() {

    setlocale(0, "");
    srand(time(NULL));

    Array ar;

    ar.SetSize(4);
}

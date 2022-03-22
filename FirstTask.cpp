using namespace std;
#include <iostream>

class DinamicArrayIntNumber {
public:
    int* arr;
    int size;
    DinamicArrayIntNumber() {
        arr = new int[10];
    }
    DinamicArrayIntNumber(int size) {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
    DinamicArrayIntNumber(int size, int n) {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = n;
        }
    }
    DinamicArrayIntNumber(const DinamicArrayIntNumber& dinamic) {
        int i;
        size = dinamic.size;
        arr = new int[size];
        for (int i = 0; i < dinamic.size; i++) {
            arr[i] = dinamic.arr[i];
        }
    }
    DinamicArrayIntNumber(DinamicArrayIntNumber&& dinamic) 
        : arr(dinamic.arr), size(dinamic.size)
    {
        dinamic.arr = nullptr;
        
    }
    ~DinamicArrayIntNumber()
    {
        delete[] arr;
    }

    int& operator[](const int index);
    int getSizeOfArray() {
        return size;
    }
    int getElementOfArray(int i) {
        return arr[i];
    }
    void resize(int newSize) {
        int* newArray = new int[newSize];
        if (size >= newSize) {
            for (int i = 0; i < newSize; i++) {
                newArray[i] = arr[i];
            }
            delete[] arr;
            size = newSize;
            this->arr = newArray;
        }
        if (size < newSize) {
            for (int i = 0; i < size; i++) {
                newArray[i] = arr[i];
            }
            for (int k = 0; k < newSize - size; k++) {
                newArray[k+size] = 0;
            }
            delete[] arr;
            size = newSize;
            this->arr = newArray;
        }
    }
    DinamicArrayIntNumber& operator=(const  DinamicArrayIntNumber& diname) {
        delete[] arr;
        size = diname.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = diname.arr[i];
        }
        
        return *this;
    }
    DinamicArrayIntNumber& operator=(DinamicArrayIntNumber&& dinamic ) {
        delete[] arr;
        size = dinamic.size;
        arr = dinamic.arr;
        dinamic.arr = nullptr;
        return *this;
    }
    friend bool operator == (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    friend bool operator != (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);

    friend bool operator> (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    friend bool operator<= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);

    friend bool operator< (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    friend bool operator>= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);

    friend DinamicArrayIntNumber operator+(DinamicArrayIntNumber& d1, DinamicArrayIntNumber& d2);

    friend ostream& operator<<(ostream& out, const DinamicArrayIntNumber& d1);
    friend istream& operator>>(istream& in, DinamicArrayIntNumber& d1);
};


bool operator== (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2) {
    if (d1.size == d2.size) {
        for (int i = 0; i < d1.size; i++) {
            if (d1.arr[i] != d2.arr[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator != (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    return !(d1 == d2);
}
int& DinamicArrayIntNumber::operator[](const int index) {
    return arr[index];
}

bool operator> (const const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    if (d1.size > d2.size) {
        return true;
    }
    if (d2.size > d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] <= d2.arr[i]) {
            return false;
        }
    }
    return true;
}

bool operator>= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    if (d1.size > d2.size) {
        return true;
    }
    if (d2.size > d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] < d2.arr[i]) {
            return false;
        }
    }
    return true;
}

bool operator< (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    if (d1.size < d2.size) {
        return true;
    }
    if (d2.size < d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] >= d2.arr[i]) {
            return false;
        }
    }
    return true;
}

bool operator<= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    if (d1.size < d2.size) {
        return true;
    }
    if (d2.size < d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] > d2.arr[i]) {
            return false;
        }
    }
    return true;
}

DinamicArrayIntNumber operator+(DinamicArrayIntNumber& d1, DinamicArrayIntNumber& d2) {
    
    DinamicArrayIntNumber result = DinamicArrayIntNumber(d1.size + d2.size);
    for (int i = 0; i < d1.size; i++) {
        result.arr[i] = d1[i];
    }
    for (int i = d1.size; i < (d1.size + d2.size); i++) {
        result.arr[i] = d2[i];
    }
    return result;
}

ostream& operator<< (ostream& out, const DinamicArrayIntNumber& dinamic)
{ 
    out << "DinamicArrayIntNumber(";
    for (int i = 0; i < dinamic.size; i++) {
        out << dinamic.arr[i] << ", ";
    }
    out << ")";

    return out;
}

istream& operator>> (istream& in, DinamicArrayIntNumber& dinamic)
{
    
    for (int i = 0; i < dinamic.size; i++) {
        in >> dinamic.arr[i];
    }
    return in;
}

int main()
{
    
}

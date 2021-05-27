// Uygur Kiran - 2021/05/18

#include <iostream>
#include <set>
using namespace std;

template <class T>
class Array {
private:
    T *data;
    int size;
    int count;

    bool typeIsNum() {
        short s;
        int i;
        long l;
        float f;
        double d;

        return (typeid(T) == typeid(s) ||
                typeid(T) == typeid(i) ||
                typeid(T) == typeid(l) ||
                typeid(T) == typeid(f) ||
                typeid(T) == typeid(d));
    }

    void swapElements(T *x, T *y) {
        T temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

public:
    Array() {
        size = 100;
        count = 0;
        data = new T[size];
    }
    Array(int ofSize) {
        size = ofSize;
        count = 0;
        data = new T[size];
    }
    ~Array() {
        delete []data;
    }

    void print();
    void info();
    void append(T item);
    void insert(T item, int atIndex);
    void insertAtSortedPos(T item);
    T remove(int fromIndex);
    T get(int itemAtIndex);
    void set(T newValue, int toIndex);
    T max();
    T min();
    T sum();
    float avg();
    bool isSorted();
    int findFirstIndex(T of);
    int linearSearch(T withKey);
    int binarySearch(T withKey);
    void reverse();
    Array<T>* merged(Array<T> with);
    Array<T>* unioned(Array<T> with);
    Array<T>* unionSorted(Array<T> with);
    Array<T>* commonElements(Array<T> with);
    Array<T>* commonElementsSorted(Array<T> with);
    Array<T>* differentElements(Array<T> comparedTo);

}; //: ARRAY

template <class T>
void Array<T>::print() {
    cout << "[";
    for (int i = 0; i < count; i++) {
        cout << data[i];
        if (i != count-1) { cout << ", "; }
    }
    cout << "]" << endl;
}

template <class T>
void Array<T>::info() {
    cout << "\n" << "ARRAY INFO *********";
    cout << "\n\t" << "size: " << size;
    cout << "\n\t" << "count: " << count;
    cout << "\n\t" << "available space: " << size-count;

    if (typeIsNum() == false) { return; }
    cout << "\n\t" << "min value: " << min();
    cout << "\n\t" << "max value: " << max();
    cout << "\n\t" << "sum: " << sum();
    cout << "\n\t" << "average: " << avg();
    cout << "\n\t" << "sorted: " << (isSorted() == 1 ? "true" : "false");
    cout << "\n" << "*********************" << endl;
}

template <class T>
void Array<T>::append(T item) {
    if (count >= size) {
        cout << "Error: new element exceeds size of the array." << endl;
        return;
    }
    data[count++] = item;
}

template <class T>
void Array<T>::insert(T item, int atIndex) {
    if (atIndex < 0) {
        cout << "Error: index cannot be a negative integer." << endl;
        return;
    }
    if (atIndex > count) {
        cout << "Error: index out of bounds. use .append() instead." << endl;
        return;
    }
    // insert
    for (int i = count; i > atIndex; i--) {
        data[i] = data[i-1];
    }
    data[atIndex] = item;
    count++;
}

template <class T>
void Array<T>::insertAtSortedPos(T item) {
    if (typeIsNum() == false) {
        cout << "Error: array must consist of short, int, long, float or double." << endl;
        return;
    }
    if (count >= size) {
        cout << "Error: new element exceeds size of the array." << endl;
        return;
    }

    int i = count-1;
    while (i >= 0 && data[i] > item) {
        data[i+1] = data[i];
        i--;
    }
    data[i+1] = item;
    count++;
}

template <class T>
T Array<T>::remove(int fromIndex) {
    if (fromIndex < 0 || fromIndex >= count) {
        cout << "Error: index is not valid." << endl;
        return -1;
    }
    T itemToDelete = data[fromIndex];

    for (int i = fromIndex; i < count-1; i++) {
        data[i] = data[i+1];
    }
    count--;

    return itemToDelete;
}

template <class T>
T Array<T>::get(int itemAtIndex) {
    if (itemAtIndex < 0 || itemAtIndex >= count) {
        cout << "Error: index is not valid." << endl;
        return -1;
    }
    return data[itemAtIndex];
}

template <class T>
void Array<T>::set(T newValue, int toIndex) {
    if (toIndex < 0 || toIndex >= count) {
        cout << "Error: index is not valid." << endl;
        return;
    }
    data[toIndex] = newValue;
}

template <class T>
T Array<T>::max() {
    if (typeIsNum() == false) {
        cout << "Error: array must consist of short, int, long, float or double." << endl;
        return -1;
    }
    T max = data[0];
    for (int i = 1; i < count; i++) {
        if (data[i] > max) { max = data[i]; }
    }
    return max;
}

template <class T>
T Array<T>::min() {
    if (typeIsNum() == false) {
        cout << "Error: array must consist of short, int, long, float or double." << endl;
        return -1;
    }
    T min = data[0];
    for (int i = 1; i < count; i++) {
        if (data[i] < min) { min = data[i]; }
    }
    return min;
}

template <class T>
T Array<T>::sum() {
    if (typeIsNum() == false) {
        cout << "Error: array must consist of short, int, long, float or double." << endl;
        return -1;
    }
    T sum = 0;
    for (int i = 0; i < count; i++) {
        sum += data[i];
    }
    return sum;
}

template <class T>
float Array<T>::avg() {
    if (typeIsNum() == false) {
        cout << "Error: array must consist of short, int, long, float or double." << endl;
        return -1;
    }
    return (float) sum()/count;
}

template <class T>
bool Array<T>::isSorted() {
    for (int i = 0; i < count-1; i++) {
        if (data[i] > data[i+1]) return false;
    }
    return true;
}

template <class T>
int Array<T>::findFirstIndex(T of) {
    for (int i = 0; i < count; i++) {
        if (of == data[i]) {
            return i;
        }
    }
    cout << "Error: item cannot found." << endl;
    return -1;
}

template <class T>
int Array<T>::linearSearch(T withKey) {
    for (int i = 0; i < count; i++) {
        if (withKey == data[i]) {
            swapElements(&data[i], &data[0]);
            return i;
        }
    }
    cout << "Error: item cannot found." << endl;
    return -1;
}

template <class T>
int Array<T>::binarySearch(T withKey) {
    if (typeIsNum() == false) {
        cout << "Error: array must consist of short, int, long, float or double." << endl;
        return -1;
    }
    if (isSorted() == false) {
        cout << "Error: binary search can only be used with sorted arrays." << endl;
        return -1;
    }

    // indexes
    int l, mid, h;
    l = 0;
    h = count-1;

    while (l <= h) {
        mid = (l+h)/2;
        if (withKey == data[mid]) {
            return mid;
        } else if (withKey < data[mid]) {
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    // if not found
    cout << "Error: item cannot found." << endl;
    return -1;
}

template <class T>
void Array<T>::reverse() {
    int idx1, idx2;
    for (idx1 = 0, idx2 = count-1; idx1 < idx2; idx1++, idx2--) {
        swapElements(&data[idx1], &data[idx2]);
    }
}

template <class T>
Array<T>* Array<T>::merged(Array<T> with) {
    if (typeIsNum() == false) {
        cout << "Error: array must consist of short, int, long, float or double." << endl;
        return new Array<T>(0);
    }
    int a,b,c;
    a=b=c=0;
    Array<T> *newArr = new Array<T>(count + with.count);

    // compare(sort if can) & copy
    while(a < count && b < with.count) {
        if(data[a] < with.data[b]) {
            newArr->data[c++] = data[a++];
        } else {
            newArr -> data[c++] = with.data[b++];
        }
    }
    // handle rest
    for(;a < count; a++) {
        newArr -> data[c++] = data[a];
    }
    for(;b < with.count; b++) {
        newArr -> data[c++] = with.data[b];
    }

    newArr -> count = count + with.count;
    return newArr;
}


template <class T>
Array<T>* Array<T>::unioned(Array<T> with) {
    if (typeIsNum() == false) {
        cout << "Error: array must consist of short, int, long, float or double." << endl;
        return new Array<T>(0);
    }

    ::set<T> temp;
    for (int i = 0; i < count; i++) {
        temp.insert(data[i]);
    }

    for (int i = 0; i < with.count; i++) {
        temp.insert(with.data[i]);
    }

    Array<T> *newArr = new Array<T>(temp.size());
    for (auto item = temp.begin(); item != temp.end(); item++) {
        newArr -> append(*item);
    }
    return newArr;
}

template <class T>
Array<T>* Array<T>::unionSorted(Array<T> with) {
    if (typeIsNum() == false) {
        cout << "Error: array must consist of short, int, long, float or double." << endl;
        return new Array<T>(0);
    }

    if (isSorted() == false) {
        cout << "Error: .unionSorted() can only be used with sorted arrays."
                "\n use .unioned() instead." << endl;
        return new Array<T>(0);
    }

    int a,b,c;
    a=b=c=0;
    Array<T> *newArr = new Array<T>(count + with.count);

    // compare & copy
    while(a < count && b < with.count) {
        if(data[a] < with.data[b]) {
            newArr -> data[c++] = data[a++];
        } else if (data[a] > with.data[b]){
            newArr -> data[c++] = with.data[b++];
        } else {
            // [a] == [b] -> take one of them.
            newArr -> data[c++] = data[a++];
            b++;
        }
    }
    // handle rest
    for(;a < count; a++) {
        newArr -> data[c++] = data[a];
    }
    for(;b < with.count; b++) {
        newArr -> data[c++] = with.data[b];
    }

    newArr -> count = c;
    return newArr;
}

template <class T>
Array<T>* Array<T>::commonElements(Array<T> with) {
    if (typeIsNum() == false) {
        cout << "Error: array must consist of short, int, long, float or double." << endl;
        return new Array<T>(0);
    }
    Array<T> *newArr = new Array<T>(count + with.count);

    for(int a = 0; a < count; a++) {
        for (int b = 0; b < with.count; b++) {
            if (data[a] == with.data[b]) {
                newArr -> append(data[a]);
                break;
            }
        }
    } //: LOOP
    return newArr;
}

template <class T>
Array<T>* Array<T>::commonElementsSorted(Array<T> with) {
    if (typeIsNum() == false) {
        cout << "Error: array must consist of short, int, long, float or double." << endl;
        return new Array<T>(0);
    }

    if (isSorted() == false) {
        cout << "Error: .commonElementsSorted() can only be used with sorted arrays."
                "\n use .commonElements() instead." << endl;
        return new Array<T>(0);
    }

    int a,b,c;
    a=b=c=0;
    Array<T> *newArr = new Array<T>(count + with.count);

    while(a < count && b < with.count) {
        if(data[a] < with.data[b]) {
            a++;
        } else if (data[a] > with.data[b]){
            b++;
        } else {
            // [a] == [b]
            newArr -> data[c++] = data[a++];
            b++;
        }
    }
    newArr -> count = c;
    return newArr;
}

template <class T>
Array<T>* Array<T>::differentElements(Array<T> comparedTo) {
    if (typeIsNum() == false) {
        cout << "Error: array must consist of short, int, long, float or double." << endl;
        return new Array<T>(0);
    }
    if (isSorted() == false) {
        cout << "Error: .differentElements() can only be used with sorted arrays." << endl;
        return new Array<T>(0);
    }

    int a,b,c;
    a=b=c=0;
    Array<T> *newArr = new Array<T>(count + comparedTo.count);

    while(a < count && b < comparedTo.count) {
        if(data[a] < comparedTo.data[b]) {
            newArr -> data[c++] = data[a++];
        } else if (data[a] > comparedTo.data[b]){
            b++;
        } else {
            // [a] == [b] -> take one of them.
            a++;
            b++;
        }
    }

    for(;a < count; a++) {
        newArr -> data[c++] = data[a];
    }

    newArr -> count = c;
    return newArr;
}



// test ///////////////////////////
int main() {
    Array<int> *b, *d, *c;
    b = new Array<int>(50);
    c = new Array<int>(200);

    b -> append(2);
    b -> append(6);
    b -> append(30);
    b -> append(20);
    b -> append(25);
    b -> append(8);
    b -> print();
    
    c -> append(30);
    c -> append(6);
    c -> append(7);
    c -> append(15);
    c -> append(20);
    c -> print();

    d = b -> unioned(*c);
    d -> print();
    d -> info();

    return 0;
}

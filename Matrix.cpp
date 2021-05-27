// Uygur Kiran 2021/05/20
#include <iostream>
using namespace std;

//////////////////////////
// DIAGONAL MATRIX
//////////////////////////
class DiagonalMat {
private:
    int *data;
    int dimension;
public:
    DiagonalMat() {
        dimension = 2;
        data = new int[2];
    }
    DiagonalMat(int dimension) {
        this -> dimension = dimension;
        data = new int[dimension];
    }
    ~DiagonalMat() {
        delete []data;
    }

    void create();
    void set(int x, int y, int value);
    int get(int x, int y);
    void print();
    int getDimension() { return dimension; }

};

void DiagonalMat::create() {
    int input;
    // only non-zero elements will be stored
    for (int i = 1; i <= dimension; i++) {
        for (int j = 1; j <= dimension; j++) {
            cin >> input;
            if (i == j) data[i - 1] = input;
        }
    }
}

void DiagonalMat::set(int x, int y, int value) {
    if (x == y) {
        data[x-1] = value;
    }
}

int DiagonalMat::get(int x, int y) {
    if (x == y) {
        return data[x-1];
    }
    return 0;
}

void DiagonalMat::print() {
    cout << endl;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (i==j) {
                cout << data[i] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


//////////////////////////
// LOWER TRIANGULAR MATRIX
//////////////////////////
class LowTriAngMat {
private:
    int *data;
    int dimension;
public:
    LowTriAngMat() {
        dimension = 2;
        data = new int[dimension*(dimension+1)/2];
    }
    LowTriAngMat(int dimension) {
        this -> dimension = dimension;
        data = new int[dimension*(dimension+1)/2];
    }
    ~LowTriAngMat() {
        delete []data;
    }

    void create();
    void set(int x, int y, int value);
    int get(int x, int y);
    void print();
    int getDimension() { return dimension; }

};

void LowTriAngMat::create() {
    int input;
    for (int i = 1; i <= dimension; i++) {
        for (int j = 1; j <= dimension; j++) {
            cin >> input;
            if ( i >= j) data[i*(i-1)/2+j-1] = input;
        }
    }
}

void LowTriAngMat::set(int x, int y, int value) {
    if (x >= y) {
        data[x*(x-1)/2+y-1] = value;
    }
}

int LowTriAngMat::get(int x, int y) {
    if (x >= y) {
        return data[x*(x-1)/2+y-1];
    }
    return 0;
}

void LowTriAngMat::print() {
    cout << endl;
    for (int i=1; i <= dimension; i++) {
        for (int j=1; j <= dimension; j++) {
            if (i>=j) {
                cout << data[i*(i-1)/2+j-1] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


// run ///////////////////
int main() {
    int choice = 3;
    int dimSize = 0;

    cout << endl << "Choose MATRIX type: " << endl;
    cout << "1. Diagonal" << endl;
    cout << "2. Lower Triangular" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << endl << "Enter dimension size: ";
        cin >> dimSize;

        DiagonalMat diagMat(dimSize);
        cout << endl << "Enter elements: " << endl;
        diagMat.create();

        int c2 = 0;
        do {
            cout << endl << "Actions" << endl;
            cout << "1. Print" << endl;
            cout << "2. Exit" << endl;
            cin >> c2;

            switch (c2) {
                case 1:
                    diagMat.print();
                    break;

            }
        } while (c2 < 2);

    } else if (choice == 2) {

            cout << endl << "Enter dimension size: ";
            cin >> dimSize;

            LowTriAngMat lwMat(dimSize);
            cout << endl << "Enter elements: " << endl;
            lwMat.create();

            int c2=0;
            do {
                cout << endl << "Actions" << endl;
                cout << "1. Print" << endl;
                cout << "2. Exit" << endl;
                cin >> c2;

                switch (c2) {
                    case 1:
                        lwMat.print();
                    break;
                }
            } while (c2 < 2);

    } //: IF

    return 0;
}
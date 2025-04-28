#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:

    Array() : data(nullptr), size(0) {}

    Array(int size) {
        this->size = size;
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = 0;
    }

    Array(const Array& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    ~Array() {
        delete[] data;
    }

    void fill() {
        for (int i = 0; i < size; ++i) {
            cout << "element [" << i << "]: ";
            cin >> data[i];
        }
    }

    void print() const {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    void resize(int newSize) {
        int* newData = new int[newSize];
        int minSize = (newSize < size) ? newSize : size;

        for (int i = 0; i < minSize; ++i)
            newData[i] = data[i];

        for (int i = minSize; i < newSize; ++i)
            newData[i] = 0;

        delete[] data;
        data = newData;
        size = newSize;
    }

    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    int getMin() const {
        if (size == 0) return 0;
        int min = data[0];
        for (int i = 1; i < size; ++i)
            if (data[i] < min)
                min = data[i];
        return min;
    }

    int getMax() const {
        if (size == 0) return 0;
        int max = data[0];
        for (int i = 1; i < size; ++i)
            if (data[i] > max)
                max = data[i];
        return max;
    }

    Array* self() {
        return this;
    }
};

int main() {
    Array arr(5);
    arr.fill();

    cout << "\nMassive: ";
    arr.print();

    cout << "Minimum: " << arr.getMin() << endl;
    cout << "Maximum: " << arr.getMax() << endl;

    cout << "\nSorting...\n";
    arr.sort();
    arr.print();

    cout << "\nchanging size to 7:\n";
    arr.resize(7);
    arr.print();

    cout << "\nCopying Massive:\n";
    Array copy = arr;
    copy.print();

    return 0;
}


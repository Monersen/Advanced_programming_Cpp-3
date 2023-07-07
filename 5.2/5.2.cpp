﻿#include <iostream>
using namespace std;

template <typename T>
class table {

    T** ptr;
    int row, col;

public:
    table(table const&) = delete;
    table& operator=(table const&) = delete;
    table() = default;

    table(int row, int col) : row(row), col(col) {

        ptr = new T * [row];
        for (int i = 0; i < row; ++i)
            ptr[i] = new T[col];
    }

    T* operator[](int pos) const {
        return ptr[pos];
    }

    T* operator[](int pos) {
        return ptr[pos];
    }

    int Size() const {
        return row * col;
    }

    ~table()
    {
        for (int i = 0; i < row; ++i)
            delete[]ptr[i];
        delete[]ptr;
    }
};


int main(int argc, char const* argv[])
{
    auto test1 = table<char>(2, 3);
    test1[0][1] = 'w';
    cout << "Regular result: " << test1[0][1] << endl;
    cout << "Table size: " << test1.Size() << endl;

    cout << endl;

    const auto test2 = table<int>(2, 3);
    test2[0][1] = 4;
    cout << "Const result: " << test2[0][1] << endl;
    cout << "Table size: " << test2.Size() << endl;

    return 0;
}
#include <iostream>
#include <vector>

template <typename T>
class Array {
private:
    T* data;
    size_t size;

public:
    Array(size_t n)
            : size(n)
    {
        data = new T[n];
    }

    Array( const Array & obj )
            : size(obj.size)
            , data(obj.size ? new T[obj.size] : nullptr)
    {
        if (data) {
            std::copy(obj.data, obj.data+size, data);
        }
    }

    Array& operator= (const Array & obj)
    {
        if(&obj == this)
            return *this;


        if (data != nullptr) {
            delete [] data;
            data = nullptr;
            size = 0;
        }

        data = obj.size ? new T[obj.size] : nullptr;
        size = obj.size;

        if (data) {
            std::copy(obj.data, obj.data+size, data);

        }

        return *this;
    }

    T& operator[](size_t i) {
        return data[i];
    }

    const T& operator[](size_t i) const {
        return data[i];
    }

    const size_t GetSize() const {
        return size;
    }

    ~Array() {
        if (data != nullptr) {
            delete [] data;
            data = nullptr;
            size = 0;
        }
    }
};

template <typename T>
Array<T> GetArray(size_t n, T x) {
    Array<T> A(n);
    for (size_t i = 0; i != n; ++i) {
        A[i] = x;
    }
    return A;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& A) {
    for (size_t i = 0; i != A.GetSize(); ++i) {
        out << A[i] << " ";
    }
    out << "\n";
    return out;
}

int main() {
    size_t n;
    std::cin >> n;
    Array<int> A(n);
    A = GetArray<int>(n, 0);
    // print the array
    std::cout << A << "\n";

    std::vector<Array<int>> vec;
    Array<int> B(n);
    // fill vector of 100 arrays
    for (size_t i = 0; i < 100; ++i) {
        B = GetArray<int>(n, i);
        vec.push_back(B);
    }
}


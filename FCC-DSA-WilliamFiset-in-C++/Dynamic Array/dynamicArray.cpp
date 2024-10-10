#include <cstdlib>
#include <iostream>

template <typename T>
class DArray {
    int length = 2;     // full size of array
    int count = 0;      // no. of relevant elements
    T* arr = (T*)malloc(length*sizeof(T));
public:
    void append(T data){
        // resize if elements exceed length of dynamic array, double the size
        if (count == length){
            length *= 2;
            arr = (T*)realloc(arr, length*sizeof(T));
        }

        // actual append code
        arr[count] = data;
        count += 1;
    }
    int size(){
        return count;
    }
    void remove(){
        if (count >= 0)
            count -= 1;
    }
    void removeAt(int i){
        if (count > 0 && i >= 0 && i < count) {
            for (int j = i; j < count - 1; j++) {
                arr[j] = arr[j + 1];
            }
            count -= 1;
        } // you can do else then throw error
    }
    void insert(int i, T data){
        if (count > 0 && i >= 0 && i < count) {
            // resize if elements exceed length of dynamic array, double the size
            if (count == length){
                length *= 2;
                arr = (T*)realloc(arr, length*sizeof(T));
            }

            // actual inserting code
            for (int j = count - 1; j >= i; j--) {
                arr[j + 1] = arr[j];
            }
            arr[i] = data;
            count += 1;
        }
    }
    T operator[](const int& index) const {
        return arr[index];
    }
    T& operator[](const int& index) {
        return arr[index];
    }
    ~DArray(){
        free(arr);
    }
};

// optional: add different constructors like, being able to pass a vector, copy vector

int main(){
    DArray<int> x;
    x.append(2);
    x.append(3);
    x.append(4);
    x.append(2);
    x.append(3);
    x.removeAt(2);
    x.removeAt(0);
    x.removeAt(2);
    x.insert(0, 69);
    x[2] = 420;
    for (int i = 0; i < x.size(); i++){
        std::cout << x[i] << std::endl;
    }
    std::cout << "Size: " << x.size() << std::endl;
}
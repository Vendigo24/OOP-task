#ifndef OOP_TASK_VECTOR_H
#define OOP_TASK_VECTOR_H

#include<iostream>
template<class T>
class Vector;

template<typename T>
std::ostream& operator<< (std::ostream&, const Vector<T>&);


template<class T>
class Vector{
private:
    T* buffer;
    size_t size;
    size_t capacity;
public:
    class Iterator{
    private:
        T* elem {nullptr};
    public:
        Iterator() = default;
        Iterator(T* data): elem(data) {}
        Iterator(const Iterator& it) {
            this->elem = it.elem;
        }

        T& operator*() { return *elem; }
        const T& operator*() const { return *elem; }
        T* operator->() { return elem; }
        const T* operator->() const { return elem; }
        T& operator[](int offset) { return elem[offset];}
        const T& operator[](int offset) const { return elem[offset]; }

        Iterator& operator++() {++elem; return *this;}
        Iterator& operator--() {--elem; return *this;}
        Iterator& operator=(const Iterator it) {elem = it.elem; return *this;};
        Iterator operator++(int) {Iterator tmp = *this; ++*this; return tmp;}
        Iterator operator--(int) {Iterator tmp = *this; --*this; return tmp;}
        Iterator& operator+=(int offset) {elem += offset; return *this;}
        Iterator& operator-=(int offset) {elem -= offset; return *this;}


        bool operator==(const Iterator that) const{ return elem == that.elem;}
        bool operator!=(const Iterator that) const{ return elem != that.elem;}
        bool operator<=>(const Iterator that) const {return elem <=> that.elem;}
    };
    Vector();
    Vector(size_t _size);
    explicit Vector(size_t _size, T value);
    ~Vector();
    Iterator begin();
    const Iterator cbegin() const;
    Iterator end();
    const Iterator cend() const;
    T& operator[](unsigned int nIndex);
    const T& operator[](unsigned int nIndex) const;
    Vector<T>& operator=(const Vector<T>& that);
    friend std::ostream& operator<< <> (std::ostream&, const Vector<T>& );
    void addMemory();
    void add(T elem);
    void remove( T elem);
    int find(T elem);
};

template<class T>
Vector<T>::Vector(){
    buffer = nullptr;
    capacity = size = 0;
}

template<class T>
Vector<T>::Vector(size_t _size, T value){
    capacity = size = _size;
    buffer = new T[size];
    for(int i = 0; i < size; i++){
        buffer[i] = value;
    }
}

template<class T>
Vector<T>::~Vector(){
    delete[] buffer;
    buffer = nullptr;
    capacity = size = 0;
}

template<class T>
typename Vector<T>::Iterator Vector<T>::begin() {
    return buffer;
}

template<class T>
const typename Vector<T>::Iterator Vector<T>::cbegin() const {
    return buffer;
}

template<class T>
typename Vector<T>::Iterator Vector<T>::end() {
    return buffer + size;
}

template<class T>
const typename Vector<T>::Iterator Vector<T>::cend() const {
    return buffer + size;
}

template<class T>
T& Vector<T>::operator[](unsigned int nIndex) {
    return buffer[nIndex];
}

template<class T>
const T& Vector<T>::operator[](unsigned int nIndex) const{
    return buffer[nIndex];
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T> &that) {
    if(this != &that){
        delete[] buffer;
        size = that.size;
        buffer = new T[size];
        for(int i = 0; i < size; i++)
            buffer[i] = that.buffer[i];
    }
    return *this;
}

template<class T>
Vector<T>::Vector(size_t _size) {
    buffer = new T[_size];
    size = _size;
    capacity = 0;
}

template<class T>
void Vector<T>::add(T elem) {
    if(capacity == size) addMemory();
    buffer[capacity++] = elem;
}

template<class T>
void Vector<T>::addMemory() {
    size += 1;
    T* tmp = buffer;
    buffer = new T[size];
    for (size_t i = 0; i < capacity; i++) buffer[i] = tmp[i];
    delete[] tmp;
}

template<class T>
void Vector<T>::remove(T elem) {
    auto it = find(elem);
    if(it != -1){
        for(it; it < capacity; it++)
            buffer[it] = buffer[it+1] ;
    }
    --size;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vec) {
    for(auto it = vec.cbegin(); it != vec.cend(); ++it) os<<*it<<" ";
    return os;
}

template<class T>
int Vector<T>::find(T elem) {
    int index = 0;
    for(auto it = begin(); it != end(); ++it, index++)
        if(*it == elem) return index;
    return -1;
}


#endif //OOP_TASK_VECTOR_H

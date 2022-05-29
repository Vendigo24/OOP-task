#ifndef OOP_TASK_VECTOR_H
#define OOP_TASK_VECTOR_H

template<class T>
class Vector{
private:
    T* buffer;
    unsigned int size;
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
    explicit Vector(unsigned int _size, T value);
    ~Vector();
    Iterator begin();
    const Iterator cbegin() const;
    Iterator end();
    const Iterator cend() const;
    T& operator[](unsigned int nIndex);
    const T& operator[](unsigned int nIndex) const;
    Vector<T>& operator=(const Vector<T>& that);
};

template<class T>
Vector<T>::Vector(){
    buffer = nullptr;
    size = 0;
}

template<class T>
Vector<T>::Vector(unsigned int _size, T value){
    size = _size;
    buffer = new T[size];
    for(int i = 0; i < size; i++){
        buffer[i] = value;
    }
}

template<class T>
Vector<T>::~Vector(){
    delete[] buffer;
    buffer = nullptr;
    size = 0;
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
#endif //OOP_TASK_VECTOR_H

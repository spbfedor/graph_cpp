#pragma once

#define SIZE 10

template <class T>
class StaticArray { // конструктор
    public:
        StaticArray(int size = 0) {
            count = size;
            if(size > 0) {
                for(int i = 0; i < size; ++i) {
                    array[i] = T();
                }
            }
        }

        // Добавление элемента
        void add(T newval) {
            if(count < SIZE) {
                array[count++] = newval;
            }
        }

        // Удаление элемента
        void del(int index) {
            if(index < 0 || index >= count) {
                return;
            }
            count--;
            for(int i = 0; i < count; ++i) { // сдвигаем элеиенты массива после удаления
                array[i] = array[i + 1];
            }
        }

        T &operator [](int index) {
            if(index < 0 || index >= count) {
                throw 0;
            }
            return array[index];
        }
        
        // поиск индекса элемента
        int find(const T &val) {
            for(int i = 0; i < count; ++i) {
                if(array[i] == val) {
                    return i;
                }
            }
            return -1;
        }

        int size() {
            return count;
        }

    private:
        T array[SIZE];
        int count;
};
// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    T* mas;
    int a, b, k;

 public:
    TPQueue():a(0), b(0), k(0), mas(new T[size]) {}
    void push(const T& f) {
        int i;
        if (k == 0) {
            k++;
            mas[0] = f;
        } else if (k < size) {
            k++;
        for (i = b; i >= a; i--) {
            if (f.prior > mas[i].prior)
                mas[(i+1)%size] = mas[i%size];
            else 
              break;
        }
        mas[(i+1)%size] = f;
        b++;
        }
    }
        T pop() {
            k--;
            return mas[(a++) % size];
        }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_

// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
private:
	T* mas;
	int a, b, k; //begin, end, count;
public:
	tpqueue():a(0),b(0),k(0),mas(new T[size]) {}
	bool empty() const {
		return k == 0;
	}
	void posh(const T& f) {
		if (k >= size)
			throw std::string("Full!");
		else
		{
			++k;
			for (int i = b; i >= a; i--) {
				if (f.pr > mas[i].pr)
					mas[i + 1] = mas[i];
				else break;
			}
			mas[i + 1] = f;
			b++;
		}
		T pop() {
			if (k == 0)
				throw std::string("empty");
			else
				k--;
			return mas[a++ % size];
		}
	}
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_

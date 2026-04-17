// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    T arr[size];
    int top_idx;

 public:
    TStack() : top_idx(-1) {}

    void push(T value) {
        if (top_idx < size - 1) {
            arr[++top_idx] = value;
        }
    }

    T pop() {
        if (!isEmpty()) {
            return arr[top_idx--];
        }
        return T();
    }

    T get() const {
        if (!isEmpty()) {
            return arr[top_idx];
        }
        return T();
    }

    bool isEmpty() const {
        return top_idx == -1;
    }
};

#endif  // INCLUDE_TSTACK_H_

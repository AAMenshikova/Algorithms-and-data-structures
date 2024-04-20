#include <iostream>

struct Node {
    int value;
    Node *next;

    Node(int val) {
        value = val;
    }
};

struct Stack {
    Node *top;

    Stack() {
        top = nullptr;
    }

    void push(int val) {
        Node *tmp = new Node(val);
        tmp->next = top;
        top = tmp;
    }

    int getTop() {
        if (!isEmpty()) {
            return top->value;
        } else {
            std::cout << "ERROR";
            exit(1);
        }
    }

    void pop() {
        if (!isEmpty()) {
            Node *tmp = top;
            top = top->next;
            delete(tmp);
        } else {
            std::cout << "ERROR";
            exit(1);
        }

    }

    bool isEmpty() {
        return top == nullptr;
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Stack st;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        char sign;
        std::cin >> sign;
        if (sign == '+') {
            int message;
            std::cin >> message;
            st.push(message);

        } else {
            int del = st.getTop();
            std::cout << del << '\n';
            st.pop();
        }
    }
    return 0;
}
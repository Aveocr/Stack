// Stack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using std::endl;
using std::cout;

class Stack {
private:
    struct Node {
        int data;
        Node* pNext, *previus;

        Node(int num) {
            data = num;
            pNext = nullptr;
        }
    };
    Node* last;
    Node* head;
    int size;
public:
    Stack();
    ~Stack();

    void push(int a);
    int pop();
    void remove();

};


Stack::Stack() {
    head = nullptr;
    last = nullptr;
    size = 0;
};
Stack::~Stack() {
    remove();
};

void Stack::push(int a) {
    Node* temp = new Node(a);
    temp->pNext = head;
    temp->previus = nullptr;
    if (head) head->previus = temp;
    head = temp;
    if (!last) last = head;
    size++;
};

int Stack::pop() {
    if (last == nullptr) {
        return -1;
    }
    else {
        Node* temp = head;
        head = temp->pNext;
        int num = temp->data;
        if (head) head->previus = nullptr;
        else last = nullptr;
        delete temp;
        size--;
        return num;
    }
};

void Stack::remove() {
    for (; size > 0; size--) {
        pop();
    }
}
int main()
{
    Stack a;
    int size = 0;
    cout << "Input size stack: ";
    std::cin >> size;
    if (size < 0) {
        std::cerr << "Error!!! You input size less than may be" << endl;
        return 0;
    }
    else {
        for (auto i = 0; i < size; i++) {
            auto buff = 0;
            std::cin >> buff;
            a.push(buff);
        }
        
        cout << "So, let remove it's now" << endl;
        for (auto i = 0; i < size; i++) {
            cout << a.pop() << " ";
        }
    }
    

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

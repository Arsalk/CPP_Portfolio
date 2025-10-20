#include <iostream>
using namespace std;

template <typename T>
class MyClass {
private:
    T secret;

public:
    MyClass(T value) : secret(value) {}

    template <typename U>
    friend class MyFriendClass;

    void display() const {
        cout << "Secret value: " << secret << endl;
    }
};

template <typename T>
class MyFriendClass {
public:
    void change(MyClass<T>& obj, T newValue) {
        obj.secret = newValue;
    }
};

int main() {
    MyClass<int> obj1(2);

    MyFriendClass<int> friendObj1;
    friendObj1.change(obj1, 10);

    obj1.display();

    MyClass<float> obj2(3.14);

    MyFriendClass<float> friendObj2;
    friendObj2.change(obj2, 6.28);

    obj2.display();

    return 0;
}

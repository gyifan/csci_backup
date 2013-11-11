#include <iostream>
#include <string>
using namespace std;

class Apple {
public:
        virtual void bite();
};

void Apple::bite() {
        cout << "Mmmm\n";
}

class CrapApple : public Apple {
        void bite();
};

void CrapApple::bite() {
        cout << "Ugh sour!\n";
}

int main() {
        Apple * apple = new CrapApple();
        apple -> bite();
        return 1;
}



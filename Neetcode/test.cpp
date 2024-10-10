#include <iostream>

class Test {
public:
    Test(){
       std::cout << "created\n";
    }

    Test(const Test& other){
        std::cout << "copied\n"; 
    }

    void getAddr(){
        std::cout << this->b << '\n';
    }

private:
    int* b = new int;

};

class Womp{
public:
    Womp(Test& ss)
        : t(ss)
    {
    }

private:
    Test t;
};


Test te(){
    return Test();
}


int main(){
    Test t;
    Test t2;
    t.getAddr();
    t2.getAddr();
    t = t2;
    std::cout << "assigned t to t2\n";
    t.getAddr();
    t2.getAddr();
    std::cout << "bruh";
}
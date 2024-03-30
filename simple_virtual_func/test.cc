

#include <stdio.h>
#include <iostream>

class A
{
public:
    int numa;

    A(){
        numa = 0;
        std::cout << "it is A() constructor\n";
    };

    A(int a){
        numa = a;
        std::cout << "it is A(int a) constructor\n";
    };
    
    virtual void show(){
        std::cout << "it is A show" << std::endl;
    }

    void test1(){
        std::cout << "it is A test1" << std::endl;
    }

    void test2(){
        std::cout << "it is A test2" << std::endl;
    }

    virtual ~A(){
         std::cout << "it is ~A\n";
    };
};

class B : public A
{
public:
    int numb;
    double dtmp;
    // B(){
    //     std::cout << "it is B() constructor\n";
    // };

    B(int a ){
        numb = a;
        std::cout << "it is B(int a) constructor\n";
    };

    void test1(){
        std::cout << "it is B test1" << std::endl;
    }

    virtual void show(){
        std::cout << "it is B show" << std::endl;
    }

    virtual ~B(){
        std::cout << "it is ~B\n";
    };
};

int main(){

    A *tmp;

    //A a;
    B b(5);

    //a.show();
    b.show();

    b.test1();
    b.test2();

    //tmp = &a;
    //tmp->show();

    tmp = (A*)(&b);
    tmp->show();

    std::cout << "A size = " << sizeof(A) << std::endl;

    std::cout << "B size = " << sizeof(B) << std::endl;


    printf("hello world.\n");
    return 0;
}
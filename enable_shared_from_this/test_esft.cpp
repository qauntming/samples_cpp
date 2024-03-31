#include <memory>
#include <iostream>
#include <thread>
 
struct Good: std::enable_shared_from_this<Good> // 注意：继承
{
    std::shared_ptr<Good> getptr() {
        return shared_from_this();
    }
};
 
struct Bad // 注意：继承
{
    // 错误写法：用不安全的表达式试图获得 this 的 shared_ptr 对象
    std::shared_ptr<Bad> getptr() {
        return std::shared_ptr<Bad>(this);
       //return shared_from_this();
    }
    ~Bad() { std::cout << "Bad::~Bad() called\n"; }
};

class A {

public:

    A() :did_it_(false) {}

    ~A() {
        std::cout << "destoried A" << std::endl;
    }

    void OnDo(bool did) {
        did_it_ = did;
        std::cout << "somthing did-A" << std::endl;
    }

    void DoSth_Async() {
        std::thread t([this]() {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            //...do somthing
            OnDo(true);

            std::cout << "A no shared_from_this = "  << std::endl;
        });

        t.detach();
    }

private:
    bool did_it_;
};


class B : public std::enable_shared_from_this<B>{

public:

    B() :did_it_(false) {}

    ~B() {
        std::cout << "destoried B" << std::endl;
    }

    void OnDo(bool did) {
        did_it_ = did;
        std::cout << "somthing did - B" << std::endl;
    }

    void DoSth_Async() {
        auto self = shared_from_this();
        std::thread t([this, self]() {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            //...do somthing
            OnDo(true);

            std::cout << "B>DoSth_Async-> use shared_from_this"  << std::endl;
        });

        t.detach();
    }

private:
    bool did_it_;
};
 
 
int main()
{
    //正确的示例：两个 shared_ptr 对象将会共享同一对象
    std::shared_ptr<Good> gp1 = std::make_shared<Good>();
    std::shared_ptr<Good> gp2 = gp1->getptr();
    std::cout << "gp2.use_count() = " << gp2.use_count() << '\n';
 
    //错误的使用示例：调用 shared_from_this 但其没有被 std::shared_ptr 占有
    try {
        //Good not_so_good;
        std::shared_ptr<Good> gp0(new Good);
        std::shared_ptr<Good> gp1 = gp0->getptr();
    } catch(std::bad_weak_ptr& e) {
        // C++17 前为未定义行为； C++17 起抛出 std::bad_weak_ptr 异常
        std::cout <<"exception: std::bad_weak_ptr trigger. "<< e.what() << '\n';    
    }
 
    // 错误的示例，每个 shared_ptr 都认为自己是对象仅有的所有者
    Bad *pb = new Bad();
    //std::shared_ptr<Bad> spb1 = std::shared_ptr<Bad>(pb);
    std::shared_ptr<Bad> spb2 = std::shared_ptr<Bad>(pb);
    std::cout << "spb2.use_count() = " << spb2.use_count() << '\n';


    {
        std::shared_ptr<A> ptrA(new A());
        ptrA->DoSth_Async();

        std::shared_ptr<B> ptrB(new B());
        ptrB->DoSth_Async();
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));

} // UB ： Bad 对象将会被删除两次
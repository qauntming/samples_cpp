#include <iostream>
#include <string>
#include <exception>
#include <memory>

using namespace std;

class MyException: public exception{
    string msg;
public:
    MyException(const string &str){
        msg = str;
    }

    string GetError() const{
        return msg;
    }
};

class A{

protected:
    void testa_print(int a){
        if(a & 1){
            throw MyException("exception from test_print.");
        }
        cout << "A::test_print func end.\n";
    }

    virtual ~A(){};
};

class B :public  A
{
public:
    void testb_print(int a){

        testa_print(a);

        cout << "B::testb_print func end.\n";
    }

    virtual ~B(){};
};


int main(){
    
    shared_ptr<B> bptr(new B()); 

    string str = "test-exception samples";

    cout << "------------------------- start -----------------------\n\n";
    cout << "samples: input str=" << str << endl;



    try{
        char ch1 = str[100];  //下标越界，ch1为垃圾值
        cout<<ch1<<endl;
    }
    catch(const exception &e){
        cout << "[1]ch1 = str[100] outof bound!\n";
    }


    /*
    检测到异常后程序的执行流会发生跳转，从异常点跳转到 catch 所在的位置，
    位于异常点之后的、并且在当前 try 块内的语句就都不会再执行了；
    
    即使 catch 语句成功地处理了错误，程序的执行流也不会再回退到异常点，
    所以这些语句永远都没有执行的机会了。本例中， 代码 " cout<<ch2<<endl;" 就是被跳过的代码。
    */

    try{
        char ch2 = str.at(100);  //下标越界，抛出异常
        cout<<ch2<<endl;
    }
    catch(const exception &e){
         cout << "[2]ch2 = str.at(100) outof bound!\n";
    }


    try{
        bptr->testb_print(1);
    }
    catch(const MyException &e){
         cout << "[3]testb_print throw exception = " << e.GetError() << endl;
    }


    cout << "end of program.\n";

    return 0;
}
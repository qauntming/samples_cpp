#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

std::string generate_file_path() {return ".data";}


template <typename T1, typename... T2>
std::string generate_file_path(T1 value, T2... args){
    std::stringstream files_ss;
    files_ss << value << generate_file_path(args...);
    return files_ss.str();
}

template <class... T>
void func(T... args){
    std::cout << sizeof...(args) << std::endl; //获取可变参数的个数
}



template <class T>
int PrintArg(T t)
{
	std::cout << t << " ";

	return 0;
}

//args代表0-N的参数包
template <class ...Args>
void CppPrint(Args... args)
{
	int a[] = { PrintArg(args)...};
	std::cout << "CppPrintEnd.." << std::endl;
}


int main(){
    std::string inpfile_prefix = "inp_";
    std::string outfile_prefix = "out_";
    
    int shape_a = 10;
    int shape_b = 20;
    int shape_c = 30;

    std::string file_name_inp = generate_file_path(inpfile_prefix, "a", "_", shape_a, "b", "_", shape_b);

    std::string file_name_out = generate_file_path(outfile_prefix, "a", "_", shape_a, "b", "_", shape_b, "c", "_", shape_c);


    std::cout << "file_name_inp = " << file_name_inp << std::endl;
    std::cout << "file_name_out = " << file_name_out << std::endl;


    func(1, 2, 3, 4);
    func(1, 2, 3);
    func(1, "2");

    CppPrint();
	CppPrint(1);
	CppPrint(1, 2);
	CppPrint(1, 2, 2.2);
	CppPrint(1, 2, 2.2, std::string("xxxx"));

    return 1;
}
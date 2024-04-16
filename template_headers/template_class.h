#ifndef _SAMPLES_CPP_TEMPLATE_HEADERS_TEMPLATE_CLASS_H 
#define _SAMPLES_CPP_TEMPLATE_HEADERS_TEMPLATE_CLASS_H

#include <iostream>


template <typename T1, typename T2> 
class SampleTest {

    int a;
    int b;

  public:

     bool compare_result_float(T1 *ref, T2 *data, int size){
        std::cout << "\ncompare_result_float \n";
      }

     bool compare_result_int(T1 *ref, T2 *data, int size){
        std::cout << "\ncompare_result_int \n";
      }


    bool compare_result(T1 *ref, T2 *data, int size){
      if(    std::is_same<T1, double>::value
          || std::is_same<T1, float>::value){
        return compare_result_float(ref, data, size);
      }
      else{
        return compare_result_int(ref, data, size);
      }
    }

  virtual ~SampleTest( ){ };

};




#endif
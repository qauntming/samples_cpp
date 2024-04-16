#include "template_class.h"
#include "dtype2enum.h"

#include <memory>


int dtpyetest(){

    std::shared_ptr<float> pDataFloat(new float[128]);
    std::shared_ptr<int> pDataInt(new int[128]);

    SampleTest<int, int> test;

    test.compare_result(pDataInt.get(), pDataInt.get(), 128);
    

    AppModeType_t typef32 = SampleTypeTraits<float>::value;
    AppModeType_t typei32 = SampleTypeTraits<int>::value;
    AppModeType_t typei8 = SampleTypeTraits<char>::value;
    
    std::cout << "SampleTypeTraits float =" << typef32
    << ",SampleTypeTraits int=" <<  typei32
    << ", SampleTypeTraits char=" << typei8;

    return 1;
}
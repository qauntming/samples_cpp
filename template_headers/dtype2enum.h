#ifndef _SAMPLES_CPP_TEMPLATE_HEADERS_DTYPE2ENUM_H 
#define _SAMPLES_CPP_TEMPLATE_HEADERS_DTYPE2ENUM_H

#include "dtype2enum.h"

typedef enum AppModeType_t{
    APP_MODE_F32 = 0,
    APP_MODE_I16 = 1,
    APP_MODE_I32 = 2,
    APP_MODE_I8 = 3,
};


template <typename T> struct SampleTypeTraits;

template <> struct SampleTypeTraits<float> {
  static const AppModeType_t value = APP_MODE_F32;
};

template <> struct SampleTypeTraits<short> {
  static const AppModeType_t value = APP_MODE_I16;
};

template <> struct SampleTypeTraits<int> {
  static const AppModeType_t value = APP_MODE_I32;
};

template <> struct SampleTypeTraits<char> {
  static const AppModeType_t value = APP_MODE_I8;
};

int dtpyetest();

#endif
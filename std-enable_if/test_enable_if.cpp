

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <variant>

// Convert variants to type T
    template <typename T>
    typename std::enable_if<       std::is_same<float, T>::value || std::is_same<double, T>::value
                                || std::is_same<Half, T>::value  || std::is_same<int32_t, T>::value
                                || std::is_same<BFloat16, T>::value
                                || std::is_same<int8_t, T>::value || std::is_same<Float8, T>::value
                                || std::is_same<BFloat8, T>::value,
                            T>::type
        constVariantCast(const ConstantVariant& val)
    {
        switch(val.index())
        {
        case static_cast<int>(DataType::Float):
            return static_cast<T>(*std::get_if<float>(&val));
        case static_cast<int>(DataType::Double):
            return static_cast<T>(*std::get_if<double>(&val));
        case static_cast<int>(DataType::Half):
            return static_cast<T>(*std::get_if<Half>(&val));
        case static_cast<int>(DataType::Int32):
            return static_cast<T>(*std::get_if<int32_t>(&val));
        case static_cast<int>(DataType::BFloat16):
            return static_cast<T>(*std::get_if<BFloat16>(&val));
        case static_cast<int>(DataType::Int8):
            return static_cast<T>(*std::get_if<int8_t>(&val));
        case static_cast<int>(DataType::Float8):
            return static_cast<T>(*std::get_if<Float8>(&val));
        case static_cast<int>(DataType::BFloat8):
            return static_cast<T>(*std::get_if<BFloat8>(&val));
        default:
            throw std::runtime_error("Unsupported variant cast type.");
        }
    }
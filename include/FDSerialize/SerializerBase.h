#ifndef SERIALIZERBASE_H
#define SERIALIZERBASE_H

#include <utility>
#include <cstddef>
#include <string>

namespace FDSerialize
{
    template<typename Serializer>
    struct SerializerBase
    {
        typedef typename Serializer::Value Value;

        template<typename T>
        static Value serialize(T &&obj)
        {
            return Serializer::serialize(std::forward<T>(obj));
        }

        template<typename T>
        static Value serialize(const T &obj)
        {
            return Serializer::serialize(obj);
        }

        template<typename T>
        static Value serialize(T obj[], size_t len)
        {
            return Serializer::serialize(obj, len);
        }

        template<typename T>
        static bool unserialize(const Value &val, T &out, std::string *err = nullptr)
        {
            return Serializer::unserialize(val, out, err);
        }

        template<typename T>
        static bool unserialize(const Value &val, T out[], size_t len, std::string *err = nullptr)
        {
            return Serializer::unserialize(val, out, len, err);
        }
    };
}

#endif // SERIALIZERBASE_H

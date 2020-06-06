#ifndef SERIALIZERBASE_H
#define SERIALIZERBASE_H

#include <utility>
#include <cstddef>
#include <string>
#include <memory>

namespace FDSerialize
{
    template<typename Serializer>
    class SerializerBase
    {
        public:
            typedef SerializerBase<Serializer> SerializerType;
            typedef typename Serializer::Allocator Allocator;
            typedef typename Serializer::Document Document;
            typedef typename Serializer::Value Value;

        protected:
            Serializer m_serializer;
            void *m_userData;

        public:
            SerializerBase() = default;

            void *getUserData() const
            {
                return m_userData;
            }

            template<typename T>
            T *getUserDataAs() const
            {
                return reinterpret_cast<T*>(m_userData);
            }

            template<typename T>
            void setUserData(T *data)
            {
                m_userData = reinterpret_cast<void *>(data);
            }

            const Document &getCurrentDocument() const
            {
                return m_serializer.getCurrentDocument();
            }

            Allocator &getAllocator()
            {
                return m_serializer.getAllocator();
            }

            void clearMemory()
            {
                m_serializer.clearMemory();
            }

            bool parseFile(const std::string_view path, std::string *err = nullptr)
            {
                return m_serializer.parseFile(path, err);
            }

            bool parseString(const std::string_view str, std::string *err = nullptr)
            {
                return m_serializer.parseFile(str, err);
            }

            std::string print(const Value &val)
            {
                return m_serializer.print(val);
            }

            void save(const Value &val, const std::string_view path)
            {
                m_serializer.save(val, path);
            }

            template<typename T>
            Value serialize(T &&obj)
            {
                return m_serializer.serialize(std::forward<T>(obj), *this);
            }

            template<typename T>
            Value serialize(const T &obj)
            {
                return m_serializer.serialize(obj, *this);
            }

            template<typename T>
            Value serialize(T obj[], size_t len)
            {
                return m_serializer.serialize(obj, len, *this);
            }

            template<typename T>
            bool unserialize(const Value &val, T &out, std::string *err = nullptr)
            {
                return m_serializer.unserialize(val, out, *this, err);
            }

            template<typename T>
            bool unserialize(const Value &val, T out[], size_t len, std::string *err = nullptr)
            {
                return m_serializer.unserialize(val, out, len, *this, err);
            }
    };
}

#endif // SERIALIZERBASE_H

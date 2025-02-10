#pragma once

template <class T>
class Sequence {
   public:
    virtual T& GetFirst() = 0;
    virtual const T& GetFirst() const = 0;
    virtual T& GetLast() = 0;
    virtual const T& GetLast() const = 0;
    virtual T& Get(size_t) = 0;
    virtual const T& Get() const = 0;
    virtual size_t GetLength() const = 0;
    virtual void Append(const T&) = 0;
    virtual void Prepend(const T&) = 0;
    virtual void InsertAt(const T&, size_t) = 0;
    virtual void RemoveAt(size_t) = 0;
    virtual ~Sequence() = default;
};

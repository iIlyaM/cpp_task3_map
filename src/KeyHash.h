//
// Created by ilya on 26.04.23.
//



#include <cstddef>
template <typename K, size_t tableSize>
struct KeyHash {
    unsigned long operator()(const K& key) const
    {
        return reinterpret_cast<unsigned long>(key) % tableSize;
    }
};


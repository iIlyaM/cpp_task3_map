//
// Created by ilya on 26.04.23.
//



#include "HashNode.h"
#include "KeyHash.h"
#include <cstddef>
#include <iostream>
#include <set>

using namespace std;


template <typename K, typename V>
class HashMap
{
public:
    HashMap();

    ~HashMap();

    bool isEmpty() const;

    int hashFunc(const K& key);

    void insert(const K& key, const V& value);

    bool remove(const K& key);

    V get(const K& key);

    void printMap();

    set<K> keys();

    int size();

private:
    const int hashGroups = 10;
    HashNode<K, V>** table;
};

template <typename K, typename V>
HashMap<K, V>::HashMap()
{
    table = new HashNode<K, V>* [hashGroups]();
}

template <typename K, typename V>
HashMap<K, V>::~HashMap()
{
    for (size_t i = 0; i < hashGroups; ++i) {
        HashNode<K, V>* entry = table[i];

        while (entry != NULL) {
            HashNode<K, V>* prev = entry;
            entry = entry->getNext();
            delete prev;
        }

        table[i] = NULL;
    }
}



template <typename K, typename V>
bool HashMap<K, V>::isEmpty() const
{
    int counter = 0;
    HashNode<K, V>* entry = NULL;
    for (int i = 0; i < hashGroups; i++)
    {
        entry = table[i];
        if (entry != NULL)
        {
            counter++;
        }
    }

    if (counter != 0)
    {
        return false;
    }

    return true;
}

template <typename K, typename V>
int HashMap<K, V>::hashFunc(const K& key)
{
    return key % hashGroups;
}

template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value)
{
    int hashValue = hashFunc(key);
    HashNode<K, V>* prev = NULL;
    HashNode<K, V>* entry = table[hashValue];

    while (entry != NULL && entry->getKey() != key)
    {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == NULL)
    {
        entry = new HashNode<K, V>(key, value);

        if (prev == NULL)
        {
            table[hashValue] = entry;
        }
        else
        {
            prev->setNext(entry);
        }
    }
    else
    {
        entry->setValue(value);
    }
}

template <typename K, typename V>
V HashMap<K, V>::get(const K& key)
{
    int hashValue = hashFunc(key);
    HashNode<K, V>* entry = table[hashValue];

    while (entry != NULL) {
        if (entry->getKey() == key) {
            V value = entry->getValue();
            return value;
        }

        entry = entry->getNext();
    }

    return NULL;
}


template <typename K, typename V>
bool HashMap<K, V>::remove(const K& key)
{
    int hashValue = hashFunc(key);
    HashNode<K, V>* prev = NULL;
    HashNode<K, V>* entry = table[hashValue];
    while (entry != NULL && entry->getKey() != key)
    {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == NULL)
    {
        return false;
    }
    else
    {
        if (prev == NULL)
        {
            table[hashValue] = entry->getNext();
        }
        else
        {
            prev->setNext(entry->getNext());
        }
        delete entry;
    }
    return true;
}

template<typename K, typename V>
void HashMap<K, V> ::printMap()
{
    for (int rows = 0; rows < hashGroups; rows++)
    {
        HashNode<K, V> *entry = table[rows];
        while (entry != NULL)
        {
            HashNode<K, V>* current = entry;
            cout << "Key: " << current->getKey() << " Value: " << current->getValue() << "\n";
            entry = entry->getNext();
        }
    }
}

template<typename K, typename V>
set<K> HashMap<K, V> ::keys()
{
    set<K> keys;
    for (int rows = 0; rows < hashGroups; rows++)
    {
        HashNode<K, V>* entry = table[rows];
        while (entry != NULL)
        {
            HashNode<K, V>* current = entry;
            keys.insert(current->getKey());
            entry = entry->getNext();
        }
    }
    return keys;

}

template<typename K, typename V>
int HashMap<K, V> ::size()
{
    int count = 0;
    for (int rows = 0; rows < hashGroups; rows++)
    {
        HashNode<K, V>* entry = table[rows];
        while (entry != NULL)
        {
            HashNode<K, V>* current = entry;
            count++;
            entry = entry->getNext();
        }
    }
    return count;
}


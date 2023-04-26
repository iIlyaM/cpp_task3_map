//
// Created by ilya on 26.04.23.
//

#include "map_test.h"
#include "HashMap.h"
#include "gtest/gtest.h"
TEST(testSize, HashMap)
{
    HashMap<int, string> hmap;
    hmap.insert(1, "jfhdjskhfjksdjfsd");
    hmap.insert(2, "2");
    hmap.insert(3, "3");
    EXPECT_EQ(hmap.size(), 3);
}

TEST(testIsEmpty, HashMap)
{
    HashMap<int, string> hmap;
    EXPECT_EQ(hmap.isEmpty(), true);
    hmap.insert(2, "2");
    EXPECT_EQ(hmap.isEmpty(), false);

}

TEST(testGet, HashMap)
{
    HashMap<int, string> hmap;
    hmap.insert(5, "1");
    EXPECT_EQ(hmap.get(5), "1");
}

TEST(testRemove, HashMap)
{
    HashMap<char, string> hmap;
    hmap.insert('1', "one");
    hmap.insert('2', "two");
    hmap.insert('3', "three");
    EXPECT_EQ(hmap.size(), 3);
    EXPECT_EQ(hmap.remove('2'), true);
    EXPECT_EQ(hmap.remove('4'), false);
    EXPECT_EQ(hmap.size(), 2);
}

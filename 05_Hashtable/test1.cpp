#include "hashtable.hpp"
void test1()
{
    HashMap<int, string> hash;
    hash.insert(100, "ddd");
    hash.insert(200, "ggg");
    hash.insert(50, "bbb");
    hash.insert(80, "cccc");
    hash.insert(150, "ffff");
    hash.insert(600, "sss");
    hash.insert(10, "aabb");
    hash.insert(1, "aaa");
    hash.insert(133, "eeee");
    cout << *hash.get(133) << endl;
    cout << hash.size() << endl;
    if (hash.contains(100))
    {
        cout << *hash.get(100) << endl;
    }
    hash.remove(100);
    if (!hash.contains(100))
    {
        cout << "error" << endl;
    }
}
void test2()
{
    HashMap<int, string> hash;
    hash.insert(100, "ddd");
    hash.insert(200, "ggg");
    hash.insert(50, "bbb");
    hash.insert(80, "cccc");
    hash.insert(150, "ffff");
    hash.insert(600, "sss");
    hash.insert(10, "aabb");
    hash.insert(1, "aaa");
    hash.insert(133, "eeee");
    hash.remove(100);
    cout << hash.size() << endl;
    HashMap<int, string> hash1(hash);
    hash1.remove(133);
    cout << hash1.size() << endl;
    cout << *hash1.get(600) << endl;
    cout << *hash1.get(150) << endl;
    //cout << *hash.get(100) << endl;
    HashMap<int, string> hash2;
    hash2 = hash1;
    hash2.remove(50);
    cout << hash2.size() << endl;
    cout << *hash2.get(600) << endl;
    cout << *hash2.get(150) << endl;
}
int main()
{
    test1();
    test2();
    return 0;
}

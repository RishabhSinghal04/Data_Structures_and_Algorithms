
#include <iostream>
#include <conio.h>
#include <unordered_map>
#include <vector>

template <typename K, typename V>
void frequency(const std::vector<K> &vec, std::unordered_map<K, V> &hash)
{
    for (const auto &element : vec)
    {
        hash[element]++;
    }
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
    for (const auto &element : vec)
    {
        out << element << ", ";
    }
    out << "\b\b \b";
    return out;
}

template <typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::unordered_map<K, V> &map_container)
{
    for (const auto &element : map_container)
    {
        out << element.first << " : " << element.second << '\n';
    }
    return out;
}

int main()
{
    using namespace std;

    const std::vector<char> alphabets{'a', 'A', 'a', 'b', 'B'};
    std::unordered_map<char, uint16_t> hash{};

    frequency(alphabets, hash);

    cout << alphabets << '\n' << hash << '\n';

    getch();
    return 0;
}
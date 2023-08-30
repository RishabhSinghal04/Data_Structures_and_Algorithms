// Insert characters in a string at certain positions

#include <iostream>
#include <conio.h>
#include <random>
#include <set>
#include <string>

void assign_random_positions(std::set<size_t> &, const size_t &,
                             const std::string_view &, const size_t &, const size_t &);

std::string insert_characters(const std::string &, const std::set<size_t> &);

std::ostream &operator<<(std::ostream &out, const std::set<size_t> &indices)
{
    for (const auto &index : indices)
    {
        out << index << ", ";
    }
    out << "\b\b ";
    return out;
}

int main()
{
    using namespace std;

    const size_t MIN = 0;
    size_t num_of_indices = 0;
    string st{};

    cout << "Enter a string : ";
    getline(cin >> ws, st);

    cout << "Enter number of positions : ";
    cin >> num_of_indices;

    size_t MAX = st.length() - 1;
    set<size_t> indices{};

    assign_random_positions(indices, num_of_indices, st, MIN, MAX);

    if (indices.empty())
    {
        cout << "No Position\nNo Insertion" << '\n';
        return 0;
    }
    cout << "Positions are : " << indices << '\n';
    cout << "String after inserting charcters : " << insert_characters(st, indices);

    getch();
    return 0;
}

void assign_random_positions(std::set<size_t> &indices, const size_t &SIZE,
                             const std::string_view &st,
                             const size_t &MIN, const size_t &MAX)
{
    if (MIN > MAX || MAX >= st.length() || SIZE >= st.length())
    {
        return;
    }

    std::random_device rd;
    std::uniform_int_distribution<uint64_t> dist(MIN, MAX);

    while (indices.size() < SIZE)
    {
        indices.insert(dist(rd));
    }
}

std::string insert_characters(const std::string &st, const std::set<size_t> &indices)
{
    std::string_view characters{"@#%&*"};
    std::random_device rd;
    std::uniform_int_distribution<uint16_t> dist(0, characters.length() - 1);

    const size_t LENGTH = st.length();
    auto indices_it = indices.begin();
    std::string temp{};

    for (size_t index = 0; index < LENGTH; ++index)
    {
        if (indices_it != indices.end() && index == *indices_it)
        {
            temp += characters.at(dist(rd));
            ++indices_it;
        }
        temp += st.at(index);
    }
    return temp;
}
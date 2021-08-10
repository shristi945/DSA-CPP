#include <iostream>
#include <utility>
#include <map>
using namespace std;
int main()
{
    multimap<int, string, greater<int>> sorted_map;
    // Sort the names of animals in descending order of the number of legs
    sorted_map.insert(make_pair(6,   "bug"));
    sorted_map.insert(make_pair(4,   "cat"));
    sorted_map.insert(make_pair(100, "centipede"));
    sorted_map.insert(make_pair(2,   "chicken"));
    sorted_map.insert(make_pair(0,   "fish"));
    sorted_map.insert(make_pair(4,   "horse"));
    sorted_map.insert(make_pair(8,   "spider"));

    for (auto const& entry: sorted_map)
    {
        cout << entry.second << " (has " << entry.first << " legs)" << '\n';
    }

    return 0;
}
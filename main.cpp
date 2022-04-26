#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

std::vector<int> unionize(std::vector<int>& left, std::vector<int>& right)
{
    std::vector<int> out;
    for(int& i : left)
    {
        out.push_back(i);
    }
    for(int& i : right)
    {
        if(std::count(out.begin(), out.end(), i))
            continue;
        else
            out.push_back(i);
    }
    return out;
}

std::vector<int> intersect(std::vector<int>& left, std::vector<int>& right)
{
    std::vector<int> out;
    for(int& i : left)
    {
        if(std::count(right.begin(), right.end(), i))
            out.push_back(i);
    }
    return out;
}

std::vector<int> difference(std::vector<int>& left, std::vector<int>& toSubtract)
{
    std::vector<int> out;
    for(int& i : left)
    {
        if(std::count(toSubtract.begin(), toSubtract.end(), i))
            continue;
        else
            out.push_back(i);
    }
    return out;
}
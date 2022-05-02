#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

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

int main() {
    // reading in the file and adding to the two vectors
    ifstream inFS;
    inFS.open("../sets.txt");

    if (!inFS.is_open()) { // make sure file opens
        cout << "Could not open set file" << endl;
        return 1;
    }
    string set1, set2;
    getline(inFS, set1);
    getline(inFS, set2);
    inFS.close();
    vector<int> left;
    vector<int> right;
    // parse out each line and add to vector
    stringstream lineSS(set1); // create string stream
    stringstream lineSR(set2);
    string cur;
    while(lineSS >> cur)
        left.push_back(stod(cur));
    while(lineSR >> cur)
        right.push_back(stod(cur));
    vector<int> join, diff, inter;
    join = unionize(left, right);
    for (int i : join) {
        cout << "Union Set: " << i << endl;
    }

    diff = difference(left, right);
    for (int i : diff) {
        cout << "Difference Set: " << i << endl;
    }

    inter = intersect(left, right);
    for (int i : inter) {
        cout << "Intersect Set: " << i << endl;
    }

    return 0;
}
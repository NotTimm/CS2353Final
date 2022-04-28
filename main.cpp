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
        cout << "Could not open downhill.csv" << endl;
        return 1;
    }
    string line;
    getline(inFS, line);

    while (getline(inFS, line)) {
        vector<int> left;
        vector<int> right;

        // parse out each line and add to vector
        stringstream lineSS(line); // create string stream
        string set1Values, set2Values;

        getline(lineSS, set1Values, ' ');
        left.push_back(stod(set1Values));
        getline(lineSS, set2Values, ' ');
        right.push_back(stod(set2Values));

        // printing the final sets
        for (int i = 0; i < unionize.size(); ++i) {
            cout << "Union Set: " << unionize.at(i).at(i) << endl;
        }

        for (int i = 0; i < difference.size(); ++i) {
            cout << "Difference Set: " << difference.at(i).at(i) << endl;
        }

        for (int i = 0; i < intersect.size(); ++i) {
            cout << "Intersect Set: " << intersect.at(i).at(i) << endl;
        }

        return 0;
    }
}
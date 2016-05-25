#include "main.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>
#include "Utils.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    vector< vector<int> > map;
    srand(0);
    int size = 100;

    cout << "Before: " << endl;
    // Generate random map between 1-10
    for (int i = 0; i < size; i++){
        map.push_back(vector<int>());
        for(int j = 0; j < size; j++){
            int tmp = i/10;
            map.at(i).push_back(tmp);
            cout << tmp << " ";
        }
        cout << endl;
    }
    
    int middle = map.size()/2;
    Utils::flood_fill(&map, map.size()/2, map.at(0).size()/2, map.at(middle).at(middle), -1);

    cout << endl << "After: " << endl;

    for (int i = 0; i < map.size(); i++){
        for (int j = 0; j < map.at(0).size(); j++ ){
            cout << map.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

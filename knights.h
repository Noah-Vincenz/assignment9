#ifndef KNIGHTS_H
#define KNIGHTS_H

#include <utility>
#include <vector>
#include <algorithm>

using std::pair;
using std::make_pair;
using std::vector;

typedef vector<pair<int,int> > Path;

/** Helper function: adds two pairs of ints */
pair<int,int> operator+(const pair<int,int> & a, const pair<int,int> & b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

// TODO - your code goes here
vector<pair<int, int> > moves(pair<int, int> pairIn) {
    vector<pair<int, int> > vectorToReturn;
    vectorToReturn.reserve(8);
    vectorToReturn.push_back(make_pair(pairIn.first+1, pairIn.second-2));
    vectorToReturn.push_back(make_pair(pairIn.first+2, pairIn.second-1));
    vectorToReturn.push_back(make_pair(pairIn.first+2, pairIn.second+1));
    vectorToReturn.push_back(make_pair(pairIn.first+1, pairIn.second+2));
    vectorToReturn.push_back(make_pair(pairIn.first-1, pairIn.second+2));
    vectorToReturn.push_back(make_pair(pairIn.first-2, pairIn.second+1));
    vectorToReturn.push_back(make_pair(pairIn.first-2, pairIn.second-1));
    vectorToReturn.push_back(make_pair(pairIn.first-1, pairIn.second-2));
    return vectorToReturn;
};

vector<pair<int, int> > legal_moves(int dim, Path path, pair<int,int> pos) {
    vector<pair<int, int> > movesVector = moves(pos);
    vector<pair<int, int> > vectorToReturn;
    std::copy_if(movesVector.begin(), movesVector.end(), back_inserter(vectorToReturn),
                [dim, path](const pair<int, int> x) {
                    return (x.first >= 0 && x.first < dim && x.second >= 0 && x.second < dim && find(path.begin(), path.end(), x) == path.end());
                });
    return vectorToReturn;
};
#include <iostream>
using std::cout;
using std::endl;

pair<Path,bool> first_tour (int dim, Path currentPath) { //problem is that it doesnt stop searching when it has found one solution and then returns no tour found
    if (currentPath.size() == dim * dim) {
        return pair<Path,bool> (currentPath, true);
    }
    else {
        for (pair <int, int> x : legal_moves(dim, currentPath, currentPath.at(currentPath.size()-1))) {
            Path tempPath = currentPath;
            tempPath.push_back(x);
            auto result = first_tour(dim, tempPath);
            if (result.second == true) return result;
        }
        return pair<Path,bool> (Path(), false);
    }
};
// Do not edit below this line

#endif

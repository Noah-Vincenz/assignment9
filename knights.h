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
vector<pair<int, int> > moves(const pair<int, int> pairIn) {
    return vector<pair<int, int> > {make_pair(pairIn.first+1, pairIn.second+2),
                                    make_pair(pairIn.first+2, pairIn.second+1),
                                    make_pair(pairIn.first+2, pairIn.second-1),
                                    make_pair(pairIn.first+1, pairIn.second-2),
                                    make_pair(pairIn.first-1, pairIn.second-2),
                                    make_pair(pairIn.first-2, pairIn.second-1),
                                    make_pair(pairIn.first-2, pairIn.second+1),
                                    make_pair(pairIn.first-1, pairIn.second+2)};
};

vector<pair<int, int> > legal_moves(const int dim, const Path path, const pair<int,int> pos) {
    vector<pair<int, int> > movesVector = moves(pos);
    vector<pair<int, int> > vectorToReturn;
    std::copy_if(movesVector.begin(), movesVector.end(), back_inserter(vectorToReturn),
                [dim, path](const pair<int, int> x) {
                    return (x.first >= 0 && x.first < dim && x.second >= 0 && x.second < dim && find(path.begin(), path.end(), x) == path.end());
                });
    return vectorToReturn;
};

pair<Path,bool> first_tour (const int dim, const Path currentPath) {
    if (currentPath.size() == dim * dim) {
        return make_pair(currentPath, true);
    }
    else {
        for (pair <int, int> x : legal_moves(dim, currentPath, currentPath.at(currentPath.size()-1))) {
            Path tempPath = currentPath;
            tempPath.push_back(x);
            auto result = first_tour(dim, tempPath);
            if (result.second == true) {
                return result;
            }
        }
        return make_pair(Path(), false);
    }
};
// Do not edit below this line

#endif

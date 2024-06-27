#include "Parser.cpp"

class Solver3{

public:
    std::vector<int> optimise(std::vector<point>);
    int best_move(point, point, point, point, point, point);
    void make_move(std::vector<int>, int, int, int, int);
    double path_length(std::vector<point>, std::vector<int>);
};
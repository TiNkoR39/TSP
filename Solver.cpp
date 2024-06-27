#include "Solver.h"


bool Solver::comp(point a1, point a2, point b1, point b2){
   return -dist(a1, a2) - dist(b1, b2) + dist(a1, b1) + dist(a2, b2) < 0;
}

double Solver::path_length(std::vector<point> points, std::vector<int> path){
    int n = points.size();
    double length = 0;

    for(int i = 0; i < n - 1; i++) length += dist(points[path[i]], points[path[i+1]]);
    length += dist(points[path[0]], points[path[n-1]]);
    return length;
}

std::vector<int> Solver::optimise(std::vector<point> points){
    int n = points.size(), i, j;
    std::vector<int> path;
    
    for(i = 0; i < n; i++) path.emplace_back(i);

    bool can_improve = true;


    while (can_improve){
        can_improve = false;
        for (int i = 0; i < n - 1; i++) 
            for (int j = i + 1; j < n; j++)
                if (comp(points[path[i]], points[path[i+1]], points[path[j]], points[path[(j + 1)%n]])){
                    reverse(path.begin() + i + 1, path.begin() + j + 1);
                    std::swap(path[i + 1], path[(j+1)%n]);
                }

    }

    return path;
}
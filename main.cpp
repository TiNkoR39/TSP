#include "Solver.cpp"




int main(){
    int i;
    Parser p;
    std::string filename = "tsp_107_1";
    std::vector<point> points = p.parse(filename);
    Solver s;
    std::vector<int> path = s.optimise(points);

    for(i = 0; i < path.size(); i++) std::cout << path[i] << " ";
    std::cout << std::endl;
    std::cout << s.path_length(points, path) << std::endl;
    return 0;
}
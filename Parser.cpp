#include "Parser.h"

double point::get_x(){return x;}
double point::get_y(){return y;}

point::point(double x, double y){
    this -> x = x;
    this -> y = y;
}

double dist(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

std::vector<point>Parser::parse(std::string filename){
    std::ifstream File(filename);
    std::vector<point> points;
    if(!File.is_open()) {
        std::cout << "can not read file" << std::endl;
        return points;
    }
    int n;
    File >> n;
    double x,y;
    for(int i = 0; i < n; i++){
        File >> x;
        File >> y;
        points.emplace_back(point(x,y));
    }
    File.close();
    return points;
}
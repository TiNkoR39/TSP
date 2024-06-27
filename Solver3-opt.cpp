#include "Solver3-opt.h"



double Solver3::path_length(std::vector<point> points, std::vector<int> path){
    int n = points.size();
    double length = 0;

    for(int i = 0; i < n - 1; i++) length += dist(points[path[i]], points[path[i+1]]);
    length += dist(points[path[0]], points[path[n-1]]);
    return length;
}



int Solver3::best_move(point a, point b, point c, point d, point e, point f){
    std::vector<double> moves;

  
    moves.push_back(dist(a,e) + dist(b,f) - dist(a,b) - dist(e,f));
    moves.push_back(dist(c,e) + dist(d,f) - dist(c,d) - dist(e,f));
    moves.push_back(dist(a,c) + dist(b,d) - dist(a,b) - dist(c,d));

    double del_edges = dist(a,b) + dist(c,d) + dist(e,f);

    moves.push_back(dist(a,c) + dist(b,e) + dist(d,f) - del_edges);
    moves.push_back(dist(a,e) + dist(d,b) + dist(c,f) - del_edges);
    moves.push_back(dist(a,d) + dist(e,d) + dist(b,f) - del_edges);
    moves.push_back(dist(a,c) + dist(b,e) + dist(d,f) - del_edges);

    double max = -1e-5;
    int best_move = 0;

    for(int i = 0; i < 7; i++)
        if(moves[i] < max){
            best_move = i;
            max = moves[i];
        }
    
    return best_move+1;
}

void Solver3::make_move(std::vector<int> path, int best_move, int i, int j, int k){
    int n = path.size();
    if(best_move == 1){
        reverse(path.begin() + (k+1)%n, path.begin() + (i));
    } 
    else if(best_move == 2){
        reverse(path.begin() + (j+1)%n, path.begin() + (k));
    } 
    else if(best_move == 3){
        reverse(path.begin() + (i+1)%n, path.begin() + (j));
    } 
    else if(best_move == 4){
        reverse(path.begin() + (i+1)%n, path.begin() + (k));
        reverse(path.begin() + (i+1)%n, path.begin() + (j));
    } 
    else if(best_move == 5){
        reverse(path.begin() + (k+1)%n, path.begin() + (i));
        reverse(path.begin() + (i+1)%n, path.begin() + (j));
    } 
    else if(best_move == 6){
        reverse(path.begin() + (k+1)%n, path.begin() + (i));
        reverse(path.begin() + (j+1)%n, path.begin() + (k));
    } 
    else if(best_move == 7){
        reverse(path.begin() + (k+1)%n, path.begin() + (i));
        reverse(path.begin() + (i+1)%n, path.begin() + (j));
        reverse(path.begin() + (j+1)%n, path.begin() + (k));
    }
    return;
}


std::vector<int> Solver3::optimise(std::vector<point> points){
    int n = points.size(), i, j, k, c1, c2, c3, move;
    point a,b,c,d,e,f;
    std::vector<int> path;
    
    for(i = 0; i < n; i++) path.emplace_back(i);

    bool can_improve = true;


    while (can_improve){
        can_improve = false;
        for(c1 = 0; c1 < n; c1++){
            i = c1;
            a = points[path[i]];
            b = points[path[(i+1)%n]];
            for(c2 = c1+1; c2 < n-2; c2++){
                j = (i+c2)%n;
                c = points[path[j]];
                d = points[path[(j+1)%n]];
                for(c3 = c2+1; c3 < n; c3++){
                    k = (i+c3)%n;
                    e = points[path[k]];
                    f = points[path[(k+1)%n]];
                    move = best_move(a,b,c,d,e,f);
                    if(move != 0){
                        std::cout << "move " << move << std::endl;
                        make_move(path, move, i, j, k);
                        can_improve = true;
                    }
                }
            }

        }
    }

    return path;
}
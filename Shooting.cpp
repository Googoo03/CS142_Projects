#include <iostream>
#include <cmath>

double eps = 1e-9;

int main(int argc, char* argv[]){
    int num_shots{},points{};
    double radius = 1;
    int num_segments = 10;



    std::cin >> num_shots;

    double xcoord{},ycoord{},distance{};
    //Take the x and y coordinates, find the radius. Since the circle is split up into 10 segments, each is r/10 size.
    for(int i = 0; i < num_shots; ++i){
        std::cin >> xcoord;
        std::cin >> ycoord;
        distance = sqrt(xcoord*xcoord + ycoord*ycoord);

        points += std::max(num_segments - floor((distance-eps) / (radius * 0.1)),0.0);
    }
    std::cout << points << std::endl;
    return 0;
}
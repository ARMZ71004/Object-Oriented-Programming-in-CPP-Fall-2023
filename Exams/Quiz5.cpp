#include <iostream>

class Point{
private:
    int x;
    int y;
    static int numPoints;
public:
    Point(): x(0), y(0) {numPoints++;}
    Point(int a, int b): x(a), y(b) {numPoints++;}
    void setX(int c){
        x = c;
    }
    void setY(int d){
        y = d;
    }
    void format() const{
        std::cout << x << "," << y << std::endl;
    }
    static int getNumPoints(){
        return numPoints;
    }
};

int Point::numPoints = 0;

void print(const Point& x){
    x.format();
}



int main() {
 std::cout << std::endl;
 Point p1;
 Point p2(7, 8);
 p1.setX(9);
 p1.setY(19);
 print(p1);
 print(p2);
 std::cout << Point::getNumPoints() << std::endl;
 std::cout << std::endl;
 return 0;
}
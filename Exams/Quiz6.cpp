#include <iostream>

class Point{
private:
    int x;
    int y;
    static int numPoints;
public:
    Point(): x(0), y(0) {numPoints++;}
    Point(int a, int b): x(a), y(b) {numPoints++;}
    ~Point() {numPoints--;}
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
    void setX(int c){
        x = c;
    }
    void setY(int d){
        y = d;
    }
    friend std::istream& operator>>(std::istream& in, Point& point) {  //friend overload
        in >> point.x >> point.y;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& point) { //friend overload
        out << point.x << " " << point.y;   // needs " " 
        return out;
    }

    Point operator-() const {
        return Point(-x, -y); //unary overload
    }

    Point operator+(const Point& z) const {
        return Point(x + z.x, y + z.y);
    }

    Point operator++(int) {  //postfix overloading
        Point temp(*this);
        x++;
        y++;
        return temp;
    }
    bool operator==(const Point& other) const {  //overload equivalence
        return (x == other.x) && (y == other.y);
    }
    const int& operator[] (int index) const{
    if(index < 0 || index > 1) { throw std::out_of_range ("index is out of range"); }  
        if(index == 0)
            return x;
        else
            return y;
    }

    static int getNumPoints(){
        return numPoints;
    }
};

int Point::numPoints = 0;







int main() {
 std::cout << std::endl;
 Point p1;
 Point p2(3, 5);
 std::cout << "Enter x and y values: ";
 std::cin >> p1;
 std::cout << p1 << " " << -p2 << std::endl;
 std::cout << (p1+p2) << std::endl;
 std::cout << (p2++) << std::endl;
 std::cout << p2 << std::endl; 
 std::cout << (p1 == p2) << std::endl;
 std::cout << p1[0] << " " << p1[1] << std::endl;
 std::cout << Point::getNumPoints() << std::endl;
 std::cout << std::endl;
 return 0;
}

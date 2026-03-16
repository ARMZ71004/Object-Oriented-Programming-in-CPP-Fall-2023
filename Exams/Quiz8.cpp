#include <iostream>

class IntArr{
private:
    int* List;
    int Size;
    int Capacity;
public:
    IntArr(int start) : List(new int[start]), Size(0), Capacity(start) {}
    ~IntArr() { delete[] List;}
    int getSize() const {return Size;}
    int getCapacity() const {return Capacity;}
    int operator[] (int index) const{
        if(index < 0 || index >= Size) { throw std::out_of_range ("b is out of range"); }  
        return List[index];
    }
    void grow(){
        int Capacity2 = Capacity * 2;
        int* List2 = new int[Capacity2];
        for (int i = 0; i < Size; ++i) {
            List2[i] = List[i];
        }
        delete[] List;
        List = List2;
        Capacity = Capacity2;
    }
    void push_back(int temp){
        if (Size == Capacity) {
            grow();
        }
        List[Size++] = temp;
    }
    
    void insert(int a, int b){
        if (b < 0 || b > Size) {throw std::out_of_range("b out of range");}
        if (Size == Capacity) {
            grow();
        }
        for (int i = Size; i > b; --i) {
                List[i] = List[i - 1];
            }
            List[b] = a;
            Size++;
        }
};

int main() {
 std::cout << std::endl;
 try {
 // test constructors, getSize, getCapacity, push_back
 IntArr a{5};
 for(int i=0; i<5; i++) { a.push_back((i+1)*5); }
 for(int i=0; i<a.getSize(); i++) { std::cout << a[i] << " "; }
 std::cout << "\n" << a.getSize() << " " << a.getCapacity() << std::endl;
 std::cout << "\nTEST INSERT" << std::endl;
 a.insert(0, 0); // insert beginning
 a.insert(12, 3); // insert middle
 a.insert(100, 7); // insert end
 for(int i=0; i<a.getSize(); i++) { std::cout << a[i] << " "; }
 std::cout << "\n" << a.getSize() << " " << a.getCapacity() << std::endl;
 } catch(const std::exception& e) {
 std::cerr << e.what() << std::endl;
 }
 std::cout << std::endl;
 return 0;
}
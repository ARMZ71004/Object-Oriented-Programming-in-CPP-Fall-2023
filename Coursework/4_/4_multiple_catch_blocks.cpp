// S. Trowbridge 2023
#include <iostream>

void append(int *a, int capacity, int &size, int val) 
{
    if(size == capacity) { throw std::out_of_range("Array is full."); }     // array is full: throw out_of_range exception
    if(val < 0) { throw std::invalid_argument("Values must be postive"); }  // val is negative: throw invalid_argument exception
    a[size++] = val;
}
void print(int *a, int size) 
{
    for(int i=0; i<size; ++i) { std::cout << a[i] << " "; }
    std::cout << "\n";
}
int main()                                                                  // https://cplusplus.com/reference/exception/exception/
{         
    std::cout << std::endl;

    const int CAPACITY = 3;
    int size=0, n=0;
    int posInts[CAPACITY];

    try 
    {
        do {                                                                // loop to append array data from user input
            std::cout << "Enter a postive integer or -1 to end: ";          
            std::cin >> n;
            if(n == -1) { break; }                                          // sentinel value entered: exit the loop
            append(posInts, CAPACITY, size, n);                                         
        } while(true);
        print(posInts, size); 
    }
    catch(const std::invalid_argument& e)                                   // code is run if invalid_argument is thrown 
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
    catch(const std::out_of_range& e)                                       // code is run if out_of_range is thrown 
    {
        std::cerr << "Error: " << e.what() << "\n";                                 
        print(posInts, size);                      
    }

    std::cout << "\nProgram Continues" << "\n";

    std::cout << std::endl;
    return 0;
}

#include <iostream>

int *getNeighbors(int *a, int SIZE, int b){
    int *temp = new int [2];
    if(b == SIZE - 1 || b == 0){
        *(temp) = 0;
        *(temp+1) = 0;   
    }
    else{
        *(temp) = *(a+b-1);
        *(temp+1) = *(a+b+1);
    }
    return (temp);
}
void print(int *b, int c){
    for(int i=0; i<c; i++){std::cout<<*(b+i)<<" ";}
    std::cout<<std::endl;
    delete [] b;
}

int main(){
 std::cout << std::endl;
 const int SIZE = 5;
 int a[SIZE] = {1,2,3,4,5};
 int *b = getNeighbors(a, SIZE, 3);
 print(b, 2);
 int *c = getNeighbors(a, SIZE, 0);
 print(c, 2);
 std::cout << std::endl;
 return 0;}

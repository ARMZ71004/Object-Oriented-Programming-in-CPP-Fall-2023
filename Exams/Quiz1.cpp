#include <iostream>

int print(int *a,int SIZE){
    for(int i = 0; i<SIZE; ++i){
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}


void rotateleft(int *a,int SIZE,int b){
    for(int i = 0; i<b; ++i){
        int c = 0;
        c = a[4];
        a[4] = a[0];
        a[0] = a[1];
        a[1] = a[2];
        a[2] = a[3];
        a[3] = c;
    }    
}


int main(){
    std::cout<<std::endl;

    const int SIZE = 5;
    int a[SIZE] = {35,20,13,43,22};

    
    print(a, SIZE);
    rotateleft(a, SIZE, 1);
    print(a, SIZE);
    rotateleft(a, SIZE, 2);
    print(a, SIZE);
    
    std::cout<<std::endl;
    return 0;
}

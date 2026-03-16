// S. Trowbridge 2023
#include <iostream>

// Recursion
// base case - end the recursive process
// recursive task - repetively reduce the problem to eventually reach the base case

// tracing the recursive process
// countDown(3)  print 3
//  countDown(2)  print 2
//    countDown(1)  print 1
//      countDown(0) return
//    countDown(1) return
//  countDown(2) return
// countDown(3) return
void countDown(int n) {
    if(n==0) { return; }            // base case: if n is 0, stop printing

    std::cout << n << std::endl;    // recursive task: print n, recurse to the next smallest digit
    countDown(n-1);                
}

// tracing the recursive process
// sumDigits(3)  
//  sumDigits(2)  
//    sumDigits(1) return 1
//  sumDigits(2) return 1 + 2
// sumDigits(3) return 3 + 3
int sumDigits(int n) {
    if(n==1) { return n; }          // base case: if n is 1, return n and stop summing 
         
    return sumDigits(n-1) + n;      // recursive task: solve sumDigits for the next smallest digit, then sum the current n
}

int main() {
    std::cout << std::endl;

    int n = 3;
    countDown(n);
    std::cout << std::endl << sumDigits(n) << std::endl;

    std::cout << std::endl;
    return 0;
}
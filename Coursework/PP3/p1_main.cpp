int main() 
{
    std::cout << std::endl;

    int *p = initialize(10);
    int *q = initialize(15);
    std::cout << *p << " " << p << "\n";
    std::cout << *q << " " << q << "\n\n";    

    increment(p);
    std::cout << *p << " " << p << "\n\n";

    swap(p, q);
    std::cout << *p << " " << p << "\n";
    std::cout << *q << " " << q << "\n\n";  

    swapVal(p, q);
    std::cout << *p << " " << p << "\n";
    std::cout << *q << " " << q << "\n";    

    std::cout << std::endl;
    return 0;
}

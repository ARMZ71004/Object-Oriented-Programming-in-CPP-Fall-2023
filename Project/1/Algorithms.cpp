#include "Algorithms.h"

void Algorithms::merge(List &s1, List &s2, List &list, bool less){
    Iterator l1 = s1.begin();
    Iterator l2 = s2.begin();
    
    while (l1.hasNext() == true && l2.hasNext() == true){
        if (compare(l1.getData(), l2.getData(), true) == true){
            push_back(list, l1.getData());
            l1.next();
        }
        else if (compare(l1.getData(), l2.getData(), true) == false){
            push_back(list, l2.getData());
            l2.next();
        }
    }
    while (l1.hasNext() == true && l2.hasNext() == false) 
    {
        push_back(list, l1.getData());
        l1.next();
    }

    while (l1.hasNext() == false && l2.hasNext() == true) 
    {
        push_back(list, l2.getData());
        l2.next();
        
    }
}
/*void Algorithms::mergeSort(List &list, bool less){   
    // get the size of the masterList
    // if the masterList is empty return

    // create two sublists, subList1, subList2
    // point an iterator to the first node in the masterList

    // iterate through the first half of the masterList
    //      add value from the masterList to subList1
    //      advance the iteratfor for masterList

    // iterate through the second half of the masterList
    //      add value from the masterList to subList2
    //      advance the iteratfor for masterList    

    // remove all values from the masterList

    // recurse on subList1
    // recurse on subLIst2
    // merge subList1, subList2 and the masterList}
    
void Algorithms::reverse(List &list){}*/

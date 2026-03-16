/*

// Return an iterator pointing to the value you are searching for or nullptr if value not found
Iterator search(List &list, int &value) 
{
    // list empty: return iterator -> nullptr

    // create start and end node pointers: start -> head, end -> nullptr

    // do/while loop while end != nullptr or end != start
    //      create mid pointer and last pointer: mid -> start, last -> node after start
    //      loop while last != end
    //          advance last to node after last
    //          if last != end
    //              advance mid to node after mide
    //              advance last to node after last (this advances last pointer 2x as fast as mid pointer)
    //              (at this point in the algorithm mid is the middle node of the current search zone, so we can do the classic binary search mid comparison)
    //
    //      if mid == nullptr: return iterator -> nullptr
    //      otherwise if mid is equivalent to value: return iterator -> mid
    //      otherwise if mid > value: start -> node after mid
    //      otherwise end -> mid 
    //      
    //  return Iterator -> nullptr (values was not found in the do/while loop)
    //

*/
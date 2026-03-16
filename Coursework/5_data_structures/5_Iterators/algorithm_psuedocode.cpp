#include <iostream>

// Sorted Insert 
// void sortedInsert(List &list, Data &d, bool less);
//
// 1. if list is empty or new data < head data, call push front
// 2. Otherwise, traverse the list with a pointer, current, checking new data < current->next data
//    Once current->next data is larger, stop, insert new node between current and current->next
// 3. If the list is a doubly linked list, make sure you update the prev pointer when you insert.
// 4. If you insert at the end of the list, update the tail pointer to point to the new node
// 5. Use the compare function to compare data based upon the boolean parameter less.
//    If less is true, sort from small to large, if less is false, from large to small.
//
// For example to insert the node [23] into the list below in the order smallest to largest:
// 
// Create new pointer, current, and point it to head (use this pointer to traverse the list):
// 
//           C
// head -> [ 5 ] -> [ 12 ] -> [ 17 ] -> [ 25 ] -> [ 30 ] -> nullptr 
//                    C
// head -> [ 5 ] -> [ 12 ] -> [ 17 ] -> [ 25 ] -> [ 30 ] -> nullptr 
//                              C
// head -> [ 5 ] -> [ 12 ] -> [ 17 ] -> [ 25 ] -> [ 30 ] -> nullptr 
//
// Since current-> next (25) > new data (23), insert the new node after current:
//
//                              C       NEW
// head -> [ 5 ] -> [ 12 ] -> [ 17 ] -> [23] -> [ 25 ] -> [ 30 ] -> nullptr 
//
// If singly linked list, test by printing list before and after sorting.
// If doubly linked list, also test by printing in reverse before and after sorting (to make sure prev links are correct).


// Reverse Function 
// void reverse(List &list);
//
// If singly linked list remember to reset head ptr at the end.
// If doubly linked list remember to reset tail ptr at the end.
// if doubly linked list, set the prev pointer before updating next as you iterate.
//
// The original List:
//              head                               
//              [ a ] -> [ b ] -> [ c ] -> [ d ] -> [ e ] -> nullptr 
// 
// 1. Create three pointers: current, prev and temp
// 2. Point current = head, prev and temp to nullptr like this:
//
//               C                                            TP
//             [ a ] -> [ b ] -> [ c ] -> [ d ] -> [ e ] -> nullptr 
//
// 3. Iterate through the list updating the pointers and links as follows:
//
//               C        T                                   P
//  nullptr <- [ a ]    [ b ] -> [ c ] -> [ d ] -> [ e ] -> nullptr 
//               P        CT                                   
//  nullptr <- [ a ]    [ b ] -> [ c ] -> [ d ] -> [ e ] -> nullptr 
//
//
//               P        C        T       
//  nullptr <- [ a ] <- [ b ]    [ c ] -> [ d ] -> [ e ] -> nullptr 
//                        P        CT       
//  nullptr <- [ a ] -> [ b ]    [ c ] -> [ d ] -> [ e ] -> nullptr 
//
//
//                        P        C        T
//  nullptr <- [ a ] <- [ b ] <- [ c ]    [ d ] -> [ e ] -> nullptr 
//                                 P        CT
//  nullptr <- [ a ] -> [ b ] <- [ c ]    [ d ] -> [ e ] -> nullptr 
//
// etc.
//
// Remember to reset head pointer when done.
//
// If singly linked list, test by printing before after reverse function call.
// If doubly linked list, also test printing the list backwards after reverse function call.


int main() {
    return 0;
}

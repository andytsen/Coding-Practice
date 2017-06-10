#include <string>
#include <iostream>


// if node is NULL: append nothing
// if node has 2 children: append val + '('
// if node has left, no right:  append val + '(', do not call rec on right NULL
// if node has no left, right: append val + '(', call rec on left NULL
// if node is a leaf: call it on none of them and return the value
//
//
//
//
//

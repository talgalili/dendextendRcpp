/*
Copyright (C) Tal Galili

This file is part of dendextendRcpp.

dendextend is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

dendextend is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

 A copy of the GNU General Public License is available at
 http://www.r-project.org/Licenses/

*/


#include <Rcpp.h>
using namespace Rcpp;
#include "is_functions.h"
#include "get_branches_heights.h"




void find_dend_for_height( List tree, std::vector<RObject>& lower, double height){
   
//    Rcout << "The tree's height is: " << get_height(tree) << "\n";       
//    Rcout << "The height to compare to is: " << height << "\n";       
    
   if(get_height( as<RObject>(tree) ) <= height) {
      lower.push_back( as<RObject>(tree) );
      // no reason to keep going...
   } else {
//      List tree(wrap(tree));
      int n = tree.size();
      for( int i=0; i<n; i++){
         if(is_leaf( tree[i] )) {
               // When we reach a leaf
               // this is always a new cluster
            lower.push_back(tree[i]);         
//            List tree_to_push=tree[i];
//            RObject(tree_to_push).attr("class") = "dendrogram";
//            lower.push_back(tree_to_push);         
         } else {
               // else:
               // add all the relevant dends underneath this node:
            find_dend_for_height(tree[i], lower, height);
         }      
      } // end for       
   } // end else  
}



// [[Rcpp::export]]
std::vector<RObject> Rcpp_cut_lower(List x, double height, bool nodes_into_dend=true){
   
   // This line:
   List tree = clone(x);
   // Is essential for making this happen:
//   require(dendextendRcpp)
//   dend = as.dendrogram(hclust(dist(iris[1:4,-5])))
//   Rcpp_cut_lower(dend, .14,F)
//   cut_lower_fun(dend, .14, labels)
//   Rcpp_cut_lower(dend, .14,F) # it would be different without clone!
//   lapply(cut(dend, .14)$lower, labels)
//
//      require(microbenchmark)
//      microbenchmark(
//         new = cut_lower_fun(dend, .14, labels),
//         old = lapply(cut(dend, .14)$lower, labels)
//      )
//      # ~7 times faster for a n=4 tree
//      # ~13 times faster for a n=150 tree

   
   std::vector<RObject> lower; // create the returned vector   
   
   if( is_leaf( as<RObject>(tree) )) {      
      lower.push_back(tree[0]);
//      return(tree);
   } else {
      find_dend_for_height(tree, lower, height);   
   }      
      
   // this would make us not need to turn the nodes into 
   // dendrograms in order to run the functions on them
   // the time improvement is significant - IF this was needed...
   if(nodes_into_dend) {       
      // the next few lines are to discover the length of "lower"

      // one way of getting n:
      List lower_list(wrap(lower));
      int n = lower_list.size();
      // another way, thanks to Kevin Ushey:
//      int n = Rf_length(wrap(lower));
      
      for(int i = 0; i < n; ++i) {
                  RObject temp_lower_node = lower[i];
                  temp_lower_node.attr("class") = "dendrogram";
          }         
   }
   
   
   return(lower) ;
}







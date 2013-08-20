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
#include "is_functions.hpp"
#include "get_branches_heights.hpp"




void find_dend_for_height( List tree, std::vector<RObject>& lower, double height){
   
//    Rcout << "The tree's height is: " << get_height(tree) << "\n";       
//    Rcout << "The height to compare to is: " << height << "\n";       
    
   if(get_height(tree) <= height) {
      lower.push_back(tree);
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
std::vector<RObject> Rcpp_cut_lower(List tree, double height){
   
   std::vector<RObject> lower; // create the returned vector   
   
   if(is_leaf( tree )) {      
      lower.push_back(tree[0]);
//      return(tree);
   } else {
      find_dend_for_height(tree, lower, height);   
   }      
   return(lower) ;
}







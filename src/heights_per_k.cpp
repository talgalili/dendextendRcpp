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


//
//
//
//// Extract the label attr from an R object
//// Only works for a character label (will crash in case of an integer value)
//double k_per_height(RObject x, double = height){
//    double height = 0;
//    if (x.hasAttribute("height")) {
//        height = as<double>(x.attr( "height" )) ;
//    } else {
//       ::Rf_warning("'height' attr is missing from node, 0 is returned, please check your tree.");
////    Rcout << "List with " << tree.size() << " elements\n";       
//    }
//    return height; // either TRUE or FALSE. But often, if it exists - it is TRUE.
//}





int find_k_per_height( List tree, double height){
   
//    Rcout << "The tree's height is: " << get_height(tree) << "\n";       
//    Rcout << "The height to compare to is: " << height << "\n";       
    
   if(get_height( as<RObject>(tree) ) <= height) {
      return 1; //    current_k is 1
      // no reason to keep going...
   } 
   
   int current_k = 0;
   for( int i=0; i<tree.size(); i++){
      if(is_leaf( tree[i] )) {
            // When we reach a leaf
            // this is always a new cluster
         current_k += 1;
      } else {
            // else:
            // count all the clusters underneath this node:
         current_k += find_k_per_height(tree[i], height);
      }      
   } 
   return current_k;   
}



// [[Rcpp::export]]
int Rcpp_k_per_height(List x, double height){
   if(is_leaf( as<RObject>(x) )) {
      return 1; //    current_k is 1      
   }
   
   return(find_k_per_height(x, height)) ;
}




// just as before, but this time for many heights!
// [[Rcpp::export]]
IntegerVector Rcpp_k_per_heights(List x, NumericVector heights){
   
   int n_height = heights.size();
   IntegerVector k_s(n_height);
   
   for(int i = 0; i < n_height; ++i) {
      k_s[i] = Rcpp_k_per_height(x, heights[i]);      
   }
   
   return(k_s);
}



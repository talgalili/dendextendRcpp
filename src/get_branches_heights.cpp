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





// Extract the height attr from an R object
double get_height(RObject x){
    double height = 0;
    if (x.hasAttribute("height")) {
        height = as<double>(x.attr( "height" )) ;
    } else {
       ::Rf_warning("'height' attr is missing from node, 0 is returned, please check your tree.");
//    Rcout << "List with " << data.size() << " elements\n";       
    }
    return height; // either TRUE or FALSE. But often, if it exists - it is TRUE.
}





void push_back_heights( List data, std::vector<double>& the_heights, 
                     bool labels_heights=false, bool branches_heights=true){
//   The Rcout are commented in order to not through too many comments to the user...
//    Rcout << "List with " << data.size() << " elements\n";
   if(branches_heights) {
      double x_height = get_height( as<RObject>(data) );
      the_heights.push_back(x_height);               
   }
   
            
    for( int i=0; i<data.size(); i++){
        if( is_list( data[i] ) ){
            // recurse
//            Rcout << "Recursing into list\n";
            push_back_heights( data[i], the_heights , labels_heights, branches_heights) ;
        } else if( is_leaf( data[i] ) & labels_heights ){
//            Rcout << "Looking at leaf\n";
            // we want to collect them. we can use the NumericVector class
            // wince we know this is a numeric vector.
            double x_height = get_height(data[i]);
            the_heights.push_back(x_height);
        } // else do nothing
    }
}



// [[Rcpp::export]]
std::vector<double> Rcpp_get_dend_heights(List x, 
                     bool labels_heights = false, bool branches_heights = true){
    std::vector<double> the_heights ;
    push_back_heights(x, the_heights, labels_heights, branches_heights) ;
    return(the_heights) ;
}



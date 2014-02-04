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



// Extract the label attr from an R object
// Only works for a character label (will crash in case of an integer value)
std::string get_label(RObject x){
    std::string label = "<EMPTY>";
    if (x.hasAttribute("label")) {
        label = as<std::string>(x.attr( "label" )) ;
    }
    return label; // either TRUE or FALSE. But often, if it exists - it is TRUE.
}





void push_back_labels( List data, std::vector<std::string>& the_labels){
//   The Rcout are commented in order to not through too many comments to the user...
//    Rcout << "List with " << data.size() << " elements\n";
    for( int i=0; i<data.size(); i++){
        if( is_list( data[i] ) ){
            // recurse
//            Rcout << "Recursing into list\n";
            push_back_labels( data[i], the_labels ) ;
        } else if( is_leaf( data[i] ) ){
//            Rcout << "Looking at leaf\n";
            // we want to collect them. we can use the NumericVector class
            // wince we know this is a numeric vector.
            std::string x_label = get_label(data[i]);
            the_labels.push_back(x_label);
        } // else do nothing
    }
}



// [[Rcpp::export]]
std::vector<std::string> Rcpp_labels_dendrogram(List x){   

   std::vector<std::string> the_labels;   
   
//   // For some reason - this doesn't work - so I fixed it in the R code...
//   // if the tree is a leaf - return its label:
//   if( is_leaf(x) ){      
//      std::string x_label = get_label(x);
//      the_labels.push_back(x_label);
//   } else {
//      // else: run through all of it:
//      push_back_labels(x, the_labels) ;      
//   }
   
   push_back_labels(x, the_labels) ;      
   return(the_labels) ;
}













// [[Rcpp::export]]
int Rcpp_count_leaves(List data){
//   The Rcout are commented in order to not through too many comments to the user...
//    Rcout << "List with " << data.size() << " elements\n";

   int number_of_leaves=0;

    for( int i=0; i<data.size(); i++){
        if( is_list( data[i] ) ){
            // recurse
//            Rcout << "Recursing into list\n";
            number_of_leaves += Rcpp_count_leaves( data[i]) ;
        } else if( is_leaf( data[i] ) ){
           number_of_leaves++;
        } // else do nothing
    }
    return(number_of_leaves);
}

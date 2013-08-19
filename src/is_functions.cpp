// is_function.h
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


// check if an R object is a list
// [[Rcpp::export]]
bool is_list(RObject x){
    return TYPEOF(x) == VECSXP ;
}

// check if an R object is a string
bool is_string(RObject x){
    return TYPEOF(x) == STRSXP && Rf_length(x) == 1 ;
}

// check if an R object is logical
bool is_logical(RObject x){
    return TYPEOF(x) == LGLSXP && Rf_length(x) == 1 ;
}

// check if an R object is a leaf - e.g: that it has the leaf attr - and that 
// it is TRUE.
// [[Rcpp::export]]
bool is_leaf(RObject x){
//   if( TYPEOF(x) != REALSXP ) return false ;  // x can be of any R type, it should NOT be restricted to typeof(x)=="double" only...
   if (!x.hasAttribute("leaf")) return false ;  // if we don't have a "leaf" than FALSE.
//   if( !is_logical( x.attr("leaf") ) ) return false ; // if it is not logical, I want it to crash on the next line...
// it is better for the function to crash because of a bad "leaf" attr, than to return FALSE and mislead the user that everything is o.k.
   bool leaf = x.attr( "leaf" ) ;
   return leaf; // either TRUE or FALSE. But often, if it exists - it is TRUE.
}


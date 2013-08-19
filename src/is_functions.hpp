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


// thanks to: http://stackoverflow.com/questions/15891781/how-to-call-on-a-function-found-on-another-file
// http://stackoverflow.com/questions/152555/h-or-hpp-for-your-class-definitions

//#ifndef PLAYER_H    // To make sure you don't declare the function more than once by including the header multiple times.
//#define PLAYER_H

#include <Rcpp.h>
using namespace Rcpp;

bool is_list(RObject x);
bool is_string(RObject x);
bool is_logical(RObject x);
bool is_leaf(RObject x);

//#endif
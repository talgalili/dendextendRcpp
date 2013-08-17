# Copyright (C) Tal Galili
#
# This file is part of RcppDend.
#
# dendextend is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# dendextend is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
#  A copy of the GNU General Public License is available at
#  http://www.r-project.org/Licenses/
#



#' @title Find Labels from a dendrogram Object using Rcpp
#' @export
#' @S3method labels dendrogram
#' @description 
#' Extract the leaves labels from a dendrogram object.
#' @usage
#' \method{labels}{dendrogram}(object, ...)
#' @param object a dendrogram object.
#' @param ... not used.
#' @return A vector of labels from the dendrogram leaves.
#' This is often a character vector, but there are cases it might be integer.
#' @author Romain Francois, Dirk Eddelbuettel, Tal Galili
#' @source 
#' R-devel-mailing list.
#' @seealso \code{\link{labels}}, \code{\link{dendrogram}}
#' @examples
#' dend <- as.dendrogram(hclust(dist(USArrests)))
#' 
#' labels(dend)
#' 
#' require(microbenchmark)
#' microbenchmark(stats:::labels.dendrogram(dend),
#'                RcppDend:::labels.dendrogram(dend),
#'                times = 100)
#' # about 30 times faster. It is faster the larger the tree is.
labels.dendrogram <- function(object,...) {
   # we would get errors if, for example, labels are not characters
   tryCatch(return(Rcpp_labels_dendrogram(object)) , error = function(e) {
      warning("Your tree's labels are not 'character'. Hence the 'labels' function can not use the Rcpp function \n and is expected to be 20 to 40 times SLOWER! \n In order to fix this, simply run on your tree:\n labels(tree)<-as.character(labels(tree)) \n This function is in the {dendextend} R package \n Do it once - and many functions which rely on the tree 'labels' will run faster. :) ")
   })
   # else: (in case of integer labels)
   stats:::labels.dendrogram(object)   
}


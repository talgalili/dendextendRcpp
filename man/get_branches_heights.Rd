\name{get_branches_heights}
\alias{get_branches_heights}
\title{Get branches height attr from a dendrogram}
\usage{
  get_branches_heights(tree, sort = TRUE,
    decreasing = FALSE, ...)
}
\arguments{
  \item{tree}{a dendrogram object.}

  \item{sort}{logical (TRUE). Should the heights be
  sorted?}

  \item{decreasing}{logical (FALSE). Should the sort be
  increasing or decreasing? Not available for partial
  sorting}

  \item{...}{not used.}
}
\value{
  A numeric vector of the dendrogram's nodes heights
  (excluding leaves).
}
\description{
  Get branches height attributes from a dendrogram.

  This function is intended to override
  \code{\link[dendextend]{get_branches_heights}}. Since it
  is 40-100 times faster.
}
\examples{
\dontrun{
dend = as.dendrogram(hclust(dist(iris[1:150,-5])))
plot(dend)
get_height(dend)


attributes(dend) <- NULL
Rcpp_get_dend_heights(dend) # knows to through a warning :)

dend = as.dendrogram(hclust(dist(iris[1:150,-5])))
Rcpp_get_dend_heights(dend)
get_branches_heights(dend)
Rcpp_get_dend_heights(dend,T,F)
Rcpp_get_dend_heights(dend,T,F)

require(dendextend)
Rcpp_get_dend_heights(dend)
get_branches_heights(dend,sort=F)


require(microbenchmark)
microbenchmark(
   RcppDend:::get_branches_heights(dend),
   dendextend:::get_branches_heights(dend,sort=F)
)
# Rcpp is about 40-107 times faster!
}
}
\author{
  Tal Galili
}
\seealso{
  \code{\link{labels}}, \code{\link{dendrogram}},
  \code{\link{attr}}
}


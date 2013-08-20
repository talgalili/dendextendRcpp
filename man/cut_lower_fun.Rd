\name{cut_lower_fun}
\alias{cut_lower_fun}
\title{Find Labels from a dendrogram Object using Rcpp}
\usage{
  cut_lower_fun(tree, h, FUN = labels, warn = FALSE, ...)
}
\arguments{
  \item{tree}{a dendrogram object.}

  \item{h}{a scalar of height to cut the tree by.}

  \item{warn}{logical (FALSE) - should the user be warned
  if reverting to default? (I set it to FALSE since it can
  be very noisy sometimes...)}

  \item{...}{passed to FUN.}
}
\value{
  A vector of labels from the dendrogram leaves. This is
  often a character vector, but there are cases it might be
  integer.
}
\description{
  Cuts the a tree at height h and returns a list with the
  FUN function implemented on all the sub trees created by
  cut at height h. This is used for creating a
  \link[dendextend]{cutree.dendrogram} function, by using
  the \code{labels} function as FUN.

  This is the Rcpp version of the function, offering a
  10-60 times improvement in speed (depending on the tree
  size it is used on).
}
\examples{
dend <- as.dendrogram(hclust(dist(USArrests)))

labels(dend)

require(microbenchmark)
microbenchmark(stats:::labels.dendrogram(dend),
               dendextendRcpp:::labels.dendrogram(dend),
               times = 100)
# about 30 times faster. It is faster the larger the tree is.
}
\author{
  Tal Galili
}
\seealso{
  \code{\link{labels}}, \code{\link{dendrogram}},
  \link[dendextend]{cutree.dendrogram}
}


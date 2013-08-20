\name{cut_lower_labels}
\alias{cut_lower_labels}
\title{Find Labels from a dendrogram Object using Rcpp}
\source{
  R-devel-mailing list.
}
\usage{
  cut_lower_labels(tree, h, warn = FALSE, ...)
}
\arguments{
  \item{tree}{a dendrogram object.}

  \item{h}{a scalar of height to cut the tree by.}

  \item{warn}{logical (FALSE) - should the user be warned
  if reverting to default? (I set it to FALSE since it can
  be very noisy sometimes...)}

  \item{...}{not used.}
}
\value{
  A vector of labels from the dendrogram leaves. This is
  often a character vector, but there are cases it might be
  integer.
}
\description{
  Cuts the a tree at height h and returns a list with the
  labels for each cluster.

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
  Romain Francois, Dirk Eddelbuettel, Tal Galili
}
\seealso{
  \code{\link{labels}}, \code{\link{dendrogram}}
}


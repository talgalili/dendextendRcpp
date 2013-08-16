\name{labels.dendrogram}
\alias{labels.dendrogram}
\title{Find Labels from a dendrogram Object using Rcpp}
\source{
  R-devel-mailing list.
}
\usage{
  \method{labels}{dendrogram}(object, ...)
}
\arguments{
  \item{object}{a dendrogram object.}

  \item{...}{not used.}
}
\value{
  A vector of labels from the dendrogram leaves. This is
  often a character vector, but there are cases it might be
  integer.
}
\description{
  Extract the leaves labels from a dendrogram object.
}
\examples{
hc <- hclust(dist(USArrests))
dend <- as.dendrogram(hc)

labels(dend)

require(microbenchmark)
microbenchmark(stats:::labels.dendrogram(dend),
               RcppDend:::labels.dendrogram(dend),
               times = 100)
# about 30 times faster. It is faster the larger the tree is.
}
\author{
  Romain Francois, Dirk Eddelbuettel, Tal Galili
}
\seealso{
  \code{\link{labels}}, \code{\link{dendrogram}}
}


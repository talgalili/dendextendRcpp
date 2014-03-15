\name{dendextendRcpp_heights_per_k.dendrogram}
\alias{Rcpp_get_dend_heights}
\alias{Rcpp_k_per_height}
\alias{Rcpp_k_per_heights}
\alias{dendextendRcpp_heights_per_k.dendrogram}
\alias{old_heights_per_k.dendrogram}
\title{Which height will result in which k for a dendrogram}
\usage{
dendextendRcpp_heights_per_k.dendrogram(tree, ...)
}
\arguments{
  \item{tree}{a dendrogram.}

  \item{...}{not used.}
}
\value{
a vector of heights, with its names being the k clusters
that will result for cutting the dendrogram at each height.
}
\description{
This is the Rcpp version of the heights_per_k.dendrogram
from the dendextend R package. It is intended to override
that function in order to get a speed gain of ranging from
10 times faster (for a tree with 3 leaves), to 130 times
(!) faster (for a tree with 150 leaves).
}
\examples{
\dontrun{

dend = as.dendrogram(hclust(dist(iris[1:150,-5])))

# plutral heightS
dendextendRcpp_heights_per_k.dendrogram(dend,1)
dendextendRcpp_heights_per_k.dendrogram(dend,.5)
dendextendRcpp_heights_per_k.dendrogram(dend,0.05)
dendextendRcpp_heights_per_k.dendrogram(dend,0)
dendextendRcpp_heights_per_k.dendrogram(dend,-1)

dendextendRcpp_heights_per_k.dendrogram(dend,c(1,.5,.2,0,-1))

require(microbenchmark)
dend = as.dendrogram(hclust(dist(iris[1:150,-5])))
dend = as.dendrogram(hclust(dist(iris[1:30,-5])))
dend = as.dendrogram(hclust(dist(iris[1:3,-5])))
microbenchmark(
   #    dendextendRcpp::heights_per_k.dendrogram(dend),
   dendextendRcpp::dendextendRcpp_heights_per_k.dendrogram(dend),
   dendextend::old_heights_per_k.dendrogram(dend)
)
# improvment is 10 times faster (in Rcpp) for a tree of size 3
# 76 times faster for a tree of size 30
# And:
# 134 times faster for a tree of size 150!!
}
}


# dendextendRcpp

## Introduction

A dendrogram object in R are is a list structure with attributes in its
nodes and leaves. 

## Motivation

Working with dendrogram objects often require a function
to recursively go through all (or most) element in the list object.
Naturally, such function are rather slow in R, but can become much faster
thank to Rcpp.

This package offers faster manipulation of dendrogram objects in
R. 

## Installation

To install the stable version on CRAN:

```r
# install.packages('dendextendRcpp') # not yet available from CRAN
```

To install the GitHub version:

```r
if (!require('devtools')) install.packages('devtools'); require('devtools')
install_github('dendextendRcpp', 'talgalili')
```

## Usage

```r
library(dendextendRcpp)

hc <- hclust(dist(USArrests))
dend <- as.dendrogram(hc)

labels(dend)

require(microbenchmark)
microbenchmark(stats:::labels.dendrogram(dend),
               dendextendRcpp:::labels.dendrogram(dend),
               times = 100)
# about 30 times faster. It is faster the larger the tree is.

```

## Contact

You are welcome to:
* submit suggestions and bug-reports at: <https://github.com/talgalili/dendextendRcpp/issues>
* send a pull request on: <https://github.com/talgalili/dendextendRcpp/>
* compose a friendly e-mail to: <tal.galili@math.tau.ac.il>


## Available functions

* labels.dendrogram (or simply labels)


## MORE INFORMATION

Visit the Rcpp project!

* http://www.rcpp.org/
* http://gallery.rcpp.org/
* http://cran.r-project.org/web/packages/Rcpp/index.html
* http://dirk.eddelbuettel.com/code/rcpp.html
* http://blog.r-enthusiasts.com/tag/rcpp/ 


[![Build Status](https://travis-ci.org/talgalili/dendextendRcpp.png?branch=master)](https://travis-ci.org/talgalili/dendextendRcpp)



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
install.packages('dendextendRcpp')
```

To install the cutting-edge GitHub version:

```r
if (!require('devtools')) install.packages('devtools'); 
devtools::install_github('talgalili/dendextendRcpp')
```

## Usage

```r
library(dendextendRcpp)

hc <- hclust(dist(USArrests))
dend <- as.dendrogram(hc)

labels(dend)

require(microbenchmark)
microbenchmark(stats_labels.dendrogram(dend),
               dendextendRcpp::dendextendRcpp_labels.dendrogram(dend),
               times = 100)
# about 10-30 times faster. It is faster the larger the tree is.

```

## Contact

You are welcome to:

* submit suggestions and bug-reports at: <https://github.com/talgalili/dendextendRcpp/issues>
* send a pull request on: <https://github.com/talgalili/dendextendRcpp/>
* compose a friendly e-mail to: <tal.galili@math.tau.ac.il>


## Available functions

* dendextendRcpp_labels.dendrogram 
* cut_lower_fun
* get_branches_heights
* heights_per_k.dendrogram


## MORE INFORMATION

Visit the Rcpp project!

* http://www.rcpp.org/
* http://gallery.rcpp.org/
* http://cran.r-project.org/web/packages/Rcpp/index.html
* http://dirk.eddelbuettel.com/code/rcpp.html
* http://blog.r-enthusiasts.com/tag/rcpp/ 





# Code of conduct

Please note that this project is released with a [Contributor Code of Conduct](CONDUCT.md). By participating in this project you agree to abide by its terms.



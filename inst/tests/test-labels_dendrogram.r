# require(testthat)

context("labels.dendrogram with and without Rcpp")


test_that("Rcpp_labels_dendrogram works",{
#    hc0 <- hclust(dist(USArrests), "ave")
#    dend0 <- as.dendrogram(hc0)
#    
#    # because USArrests has no row names, hence - it is creating a dendrogram
#    # with integer labels
#    expect_warning(RcppDend:::labels.dendrogram(dend0))
   
   hc <- hclust(dist(USArrests))
   dend <- as.dendrogram(hc)
   
#    Rcpp_labels_dendrogram(dend)

#    expect_identical(stats:::labels.dendrogram(dend),
#                     RcppDend:::labels.dendrogram(dend)
#    )   
   
})


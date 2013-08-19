# require(testthat)
# require(RcppDend)

context("labels.dendrogram with and without Rcpp")


test_that("Rcpp_labels_dendrogram works",{
#    hc0 <- hclust(dist(USArrests), "ave")
#    dend0 <- as.dendrogram(hc0)
#    
#    # because USArrests has no row names, hence - it is creating a dendrogram
#    # with integer labels
#    expect_warning(RcppDend:::labels.dendrogram(dend0))
   
   dend <- as.dendrogram(hclust(dist(USArrests)))
   # plot(dend)
   
   expect_identical(length(Rcpp_labels_dendrogram(dend)), 50L)
   
   expect_identical(stats:::labels.dendrogram(dend),
                    RcppDend:::labels.dendrogram(dend) )   
   
   # doesn't work for labels which are integers, here is an example:
   no_rownames_USArrests <- USArrests
   rownames(no_rownames_USArrests) <- NULL
   no_rownames_dend <- as.dendrogram(hclust(dist(no_rownames_USArrests)))   
   expect_warning(RcppDend:::labels.dendrogram(no_rownames_dend)) # we reverted to  stats:::labels.dendrogram(dend)

   one_leaf <- dend[[1]][[1]][[1]]
   # plot(one_leaf)
   expect_identical(labels(one_leaf), "Florida")
#    RcppDend:::labels.dendrogram(one_leaf)
#    RcppDend:::get_label
#    RcppDend:::Rcpp_labels_dendrogram(one_leaf)
#    dendextend:::labels.dendrogram(one_leaf)
   
})




test_that("Rcpp_count_leaves works",{
   dend <- as.dendrogram(hclust(dist(USArrests)))
   
   
   expect_identical(Rcpp_count_leaves(dend),
                    50L
   )   
   
})

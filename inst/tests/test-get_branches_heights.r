# require(testthat)

context("get_branches_heights works")


test_that("get_branches_heights works",{
   
   dend <- as.dendrogram(hclust(dist(USArrests)))

   require(dendextend)
   expect_identical(RcppDend:::get_branches_heights(dend),
                    dendextend:::get_branches_heights(dend))
   

   
   
#    require(microbenchmark)
#    microbenchmark(
#       RcppDend:::get_branches_heights(dend),
#       dendextend:::get_branches_heights(dend)
#    )
#    # Rcpp is 50 times faster...
#    
   
})



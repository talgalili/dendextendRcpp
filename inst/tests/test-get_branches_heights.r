# require(testthat)

context("get_branches_heights works")


test_that("get_branches_heights works",{
   
   dend <- as.dendrogram(hclust(dist(USArrests)))

   require(dendextend)
   expect_identical(dendextendRcpp:::get_branches_heights(dend),
                    dendextend:::get_branches_heights(dend))
   

   
   
#    require(microbenchmark)
#    microbenchmark(
#       dendextendRcpp:::get_branches_heights(dend),
#       dendextend:::get_branches_heights(dend)
#    )
#    # Rcpp is 50 times faster...
#    
   
})



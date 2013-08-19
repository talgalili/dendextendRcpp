# require(testthat)

context("heights_per_k.dendrogram works")


test_that("heights_per_k.dendrogram works",{
   
   dend <- as.dendrogram(hclust(dist(USArrests)))

   #'    RcppDend:::heights_per_k.dendrogram(dend),
   #'    dendextend:::heights_per_k.dendrogram(dend)
   
   require(dendextend)
   expect_identical(RcppDend:::heights_per_k.dendrogram(dend),
                    dendextend:::heights_per_k.dendrogram(dend))
   

   
   
#    require(microbenchmark)
#    microbenchmark(
#       RcppDend:::get_branches_heights(dend),
#       dendextend:::get_branches_heights(dend)
#    )
#    # Rcpp is 50 times faster...
#    
   
})



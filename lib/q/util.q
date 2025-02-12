
/
    @file
        util.q
    
    @description
        Utility functions.
\

// @brief Row strided index.
// @param x Short|Int|Long Length of list to be indexed.
// @param y Short|Int|Long Stride size.
// @return List Strided index.
.util.rowStrdIdx:{til[y]+/:til x+1-y};

// @brief Column strided index.
// @param x Short|Int|Long Length of list to be indexed.
// @param y Short|Int|Long Stride size.
// @return List Strided index.
.util.colStrdIdx:{til[y]+\:til x+1-y};

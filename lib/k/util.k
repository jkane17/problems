
/
    @file
        util.k
    
    @description
        Utility functions.
\

// @brief Row strided index.
// @param x Short|Int|Long Length of list to be indexed.
// @param y Short|Int|Long Stride size.
// @return List Strided index.
.util.rowStrdIdx:{(!y)+/:!x+1-y};

// @brief Column strided index.
// @param x Short|Int|Long Length of list to be indexed.
// @param y Short|Int|Long Stride size.
// @return List Strided index.
.util.colStrdIdx:{(!y)+\:!x+1-y};

// @brief Generate a range of longs.
// @param l Short|Int|Long Range lower bound.
// @param u Short|Int|Long Range upper bound.
// @param s Short|Int|Long Step.
// @param sf Function Scaling function to allow different range variations.
// @return Longs Range.
.util.range0:{[l;u;s;sf] sf s*!1+(u-l) div s};

// @brief List of consecutive integers within some bounds.
// @param l Short|Int|Long Range lower bound.
// @param u Short|Int|Long Range upper bound.
// @return Longs Range.
.util.range:{[l;u] range0[l;u;1;l+]};

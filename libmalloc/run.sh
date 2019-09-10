#!/bin/bash
export DYLD_LIBRARY_PATH=.
export DYLD_INSERT_LIBRARIES="libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE=1
$@

#usage example : ./run.sh ls
# env DYLD_LIBRARY_PATH='.' DYLD_INSERT_LIBRARIES='libft_malloc.so' DYLD_FORCE_FLAT_NAMESPACE=1

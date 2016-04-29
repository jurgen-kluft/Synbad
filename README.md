# Merkle Tree

To have a more consistent hit of sub-trees being identical in a merkle-tree with changing amount of items is
to align the size up to a power-of-2.

For example: let's start the size of a merkle-tree with 16-bits (65536) and increase to 17, 18 and 19 bits and so on.
Procedure:
- Hash = 256 bits
- S = Max(PowerOf2(C) + 1, 16)
- Sort the hashes by the 
- Push them out over the array of size S
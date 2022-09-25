subset S1 -> +
subset S2 -> -
so we have to find no. of pairs of subsets where S1 - S2 == target
Sol :
S1 - S2 = target;
S1 + S2 = sum(v);
Adding Above Two :
=> **2(S1) = target + sum(v)**
Now we just need to find no. of S1 which satisfies this eq. (keep in mind that wmpty subset sum = 0)
**Not Possible** when **target + sum(v) is odd**
20 -1 7 999 -40 67 2 

### determine if even of odd 
    > if odd : remove the last number (designate it as 'straggler') and keep it for later
odd -> 2 removed

### divide array into pairs of two values
{20 -1} {7 999} {-40 67}

### sort each pair
    > the pairs are then sorted so that the smaller number is on the left and the larger number is on the right
{-1 20} {7 999} {-40 67}

### sort the pair sequence by its larger value
    > recursively
{-1 20} {-40 67} {7 999}

### create a new sequence 'S' and a new sequence 'pend' 
    > the 'S' sequence is created by pulling out the highest value of each pair and inserting it into 'S'.
    > the 'pend' sequence for the smaller values
S   : 20  67 999
pend: -1 -40   7

### 

# CSCI389-hw0 PRASUN
Homework file for CSCI 389

## PART 1

### a)

Number Of Objects | Number Of Iterations | Average MeanTime 
------------------|----------------------|-----------------
2^8(256) | 50000 | 0.229279017421875
2^9(512) | 25000 | 0.23287449335937496
2^10(1024) | 12500 | 0.23677793890624999
2^11(2048)  | 6250 | 0.23699097976562503
2^12(4096) | 3125 | 0.2389033874218749
2^13(8192) | 1562 | 0.23934449852077663
2^14(16384) | 781 | 0.24019167532047755
2^15(32768) | 390 | 0.2423699654603616
2^16(65536) | 195 | 0.24753658791566505
2^17(131072) | 97 | 0.24811910342186994
2^18(262144) | 48 | 0.2461749671300252
2^19(524288) | 24 | 0.24166769933700563
2^20(1048576) | 12 | 0.24533351755142208
2^21(2097152) | 6 | 0.24265032100677486
2^22(4194304) | 3 | 0.24918807522455852
2^23(8388608) | 2 | 0.24776216030120857
2^24(16777216) | 1 | 0.2543278701305389

My strategy was to keep the average mean time constant across several runs as seen in the above table. I did this to see how many iterations I could go upto as I incremented the number of objects by a factor of 2. As it turns out, it seems that if I halved the number of iterations as I scaled the number of objects by a factor of 2, the average mean time remained more or less constant. Also, I started from the benchmark of 50000 iterations for 256(2^8) objects and went down to 1 iteration for 16777216(2^24) objects to keep the running time low which allowed me to compute the median across multiple trials with same parameters to ignore the effect of outliers.

### b) 

I would pick the median across multiple trials for each individual trial to ensure that my result was a good git and representative of all trials. It helped to eradicate the outilers in my data. 

### c)

![Part 1](https://github.com/prg007/CSCI389-hw0/blob/master/Python_part1.png)


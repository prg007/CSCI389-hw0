# CSCI389-hw0 PRASUN
Homework file for CSCI 389 for Prasun. 

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

I would pick the median across multiple trials for each individual trial to ensure that my result was a good fit and representative of all trials. It helped to eradicate the outilers in my data. 

### c)

![Part 1](https://github.com/prg007/CSCI389-hw0/blob/master/Python_part1.png)

## PART 2

The C++ version(**update.cpp**) of update_locations.py was compiled by setting the data type to float. This is done by setting the data_t parameter to 'float' in line 9 of update.cpp. The C++ version gave much better performance as compared to the Python version.  I was able to run more iterations and larger object counts. This means we can compute and tabulate our results over a larger range making our results much more significant. The running time of C++ code and the comparison graph of C++ vs Python has been attached below

Number Of Objects | Number Of Iterations | Average MeanTime 
------------------|----------------------|-----------------
2^8(256) | 50000 | 0.0511211
2^9(512) | 25000 | 0.0490125
2^10(1024) | 12500 | 0.0531766
2^11(2048)  | 6250 | 0.0534398
2^12(4096) | 3125 | 0.0546383
2^13(8192) | 1562 | 0.0546933
2^14(16384) | 781 | 0.0598457
2^15(32768) | 390 | 0.0625282
2^16(65536) | 195 | 0.0585671
2^17(131072) | 97 | 0.059289
2^18(262144) | 48 | 0.0562437
2^19(524288) | 24 | 0.0631404
2^20(1048576) | 12 | 0.0601085
2^21(2097152) | 6 | 0.0612569
2^22(4194304) | 3 | 0.0570711
2^23(8388608) | 2 | 0.062556
2^24(16777216) | 1 | 0.0700629


![Part 2](https://github.com/prg007/CSCI389-hw0/blob/master/part2_C++_vs_Python.png)

## PART3

As mentioned in the question, I ran the 3 trials on average for each of the data types. The results have been attached in the graph below. I found that the performace of **int8** was much better than all other data types. The performance of **int16** was a little better than the performance of **int32** and **float**. The performance of **int32** and **float** were almost comparable to each other. **int64** and **double** on average had the worst performance. Look at the graph below for more information.






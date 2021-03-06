# CSCI389-hw0 PRASUN
Homework file for CSCI 389 for Prasun. 
There are 2 C++ files - update.cpp (This one uses array's)
u.cpp - This one uses vectors. As it turns out using array's improves your performance by a factor of 500 times as compared to Python, whereas using vectors improves your performance by a factor of 50 times(approximately). The graphs in this repository are computed using the vector version u.cpp 

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

The C++ version(**update.cpp**) of update_locations.py was compiled by setting the data type to float. This is done by setting the data_t parameter to 'float' in line 9 of update.cpp. The C++ version gave much better performance(500 times faster as compared to the Python version).  I was able to run more iterations and larger object counts. This means we can compute and tabulate our results over a larger range making our results much more significant. The running time of C++ code and the comparison graph of C++ vs Python has been attached below

Number Of Objects | Number Of Iterations | Average MeanTime 
------------------|----------------------|-----------------
2^8(256) | 50000 | 0.00511211
2^9(512) | 25000 | 0.00490125
2^10(1024) | 12500 | 0.00531766
2^11(2048)  | 6250 | 0.00534398
2^12(4096) | 3125 | 0.00546383
2^13(8192) | 1562 | 0.00546933
2^14(16384) | 781 | 0.00598457
2^15(32768) | 390 | 0.00625282
2^16(65536) | 195 | 0.00585671
2^17(131072) | 97 | 0.0059289
2^18(262144) | 48 | 0.00562437
2^19(524288) | 24 | 0.00631404
2^20(1048576) | 12 | 0.00601085
2^21(2097152) | 6 | 0.00612569
2^22(4194304) | 3 | 0.00570711
2^23(8388608) | 2 | 0.0062556
2^24(16777216) | 1 | 0.00700629


![Part 2](https://github.com/prg007/CSCI389-hw0/blob/master/part2_C++_vs_Python_1.png)

## PART3

As mentioned in the question, I ran the 3 trials on average for each of the data types. The results have been attached in the graph below. I found that the performace of **int8** was much better than all other data types. The performance of **int16** was a little better than the performance of **int32** and **float**. The performance of **int32** and **float** were almost comparable to each other. **int64** and **double** on average had the worst performance. Look at the graph below for more information.

![Part 3](https://github.com/prg007/CSCI389-hw0/blob/master/Comparison_of_C++_Data_Types_2.png)

## PART4

As mentioned in the question I ran `update.cpp` using the following code `/usr/bin/time -lp ./a 1048576 1000` with # of iterations set to **1000** and # of objects set to **2^10**. In order to find the amount of data used read `the maximum resident set size` attribute in the command line. As expected, **double** and **int64** consumed the most amount of memory followed by **float** and **int32** which was followed by **int16**. **int8** consumed the least amount of memory. The results have been tabulated below: 

Data Type | Memory Used 
----------|------------
double | 51171328
float  | 25972736
int64_t |  51142656
int32_t | 25976832
int16_t | 13402112
int8_t | 7114752

As far as memory usage for Python is concerned, I had to use a different approach. I basically followed what was mentioned in this stackoverflow link (https://stackoverflow.com/questions/552744/how-do-i-profile-memory-usage-in-python). It involves installing guppy and using hpy. For the same parameters as above, Python used a memory size of **Total size = 208185467 bytes**. which is 4 times worse than double in C++ and almost 30 times worse than using int8 in C++

<!--
SPDX-License-Identifier: ISC
scspell-id: abe0e313-a0f8-11ed-a28d-80ee73e9b8e7
Copyright (c) 2023 The DPS8M Development Team
-->

# ChaRandom

- ChaCha-based random number generator derived from *OpenBSD*'s `arc4random`(`3`).
- This cryptographic random generator passes **NIST-SP-800-22** (*Rev 1*).

### ent

```
$ test 2147483647 | ent
```
```
Entropy = 8.000000 bits per byte.

Optimum compression would reduce the size
of this 2147483647 byte file by 0 percent.

Chi square distribution for 2147483647 samples is 229.51, and randomly
would exceed this value 87.26 percent of the times.

Arithmetic mean value of data bytes is 127.5008 (127.5 = random).
Monte Carlo value for Pi is 3.141561150 (error 0.00 percent).
Serial correlation coefficient is -0.000005 (totally uncorrelated = 0.0).
```

### dieharder

```
$ test | dieharder -a -g 200 -k 2 -Y 1
```
```
#=====================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown  #
#=====================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.95e+07  |1014457751|
#=====================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=====================================================================#
   diehard_birthdays|   0|       100|     100|0.51248336|  PASSED
      diehard_operm5|   0|   1000000|     100|0.67261855|  PASSED
  diehard_rank_32x32|   0|     40000|     100|0.94089514|  PASSED
    diehard_rank_6x8|   0|    100000|     100|0.48995872|  PASSED
   diehard_bitstream|   0|   2097152|     100|0.03633725|  PASSED
        diehard_opso|   0|   2097152|     100|0.94931554|  PASSED
        diehard_oqso|   0|   2097152|     100|0.33154265|  PASSED
         diehard_dna|   0|   2097152|     100|0.34764845|  PASSED
diehard_count_1s_str|   0|    256000|     100|0.11156129|  PASSED
diehard_count_1s_byt|   0|    256000|     100|0.69246037|  PASSED
 diehard_parking_lot|   0|     12000|     100|0.84067258|  PASSED
    diehard_2dsphere|   2|      8000|     100|0.50919489|  PASSED
    diehard_3dsphere|   3|      4000|     100|0.91373544|  PASSED
     diehard_squeeze|   0|    100000|     100|0.45344869|  PASSED
        diehard_sums|   0|       100|     100|0.01966014|  PASSED
        diehard_runs|   0|    100000|     100|0.66094420|  PASSED
        diehard_runs|   0|    100000|     100|0.31032086|  PASSED
       diehard_craps|   0|    200000|     100|0.57402860|  PASSED
       diehard_craps|   0|    200000|     100|0.08546529|  PASSED
 marsaglia_tsang_gcd|   0|  10000000|     100|0.23603205|  PASSED
 marsaglia_tsang_gcd|   0|  10000000|     100|0.09454913|  PASSED
         sts_monobit|   1|    100000|     100|0.65555314|  PASSED
            sts_runs|   2|    100000|     100|0.33811122|  PASSED
          sts_serial|   1|    100000|     100|0.76338020|  PASSED
          sts_serial|   2|    100000|     100|0.72887441|  PASSED
          sts_serial|   3|    100000|     100|0.93454748|  PASSED
          sts_serial|   3|    100000|     100|0.82501979|  PASSED
          sts_serial|   4|    100000|     100|0.97428942|  PASSED
          sts_serial|   4|    100000|     100|0.99222162|  PASSED
          sts_serial|   5|    100000|     100|0.41948055|  PASSED
          sts_serial|   5|    100000|     100|0.56272790|  PASSED
          sts_serial|   6|    100000|     100|0.66430536|  PASSED
          sts_serial|   6|    100000|     100|0.93862836|  PASSED
          sts_serial|   7|    100000|     100|0.15326919|  PASSED
          sts_serial|   7|    100000|     100|0.08482236|  PASSED
          sts_serial|   8|    100000|     100|0.40597717|  PASSED
          sts_serial|   8|    100000|     100|0.99019873|  PASSED
          sts_serial|   9|    100000|     100|0.29517845|  PASSED
          sts_serial|   9|    100000|     100|0.83714808|  PASSED
          sts_serial|  10|    100000|     100|0.58090875|  PASSED
          sts_serial|  10|    100000|     100|0.01910814|  PASSED
          sts_serial|  11|    100000|     100|0.45032830|  PASSED
          sts_serial|  11|    100000|     100|0.62923231|  PASSED
          sts_serial|  12|    100000|     100|0.25535747|  PASSED
          sts_serial|  12|    100000|     100|0.16200570|  PASSED
          sts_serial|  13|    100000|     100|0.23500364|  PASSED
          sts_serial|  13|    100000|     100|0.00735534|  PASSED
          sts_serial|  14|    100000|     100|0.76012729|  PASSED
          sts_serial|  14|    100000|     100|0.92143138|  PASSED
          sts_serial|  15|    100000|     100|0.97919049|  PASSED
          sts_serial|  15|    100000|     100|0.75871165|  PASSED
          sts_serial|  16|    100000|     100|0.27981115|  PASSED
          sts_serial|  16|    100000|     100|0.41490745|  PASSED
         rgb_bitdist|   1|    100000|     100|0.55324342|  PASSED
         rgb_bitdist|   2|    100000|     100|0.33508221|  PASSED
         rgb_bitdist|   3|    100000|     100|0.28964578|  PASSED
         rgb_bitdist|   4|    100000|     100|0.47998519|  PASSED
         rgb_bitdist|   5|    100000|     100|0.82168974|  PASSED
         rgb_bitdist|   6|    100000|     100|0.35379325|  PASSED
         rgb_bitdist|   7|    100000|     100|0.10225833|  PASSED
         rgb_bitdist|   8|    100000|     100|0.57781865|  PASSED
         rgb_bitdist|   9|    100000|     100|0.31695178|  PASSED
         rgb_bitdist|  10|    100000|     100|0.05834344|  PASSED
         rgb_bitdist|  11|    100000|     100|0.78707837|  PASSED
         rgb_bitdist|  12|    100000|     100|0.85295933|  PASSED
rgb_minimum_distance|   2|     10000|    1000|0.90118511|  PASSED
rgb_minimum_distance|   3|     10000|    1000|0.46508799|  PASSED
rgb_minimum_distance|   4|     10000|    1000|0.86784119|  PASSED
rgb_minimum_distance|   5|     10000|    1000|0.58487761|  PASSED
    rgb_permutations|   2|    100000|     100|0.65455810|  PASSED
    rgb_permutations|   3|    100000|     100|0.38653036|  PASSED
    rgb_permutations|   4|    100000|     100|0.51444918|  PASSED
    rgb_permutations|   5|    100000|     100|0.47494414|  PASSED
      rgb_lagged_sum|   0|   1000000|     100|0.22936723|  PASSED
      rgb_lagged_sum|   1|   1000000|     100|0.96741410|  PASSED
      rgb_lagged_sum|   2|   1000000|     100|0.14242251|  PASSED
      rgb_lagged_sum|   3|   1000000|     100|0.20368119|  PASSED
      rgb_lagged_sum|   4|   1000000|     100|0.47781251|  PASSED
      rgb_lagged_sum|   5|   1000000|     100|0.66553637|  PASSED
      rgb_lagged_sum|   6|   1000000|     100|0.83910345|  PASSED
      rgb_lagged_sum|   7|   1000000|     100|0.65879259|  PASSED
      rgb_lagged_sum|   8|   1000000|     100|0.50260081|  PASSED
      rgb_lagged_sum|   9|   1000000|     100|0.12614775|  PASSED
      rgb_lagged_sum|  10|   1000000|     100|0.11840220|  PASSED
      rgb_lagged_sum|  11|   1000000|     100|0.77631996|  PASSED
      rgb_lagged_sum|  12|   1000000|     100|0.40090026|  PASSED
      rgb_lagged_sum|  13|   1000000|     100|0.86060949|  PASSED
      rgb_lagged_sum|  14|   1000000|     100|0.93131240|  PASSED
      rgb_lagged_sum|  15|   1000000|     100|0.15448380|  PASSED
      rgb_lagged_sum|  16|   1000000|     100|0.90213869|  PASSED
      rgb_lagged_sum|  17|   1000000|     100|0.68550665|  PASSED
      rgb_lagged_sum|  18|   1000000|     100|0.54789920|  PASSED
      rgb_lagged_sum|  19|   1000000|     100|0.87603190|  PASSED
      rgb_lagged_sum|  20|   1000000|     100|0.31283710|  PASSED
      rgb_lagged_sum|  21|   1000000|     100|0.94672224|  PASSED
      rgb_lagged_sum|  22|   1000000|     100|0.45718390|  PASSED
      rgb_lagged_sum|  23|   1000000|     100|0.22714799|  PASSED
      rgb_lagged_sum|  24|   1000000|     100|0.12779276|  PASSED
      rgb_lagged_sum|  25|   1000000|     100|0.52287429|  PASSED
      rgb_lagged_sum|  26|   1000000|     100|0.66948667|  PASSED
      rgb_lagged_sum|  27|   1000000|     100|0.13410870|  PASSED
      rgb_lagged_sum|  28|   1000000|     100|0.34546007|  PASSED
      rgb_lagged_sum|  29|   1000000|     100|0.08647706|  PASSED
      rgb_lagged_sum|  30|   1000000|     100|0.13600786|  PASSED
      rgb_lagged_sum|  31|   1000000|     100|0.26106208|  PASSED
      rgb_lagged_sum|  32|   1000000|     100|0.44510799|  PASSED
     rgb_kstest_test|   0|     10000|    1000|0.29324900|  PASSED
     dab_bytedistrib|   0|  51200000|       1|0.26416824|  PASSED
             dab_dct| 256|     50000|       1|0.04168757|  PASSED
Preparing to run test 207.  ntuple = 0
        dab_filltree|  32|  15000000|       1|0.72507217|  PASSED
        dab_filltree|  32|  15000000|       1|0.25112893|  PASSED
Preparing to run test 208.  ntuple = 0
       dab_filltree2|   0|   5000000|       1|0.39451926|  PASSED
       dab_filltree2|   1|   5000000|       1|0.84234140|  PASSED
Preparing to run test 209.  ntuple = 0
        dab_monobit2|  12|  65000000|       1|0.58132465|  PASSED
```

### PractRand

```
$ test 0 | PractRand_RNG_test stdin -a -te 10
```
```
rng=RNG_stdin, seed=unknown
length= 1 terabyte (2^40 bytes), time= 16512 seconds
  Test Name                    Raw        Processed  Evaluation
  BDayS128(26):all1            R=  -0.9   p~= 0.8    normal
  BDayS128(26):all2            R=  -0.6   p~= 0.7    normal
  [Low1/8]BDayS128(26):all1    R=  +1.1   p~= 0.1    normal
  [Low1/8]BDayS128(26):all2    R=  +0.1   p~= 0.5    normal
  [Low4/32]BDayS128(26):all1   R=  -0.3   p~= 0.6    normal
  [Low4/32]BDayS128(26):all2   R=  +0.2   p~= 0.4    normal
  [Low1/32]BDayS128(26):all1   R=  +0.5   p~= 0.3    normal
  [Low1/32]BDayS128(26):all2   R=  +0.9   p~= 0.2    normal
```

```
$ test 0 | PractRand_RNG_test stdin -a
```
```
rng=RNG_stdin, seed=unknown
length= 2 terabytes (2^41 bytes), time= 23760 seconds
  Test Name                         Raw       Processed     Evaluation
  BCFN(2+0,13-0,T)                  R=  -1.9  p = 0.778     normal
  BCFN(2+1,13-0,T)                  R=  -0.8  p = 0.626     normal
  BCFN(2+2,13-0,T)                  R=  -3.6  p = 0.930     normal
  BCFN(2+3,13-0,T)                  R=  +2.6  p = 0.140     normal
  BCFN(2+4,13-0,T)                  R=  -1.1  p = 0.675     normal
  BCFN(2+5,13-0,T)                  R=  -1.9  p = 0.784     normal
  BCFN(2+6,13-0,T)                  R=  -1.4  p = 0.716     normal
  BCFN(2+7,13-0,T)                  R=  +1.6  p = 0.253     normal
  BCFN(2+8,13-0,T)                  R=  +0.1  p = 0.485     normal
  BCFN(2+9,13-0,T)                  R=  -3.1  p = 0.898     normal
  BCFN(2+10,13-0,T)                 R=  +1.3  p = 0.290     normal
  BCFN(2+11,13-0,T)                 R=  +0.9  p = 0.351     normal
  BCFN(2+12,13-0,T)                 R=  +0.2  p = 0.457     normal
  BCFN(2+13,13-1,T)                 R=  +0.1  p = 0.476     normal
  BCFN(2+14,13-1,T)                 R=  +2.4  p = 0.167     normal
  BCFN(2+15,13-2,T)                 R=  -1.9  p = 0.783     normal
  BCFN(2+16,13-3,T)                 R=  -2.1  p = 0.799     normal
  BCFN(2+17,13-3,T)                 R=  -0.1  p = 0.500     normal
  BCFN(2+18,13-4,T)                 R=  +0.3  p = 0.428     normal
  BCFN(2+19,13-5,T)                 R=  -0.3  p = 0.523     normal
  BCFN(2+20,13-5,T)                 R=  +1.8  p = 0.215     normal
  BCFN(2+21,13-6,T)                 R=  +0.1  p = 0.444     normal
  BCFN(2+22,13-6,T)                 R=  +2.3  p = 0.166     normal
  BCFN(2+23,13-7,T)                 R=  -2.0  p = 0.799     normal
  BCFN(2+24,13-8,T)                 R=  +1.3  p = 0.245     normal
  BCFN(2+25,13-8,T)                 R=  +0.2  p = 0.394     normal
  BCFN(2+26,13-9,T)                 R=  +5.9  p = 0.021     normal
  BCFN(2+27,13-9,T)                 R=  -2.0  p = 0.838     normal
  DC6-9x1Bytes-1                    R=  -0.4  p = 0.612     normal
  Gap-16:A                          R=  -1.1  p = 0.835     normal
  Gap-16:B                          R=  -1.5  p = 0.851     normal
  FPF-14+6/16:(0,14-0)              R=  -0.1  p = 0.532     normal
  FPF-14+6/16:(1,14-0)              R=  +1.3  p = 0.188     normal
  FPF-14+6/16:(2,14-0)              R=  -0.4  p = 0.604     normal
  FPF-14+6/16:(3,14-0)              R=  -1.7  p = 0.888     normal
  FPF-14+6/16:(4,14-0)              R=  -2.5  p = 0.962     normal
  FPF-14+6/16:(5,14-0)              R=  +0.7  p = 0.307     normal
  FPF-14+6/16:(6,14-0)              R=  +1.4  p = 0.163     normal
  FPF-14+6/16:(7,14-0)              R=  +2.3  p = 0.057     normal
  FPF-14+6/16:(8,14-0)              R=  +0.5  p = 0.373     normal
  FPF-14+6/16:(9,14-0)              R=  +0.1  p = 0.468     normal
  FPF-14+6/16:(10,14-0)             R=  -1.3  p = 0.824     normal
  FPF-14+6/16:(11,14-0)             R=  -0.3  p = 0.577     normal
  FPF-14+6/16:(12,14-0)             R=  -1.2  p = 0.802     normal
  FPF-14+6/16:(13,14-0)             R=  +1.9  p = 0.088     normal
  FPF-14+6/16:(14,14-0)             R=  -0.8  p = 0.710     normal
  FPF-14+6/16:(15,14-0)             R=  +0.9  p = 0.254     normal
  FPF-14+6/16:(16,14-0)             R=  -0.4  p = 0.621     normal
  FPF-14+6/16:(17,14-1)             R=  +1.1  p = 0.222     normal
  FPF-14+6/16:(18,14-2)             R=  +0.2  p = 0.458     normal
  FPF-14+6/16:(19,14-2)             R=  +0.3  p = 0.411     normal
  FPF-14+6/16:(20,14-3)             R=  -2.4  p = 0.958     normal
  FPF-14+6/16:(21,14-4)             R=  +0.5  p = 0.376     normal
  FPF-14+6/16:(22,14-5)             R=  -1.3  p = 0.815     normal
  FPF-14+6/16:(23,14-5)             R=  -1.9  p = 0.913     normal
  FPF-14+6/16:(24,14-6)             R=  +1.7  p = 0.117     normal
  FPF-14+6/16:(25,14-7)             R=  -0.3  p = 0.558     normal
  FPF-14+6/16:(26,14-8)             R=  -0.3  p = 0.573     normal
  FPF-14+6/16:(27,14-8)             R=  -0.1  p = 0.508     normal
  FPF-14+6/16:(28,14-9)             R=  +3.0  p = 0.030     normal
  FPF-14+6/16:(29,14-10)            R=  +1.1  p = 0.197     normal
  FPF-14+6/16:(30,14-11)            R=  +0.8  p = 0.237     normal
  FPF-14+6/16:(31,14-11)            R=  +0.2  p = 0.388     normal
  FPF-14+6/16:all                   R=  +0.1  p = 0.483     normal
  FPF-14+6/16:cross                 R=  +0.3  p = 0.364     normal
  BRank(12):128(16)                 R=  -0.3  p~= 0.570     normal
  BRank(12):256(16)                 R=  -0.4  p~= 0.580     normal
  BRank(12):384(4)                  R=  -0.8  p~= 0.670     normal
  BRank(12):512(8)                  R=  +1.2  p~= 0.107     normal
  BRank(12):768(4)                  R=  +1.7  p~= 0.060     normal
  BRank(12):1K(8)                   R=  +0.2  p~= 0.360     normal
  BRank(12):1536(2)                 R=  -0.2  p~= 0.554     normal
  BRank(12):2K(4)                   R=  -0.8  p~= 0.670     normal
  BRank(12):3K(2)                   R=  -0.2  p~= 0.554     normal
  BRank(12):4K(4)                   R=  +1.7  p~= 0.060     normal
  BRank(12):6K(1)                   R=  -0.7  p~= 0.689     normal
  BRank(12):8K(2)                   R=  +1.6  p~= 0.168     normal
  BRank(12):12K(1)                  R=  -0.7  p~= 0.689     normal
  BRank(12):16K(2)                  R=  +1.6  p~= 0.168     normal
  BRank(12):24K(1)                  R=  +1.8  p~= 0.146     normal
  BRank(12):32K(1)                  R=  +1.8  p~= 0.146     normal
  mod3n(5):(0,9-6)                  R=  -0.6  p = 0.577     normal
  mod3n(5):(1,9-6)                  R=  -0.9  p = 0.655     normal
  mod3n(5):(2,9-6)                  R=  -1.6  p = 0.806     normal
  mod3n(5):(3,9-6)                  R=  -0.6  p = 0.577     normal
  mod3n(5):(4,9-6)                  R=  -0.0  p = 0.447     normal
  mod3n(5):(5,9-6)                  R=  +1.9  p = 0.152     normal
  mod3n(5):(6,9-6)                  R=  -1.8  p = 0.834     normal
  mod3n(5):(7,9-6)                  R=  -2.3  p = 0.913     normal
  mod3n(5):(8,9-6)                  R=  -0.1  p = 0.468     normal
  mod3n(5):(9,9-6)                  R=  -1.1  p = 0.692     normal
  mod3n(5):(10,9-6)                 R=  -2.5  p = 0.940     normal
  mod3n(5):(11,9-6)                 R=  -1.3  p = 0.729     normal
  mod3n(5):(12,9-6)                 R=  +1.7  p = 0.171     normal
  mod3n(5):(13,9-6)                 R=  -2.2  p = 0.910     normal
  mod3n(5):(14,9-6)                 R=  +1.4  p = 0.210     normal
  mod3n(5):(15,9-6)                 R=  +1.4  p = 0.207     normal
  TMFn(2+0):wl                      R=  +0.7  p~= 0.4       normal
  TMFn(2+1):wl                      R=  +1.6  p~= 0.3       normal
  TMFn(2+2):wl                      R=  +1.6  p~= 0.3       normal
  TMFn(2+3):wl                      R=  +0.3  p~= 0.5       normal
  TMFn(2+4):wl                      R=  -0.3  p~= 0.6       normal
  TMFn(2+5):wl                      R=  +0.3  p~= 0.4       normal
  TMFn(2+6):wl                      R=  +0.6  p~= 0.4       normal
  TMFn(2+7):wl                      R=  +1.1  p~= 0.3       normal
  TMFn(2+8):wl                      R=  +2.2  p~= 0.2       normal
  TMFn(2+9):wl                      R=  +0.6  p~= 0.4       normal
  TMFn(2+10):wl                     R=  +1.2  p~= 0.3       normal
  TMFn(2+11):wl                     R=  +1.9  p~= 0.3       normal
  TMFn(2+12):wl                     R=  +2.1  p~= 0.2       normal
  TMFn(2+13):wl                     R=  +2.1  p~= 0.2       normal
  [Low1/8]BCFN(2+0,13-0,T)          R=  +0.0  p = 0.494     normal
  [Low1/8]BCFN(2+1,13-0,T)          R=  +0.1  p = 0.482     normal
  [Low1/8]BCFN(2+2,13-0,T)          R=  +2.9  p = 0.117     normal
  [Low1/8]BCFN(2+3,13-0,T)          R=  -2.8  p = 0.877     normal
  [Low1/8]BCFN(2+4,13-0,T)          R=  -0.8  p = 0.626     normal
  [Low1/8]BCFN(2+5,13-0,T)          R=  +3.5  p = 0.081     normal
  [Low1/8]BCFN(2+6,13-0,T)          R=  +0.1  p = 0.479     normal
  [Low1/8]BCFN(2+7,13-0,T)          R=  -5.5  p = 0.988     normal
  [Low1/8]BCFN(2+8,13-0,T)          R=  -4.8  p = 0.977     normal
  [Low1/8]BCFN(2+9,13-0,T)          R=  -0.1  p = 0.520     normal
  [Low1/8]BCFN(2+10,13-1,T)         R=  -1.7  p = 0.756     normal
  [Low1/8]BCFN(2+11,13-1,T)         R=  +0.1  p = 0.473     normal
  [Low1/8]BCFN(2+12,13-2,T)         R=  +1.4  p = 0.278     normal
  [Low1/8]BCFN(2+13,13-3,T)         R=  -4.1  p = 0.959     normal
  [Low1/8]BCFN(2+14,13-3,T)         R=  +2.2  p = 0.187     normal
  [Low1/8]BCFN(2+15,13-4,T)         R=  +0.7  p = 0.363     normal
  [Low1/8]BCFN(2+16,13-5,T)         R=  -1.4  p = 0.710     normal
  [Low1/8]BCFN(2+17,13-5,T)         R=  -0.0  p = 0.477     normal
  [Low1/8]BCFN(2+18,13-6,T)         R=  -1.8  p = 0.757     normal
  [Low1/8]BCFN(2+19,13-6,T)         R=  -3.8  p = 0.965     normal
  [Low1/8]BCFN(2+20,13-7,T)         R=  +1.8  p = 0.207     normal
  [Low1/8]BCFN(2+21,13-8,T)         R=  +0.6  p = 0.330     normal
  [Low1/8]BCFN(2+22,13-8,T)         R=  +0.8  p = 0.315     normal
  [Low1/8]BCFN(2+23,13-9,T)         R=  -1.3  p = 0.676     normal
  [Low1/8]BCFN(2+24,13-9,T)         R=  -1.0  p = 0.628     normal
  [Low1/8]DC6-9x1Bytes-1            R=  +2.8  p = 0.076     normal
  [Low1/8]Gap-16:A                  R=  +1.4  p = 0.211     normal
  [Low1/8]Gap-16:B                  R=  -1.1  p = 0.772     normal
  [Low1/8]FPF-14+6/16:(0,14-0)      R=  -0.3  p = 0.588     normal
  [Low1/8]FPF-14+6/16:(1,14-0)      R=  -0.3  p = 0.591     normal
  [Low1/8]FPF-14+6/16:(2,14-0)      R=  +1.8  p = 0.104     normal
  [Low1/8]FPF-14+6/16:(3,14-0)      R=  -2.3  p = 0.948     normal
  [Low1/8]FPF-14+6/16:(4,14-0)      R=  +0.5  p = 0.352     normal
  [Low1/8]FPF-14+6/16:(5,14-0)      R=  -0.8  p = 0.703     normal
  [Low1/8]FPF-14+6/16:(6,14-0)      R=  -0.2  p = 0.547     normal
  [Low1/8]FPF-14+6/16:(7,14-0)      R=  +2.1  p = 0.067     normal
  [Low1/8]FPF-14+6/16:(8,14-0)      R=  -0.5  p = 0.641     normal
  [Low1/8]FPF-14+6/16:(9,14-0)      R=  +0.1  p = 0.471     normal
  [Low1/8]FPF-14+6/16:(10,14-0)     R=  +2.2  p = 0.065     normal
  [Low1/8]FPF-14+6/16:(11,14-0)     R=  -0.0  p = 0.509     normal
  [Low1/8]FPF-14+6/16:(12,14-0)     R=  -0.3  p = 0.597     normal
  [Low1/8]FPF-14+6/16:(13,14-0)     R=  +2.1  p = 0.074     normal
  [Low1/8]FPF-14+6/16:(14,14-1)     R=  -0.3  p = 0.584     normal
  [Low1/8]FPF-14+6/16:(15,14-2)     R=  +1.6  p = 0.137     normal
  [Low1/8]FPF-14+6/16:(16,14-2)     R=  -0.4  p = 0.607     normal
  [Low1/8]FPF-14+6/16:(17,14-3)     R=  -1.0  p = 0.755     normal
  [Low1/8]FPF-14+6/16:(18,14-4)     R=  +0.2  p = 0.437     normal
  [Low1/8]FPF-14+6/16:(19,14-5)     R=  -0.6  p = 0.664     normal
  [Low1/8]FPF-14+6/16:(20,14-5)     R=  -0.6  p = 0.666     normal
  [Low1/8]FPF-14+6/16:(21,14-6)     R=  +1.0  p = 0.242     normal
  [Low1/8]FPF-14+6/16:(22,14-7)     R=  +0.5  p = 0.346     normal
  [Low1/8]FPF-14+6/16:(23,14-8)     R=  -0.9  p = 0.723     normal
  [Low1/8]FPF-14+6/16:(24,14-8)     R=  +0.8  p = 0.273     normal
  [Low1/8]FPF-14+6/16:(25,14-9)     R=  +0.3  p = 0.392     normal
  [Low1/8]FPF-14+6/16:(26,14-10)    R=  +0.0  p = 0.440     normal
  [Low1/8]FPF-14+6/16:(27,14-11)    R=  -0.2  p = 0.498     normal
  [Low1/8]FPF-14+6/16:(28,14-11)    R=  +2.2  p = 0.078     normal
  [Low1/8]FPF-14+6/16:all           R=  +1.1  p = 0.232     normal
  [Low1/8]FPF-14+6/16:cross         R=  -0.0  p = 0.470     normal
  [Low1/8]BRank(12):128(16)         R=  +0.6  p~= 0.240     normal
  [Low1/8]BRank(12):256(8)          R=  -0.3  p~= 0.500     normal
  [Low1/8]BRank(12):384(4)          R=  -0.2  p~= 0.500     normal
  [Low1/8]BRank(12):512(8)          R=  -1.1  p~= 0.860     normal
  [Low1/8]BRank(12):768(2)          R=  -1.0  p~= 0.744     normal
  [Low1/8]BRank(12):1K(4)           R=  -0.2  p~= 0.500     normal
  [Low1/8]BRank(12):1536(2)         R=  +1.6  p~= 0.168     normal
  [Low1/8]BRank(12):2K(4)           R=  +0.4  p~= 0.340     normal
  [Low1/8]BRank(12):3K(1)           R=  -0.7  p~= 0.689     normal
  [Low1/8]BRank(12):4K(2)           R=  -1.0  p~= 0.744     normal
  [Low1/8]BRank(12):6K(1)           R=  -0.7  p~= 0.689     normal
  [Low1/8]BRank(12):8K(2)           R=  +0.8  p~= 0.293     normal
  [Low1/8]BRank(12):12K(1)          R=  -0.7  p~= 0.689     normal
  [Low1/8]BRank(12):16K(1)          R=  +0.4  p~= 0.366     normal
  [Low1/8]mod3n(5):(0,9-6)          R=  +2.2  p = 0.125     normal
  [Low1/8]mod3n(5):(1,9-6)          R=  +2.1  p = 0.131     normal
  [Low1/8]mod3n(5):(2,9-6)          R=  -2.2  p = 0.912     normal
  [Low1/8]mod3n(5):(3,9-6)          R=  -2.6  p = 0.956     normal
  [Low1/8]mod3n(5):(4,9-6)          R=  +0.3  p = 0.379     normal
  [Low1/8]mod3n(5):(5,9-6)          R=  +1.1  p = 0.248     normal
  [Low1/8]mod3n(5):(6,9-6)          R=  -1.0  p = 0.674     normal
  [Low1/8]mod3n(5):(7,9-6)          R=  +1.2  p = 0.233     normal
  [Low1/8]mod3n(5):(8,9-6)          R=  +1.4  p = 0.200     normal
  [Low1/8]mod3n(5):(9,9-6)          R=  -2.1  p = 0.886     normal
  [Low1/8]mod3n(5):(10,9-6)         R=  -0.8  p = 0.631     normal
  [Low1/8]mod3n(5):(11,9-6)         R=  -1.6  p = 0.810     normal
  [Low1/8]mod3n(5):(12,9-6)         R=  -2.7  p = 0.963     normal
  [Low1/8]mod3n(5):(13,9-6)         R=  -0.7  p = 0.608     normal
  [Low1/8]mod3n(5):(14,9-6)         R=  -0.2  p = 0.494     normal
  [Low1/8]mod3n(5):(15,9-6)         R=  -0.1  p = 0.471     normal
  [Low1/8]TMFn(2+0):wl              R=  +0.5  p~= 0.4       normal
  [Low1/8]TMFn(2+1):wl              R=  -0.6  p~= 0.6       normal
  [Low1/8]TMFn(2+2):wl              R=  -0.7  p~= 0.6       normal
  [Low1/8]TMFn(2+3):wl              R=  -0.8  p~= 0.6       normal
  [Low1/8]TMFn(2+4):wl              R=  +1.2  p~= 0.3       normal
  [Low1/8]TMFn(2+5):wl              R=  +0.2  p~= 0.5       normal
  [Low1/8]TMFn(2+6):wl              R=  +0.2  p~= 0.5       normal
  [Low1/8]TMFn(2+7):wl              R=  -0.6  p~= 0.6       normal
  [Low1/8]TMFn(2+8):wl              R=  +1.5  p~= 0.3       normal
  [Low1/8]TMFn(2+9):wl              R=  -1.5  p~= 0.7       normal
  [Low1/8]TMFn(2+10):wl             R=  -0.2  p~= 0.5       normal
  [Low1/8]TMFn(2+11):wl             R=  +2.0  p~= 0.3       normal
  [Low1/8]TMFn(2+12):wl             R=  +1.1  p~= 0.3       normal
  [Low1/8]TMFn(2+13):wl             R=  +0.0  p~= 0.5       normal
  [Low4/32]BCFN(2+0,13-0,T)         R=  -0.9  p = 0.641     normal
  [Low4/32]BCFN(2+1,13-0,T)         R=  +4.6  p = 0.032     normal
  [Low4/32]BCFN(2+2,13-0,T)         R=  +0.5  p = 0.408     normal
  [Low4/32]BCFN(2+3,13-0,T)         R=  -2.5  p = 0.851     normal
  [Low4/32]BCFN(2+4,13-0,T)         R=  +2.0  p = 0.200     normal
  [Low4/32]BCFN(2+5,13-0,T)         R=  -1.9  p = 0.777     normal
  [Low4/32]BCFN(2+6,13-0,T)         R=  +7.3  p =  2.0e-3   normal
  [Low4/32]BCFN(2+7,13-0,T)         R=  -1.2  p = 0.692     normal
  [Low4/32]BCFN(2+8,13-0,T)         R=  +1.8  p = 0.228     normal
  [Low4/32]BCFN(2+9,13-0,T)         R=  +1.2  p = 0.317     normal
  [Low4/32]BCFN(2+10,13-1,T)        R=  +1.6  p = 0.248     normal
  [Low4/32]BCFN(2+11,13-1,T)        R=  +4.9  p = 0.026     normal
  [Low4/32]BCFN(2+12,13-2,T)        R=  -5.1  p = 0.985     normal
  [Low4/32]BCFN(2+13,13-3,T)        R=  +2.6  p = 0.141     normal
  [Low4/32]BCFN(2+14,13-3,T)        R=  -6.6  p =1-1.4e-3   normal
  [Low4/32]BCFN(2+15,13-4,T)        R=  +1.5  p = 0.260     normal
  [Low4/32]BCFN(2+16,13-5,T)        R=  +3.4  p = 0.088     normal
  [Low4/32]BCFN(2+17,13-5,T)        R=  -2.5  p = 0.858     normal
  [Low4/32]BCFN(2+18,13-6,T)        R=  -2.2  p = 0.826     normal
  [Low4/32]BCFN(2+19,13-6,T)        R=  +3.4  p = 0.087     normal
  [Low4/32]BCFN(2+20,13-7,T)        R=  +4.4  p = 0.049     normal
  [Low4/32]BCFN(2+21,13-8,T)        R=  -0.7  p = 0.557     normal
  [Low4/32]BCFN(2+22,13-8,T)        R=  -0.1  p = 0.448     normal
  [Low4/32]BCFN(2+23,13-9,T)        R=  -0.4  p = 0.499     normal
  [Low4/32]BCFN(2+24,13-9,T)        R=  -1.4  p = 0.705     normal
  [Low4/32]DC6-9x1Bytes-1           R=  +2.7  p = 0.089     normal
  [Low4/32]Gap-16:A                 R=  -1.6  p = 0.905     normal
  [Low4/32]Gap-16:B                 R=  -0.4  p = 0.596     normal
  [Low4/32]FPF-14+6/16:(0,14-0)     R=  +2.1  p = 0.070     normal
  [Low4/32]FPF-14+6/16:(1,14-0)     R=  +1.0  p = 0.236     normal
  [Low4/32]FPF-14+6/16:(2,14-0)     R=  -0.1  p = 0.533     normal
  [Low4/32]FPF-14+6/16:(3,14-0)     R=  -0.4  p = 0.614     normal
  [Low4/32]FPF-14+6/16:(4,14-0)     R=  -2.3  p = 0.948     normal
  [Low4/32]FPF-14+6/16:(5,14-0)     R=  +2.8  p = 0.024     normal
  [Low4/32]FPF-14+6/16:(6,14-0)     R=  -1.3  p = 0.827     normal
  [Low4/32]FPF-14+6/16:(7,14-0)     R=  +2.8  p = 0.027     normal
  [Low4/32]FPF-14+6/16:(8,14-0)     R=  +2.4  p = 0.050     normal
  [Low4/32]FPF-14+6/16:(9,14-0)     R=  -1.4  p = 0.834     normal
  [Low4/32]FPF-14+6/16:(10,14-0)    R=  -1.5  p = 0.855     normal
  [Low4/32]FPF-14+6/16:(11,14-0)    R=  -1.1  p = 0.775     normal
  [Low4/32]FPF-14+6/16:(12,14-0)    R=  +0.4  p = 0.389     normal
  [Low4/32]FPF-14+6/16:(13,14-0)    R=  +1.5  p = 0.150     normal
  [Low4/32]FPF-14+6/16:(14,14-1)    R=  -0.5  p = 0.635     normal
  [Low4/32]FPF-14+6/16:(15,14-2)    R=  +1.5  p = 0.145     normal
  [Low4/32]FPF-14+6/16:(16,14-2)    R=  -0.4  p = 0.624     normal
  [Low4/32]FPF-14+6/16:(17,14-3)    R=  -0.3  p = 0.578     normal
  [Low4/32]FPF-14+6/16:(18,14-4)    R=  +1.1  p = 0.226     normal
  [Low4/32]FPF-14+6/16:(19,14-5)    R=  +1.3  p = 0.177     normal
  [Low4/32]FPF-14+6/16:(20,14-5)    R=  +0.4  p = 0.378     normal
  [Low4/32]FPF-14+6/16:(21,14-6)    R=  -0.6  p = 0.665     normal
  [Low4/32]FPF-14+6/16:(22,14-7)    R=  -0.9  p = 0.732     normal
  [Low4/32]FPF-14+6/16:(23,14-8)    R=  -0.1  p = 0.511     normal
  [Low4/32]FPF-14+6/16:(24,14-8)    R=  +0.1  p = 0.459     normal
  [Low4/32]FPF-14+6/16:(25,14-9)    R=  -0.3  p = 0.542     normal
  [Low4/32]FPF-14+6/16:(26,14-10)   R=  -0.0  p = 0.466     normal
  [Low4/32]FPF-14+6/16:(27,14-11)   R=  -0.7  p = 0.653     normal
  [Low4/32]FPF-14+6/16:(28,14-11)   R=  -1.3  p = 0.844     normal
  [Low4/32]FPF-14+6/16:all          R=  +1.3  p = 0.189     normal
  [Low4/32]FPF-14+6/16:cross        R=  -0.6  p = 0.717     normal
  [Low4/32]BRank(12):128(16)        R=  -0.4  p~= 0.580     normal
  [Low4/32]BRank(12):256(8)         R=  +1.4  p~= 0.100     normal
  [Low4/32]BRank(12):384(4)         R=  -0.2  p~= 0.500     normal
  [Low4/32]BRank(12):512(8)         R=  +1.1  p~= 0.120     normal
  [Low4/32]BRank(12):768(2)         R=  -1.0  p~= 0.744     normal
  [Low4/32]BRank(12):1K(4)          R=  -0.8  p~= 0.670     normal
  [Low4/32]BRank(12):1536(2)        R=  +0.6  p~= 0.322     normal
  [Low4/32]BRank(12):2K(4)          R=  +2.5  p~= 0.020     normal
  [Low4/32]BRank(12):3K(1)          R=  -0.7  p~= 0.689     normal
  [Low4/32]BRank(12):4K(2)          R=  -1.0  p~= 0.744     normal
  [Low4/32]BRank(12):6K(1)          R=  +1.8  p~= 0.146     normal
  [Low4/32]BRank(12):8K(2)          R=  +0.8  p~= 0.293     normal
  [Low4/32]BRank(12):12K(1)         R=  +1.8  p~= 0.146     normal
  [Low4/32]BRank(12):16K(1)         R=  -0.7  p~= 0.689     normal
  [Low4/32]mod3n(5):(0,9-6)         R=  +0.1  p = 0.417     normal
  [Low4/32]mod3n(5):(1,9-6)         R=  +4.7  p = 0.020     normal
  [Low4/32]mod3n(5):(2,9-6)         R=  +0.4  p = 0.366     normal
  [Low4/32]mod3n(5):(3,9-6)         R=  +1.9  p = 0.149     normal
  [Low4/32]mod3n(5):(4,9-6)         R=  -3.4  p =1-6.1e-3   normal
  [Low4/32]mod3n(5):(5,9-6)         R=  -1.5  p = 0.783     normal
  [Low4/32]mod3n(5):(6,9-6)         R=  -1.8  p = 0.849     normal
  [Low4/32]mod3n(5):(7,9-6)         R=  +2.0  p = 0.143     normal
  [Low4/32]mod3n(5):(8,9-6)         R=  +2.0  p = 0.139     normal
  [Low4/32]mod3n(5):(9,9-6)         R=  +0.2  p = 0.397     normal
  [Low4/32]mod3n(5):(10,9-6)        R=  -0.6  p = 0.571     normal
  [Low4/32]mod3n(5):(11,9-6)        R=  +1.4  p = 0.200     normal
  [Low4/32]mod3n(5):(12,9-6)        R=  -0.3  p = 0.515     normal
  [Low4/32]mod3n(5):(13,9-6)        R=  -0.2  p = 0.484     normal
  [Low4/32]mod3n(5):(14,9-6)        R=  -1.4  p = 0.762     normal
  [Low4/32]mod3n(5):(15,9-6)        R=  -0.8  p = 0.633     normal
  [Low4/32]TMFn(2+0):wl             R=  -0.9  p~= 0.6       normal
  [Low4/32]TMFn(2+1):wl             R=  +0.8  p~= 0.4       normal
  [Low4/32]TMFn(2+2):wl             R=  +1.2  p~= 0.3       normal
  [Low4/32]TMFn(2+3):wl             R=  +0.7  p~= 0.4       normal
  [Low4/32]TMFn(2+4):wl             R=  -0.6  p~= 0.6       normal
  [Low4/32]TMFn(2+5):wl             R=  +0.3  p~= 0.5       normal
  [Low4/32]TMFn(2+6):wl             R=  +0.6  p~= 0.4       normal
  [Low4/32]TMFn(2+7):wl             R=  +2.7  p~= 0.2       normal
  [Low4/32]TMFn(2+8):wl             R=  +2.4  p~= 0.2       normal
  [Low4/32]TMFn(2+9):wl             R=  +0.2  p~= 0.5       normal
  [Low4/32]TMFn(2+10):wl            R=  +2.8  p~= 0.2       normal
  [Low4/32]TMFn(2+11):wl            R=  +0.7  p~= 0.4       normal
  [Low4/32]TMFn(2+12):wl            R=  +0.2  p~= 0.5       normal
  [Low4/32]TMFn(2+13):wl            R=  +1.2  p~= 0.3       normal
  [Low1/32]BCFN(2+0,13-0,T)         R=  +0.5  p = 0.422     normal
  [Low1/32]BCFN(2+1,13-0,T)         R=  -2.2  p = 0.817     normal
  [Low1/32]BCFN(2+2,13-0,T)         R=  +1.8  p = 0.231     normal
  [Low1/32]BCFN(2+3,13-0,T)         R=  -4.5  p = 0.969     normal
  [Low1/32]BCFN(2+4,13-0,T)         R=  -0.5  p = 0.575     normal
  [Low1/32]BCFN(2+5,13-0,T)         R=  +4.2  p = 0.047     normal
  [Low1/32]BCFN(2+6,13-0,T)         R=  +1.6  p = 0.260     normal
  [Low1/32]BCFN(2+7,13-0,T)         R=  +0.2  p = 0.470     normal
  [Low1/32]BCFN(2+8,13-1,T)         R=  -1.3  p = 0.702     normal
  [Low1/32]BCFN(2+9,13-1,T)         R=  +1.8  p = 0.229     normal
  [Low1/32]BCFN(2+10,13-2,T)        R=  +6.8  p =  4.4e-3   normal
  [Low1/32]BCFN(2+11,13-3,T)        R=  -1.4  p = 0.710     normal
  [Low1/32]BCFN(2+12,13-3,T)        R=  -0.3  p = 0.528     normal
  [Low1/32]BCFN(2+13,13-4,T)        R=  -2.1  p = 0.809     normal
  [Low1/32]BCFN(2+14,13-5,T)        R=  +1.0  p = 0.319     normal
  [Low1/32]BCFN(2+15,13-5,T)        R=  -2.7  p = 0.874     normal
  [Low1/32]BCFN(2+16,13-6,T)        R=  -3.3  p = 0.935     normal
  [Low1/32]BCFN(2+17,13-6,T)        R=  -1.5  p = 0.711     normal
  [Low1/32]BCFN(2+18,13-7,T)        R=  -2.2  p = 0.827     normal
  [Low1/32]BCFN(2+19,13-8,T)        R=  +3.3  p = 0.089     normal
  [Low1/32]BCFN(2+20,13-8,T)        R=  +2.7  p = 0.124     normal
  [Low1/32]BCFN(2+21,13-9,T)        R=  +3.0  p = 0.097     normal
  [Low1/32]BCFN(2+22,13-9,T)        R=  -2.5  p = 0.931     normal
  [Low1/32]DC6-9x1Bytes-1           R=  -0.4  p = 0.633     normal
  [Low1/32]Gap-16:A                 R=  +1.3  p = 0.247     normal
  [Low1/32]Gap-16:B                 R=  +1.2  p = 0.188     normal
  [Low1/32]FPF-14+6/16:(0,14-0)     R=  -0.4  p = 0.604     normal
  [Low1/32]FPF-14+6/16:(1,14-0)     R=  +0.0  p = 0.499     normal
  [Low1/32]FPF-14+6/16:(2,14-0)     R=  +1.3  p = 0.187     normal
  [Low1/32]FPF-14+6/16:(3,14-0)     R=  -2.0  p = 0.919     normal
  [Low1/32]FPF-14+6/16:(4,14-0)     R=  +1.9  p = 0.092     normal
  [Low1/32]FPF-14+6/16:(5,14-0)     R=  -0.4  p = 0.621     normal
  [Low1/32]FPF-14+6/16:(6,14-0)     R=  -0.3  p = 0.587     normal
  [Low1/32]FPF-14+6/16:(7,14-0)     R=  +0.5  p = 0.360     normal
  [Low1/32]FPF-14+6/16:(8,14-0)     R=  +0.5  p = 0.376     normal
  [Low1/32]FPF-14+6/16:(9,14-0)     R=  -1.2  p = 0.811     normal
  [Low1/32]FPF-14+6/16:(10,14-0)    R=  -0.3  p = 0.598     normal
  [Low1/32]FPF-14+6/16:(11,14-0)    R=  +0.8  p = 0.285     normal
  [Low1/32]FPF-14+6/16:(12,14-1)    R=  +0.2  p = 0.444     normal
  [Low1/32]FPF-14+6/16:(13,14-2)    R=  +0.2  p = 0.445     normal
  [Low1/32]FPF-14+6/16:(14,14-2)    R=  -3.0  p = 0.984     normal
  [Low1/32]FPF-14+6/16:(15,14-3)    R=  +0.5  p = 0.372     normal
  [Low1/32]FPF-14+6/16:(16,14-4)    R=  +0.7  p = 0.303     normal
  [Low1/32]FPF-14+6/16:(17,14-5)    R=  +3.3  p = 0.014     normal
  [Low1/32]FPF-14+6/16:(18,14-5)    R=  +0.2  p = 0.435     normal
  [Low1/32]FPF-14+6/16:(19,14-6)    R=  +1.2  p = 0.205     normal
  [Low1/32]FPF-14+6/16:(20,14-7)    R=  -1.6  p = 0.871     normal
  [Low1/32]FPF-14+6/16:(21,14-8)    R=  +0.1  p = 0.438     normal
  [Low1/32]FPF-14+6/16:(22,14-8)    R=  +3.3  p = 0.018     normal
  [Low1/32]FPF-14+6/16:(23,14-9)    R=  -1.3  p = 0.812     normal
  [Low1/32]FPF-14+6/16:(24,14-10)   R=  +0.9  p = 0.244     normal
  [Low1/32]FPF-14+6/16:(25,14-11)   R=  -0.8  p = 0.691     normal
  [Low1/32]FPF-14+6/16:(26,14-11)   R=  -1.1  p = 0.760     normal
  [Low1/32]FPF-14+6/16:all          R=  +0.1  p = 0.498     normal
  [Low1/32]FPF-14+6/16:cross        R=  +1.2  p = 0.128     normal
  [Low1/32]BRank(12):128(16)        R=  -0.9  p~= 0.810     normal
  [Low1/32]BRank(12):256(8)         R=  +0.6  p~= 0.250     normal
  [Low1/32]BRank(12):384(2)         R=  -0.2  p~= 0.554     normal
  [Low1/32]BRank(12):512(8)         R=  +0.1  p~= 0.470     normal
  [Low1/32]BRank(12):768(2)         R=  -1.0  p~= 0.744     normal
  [Low1/32]BRank(12):1K(4)          R=  -0.2  p~= 0.500     normal
  [Low1/32]BRank(12):1536(1)        R=  -0.7  p~= 0.689     normal
  [Low1/32]BRank(12):2K(4)          R=  +0.4  p~= 0.340     normal
  [Low1/32]BRank(12):3K(1)          R=  -0.7  p~= 0.689     normal
  [Low1/32]BRank(12):4K(2)          R=  +0.6  p~= 0.322     normal
  [Low1/32]BRank(12):6K(1)          R=  +0.4  p~= 0.366     normal
  [Low1/32]BRank(12):8K(2)          R=  +0.6  p~= 0.322     normal
  [Low1/32]BRank(12):12K(1)         R=  -0.7  p~= 0.689     normal
  [Low1/32]mod3n(5):(0,9-6)         R=  -0.3  p = 0.511     normal
  [Low1/32]mod3n(5):(1,9-6)         R=  -1.2  p = 0.710     normal
  [Low1/32]mod3n(5):(2,9-6)         R=  -1.2  p = 0.726     normal
  [Low1/32]mod3n(5):(3,9-6)         R=  +0.9  p = 0.268     normal
  [Low1/32]mod3n(5):(4,9-6)         R=  -3.4  p =1-5.3e-3   normal
  [Low1/32]mod3n(5):(5,9-6)         R=  -1.1  p = 0.696     normal
  [Low1/32]mod3n(5):(6,9-6)         R=  +0.3  p = 0.373     normal
  [Low1/32]mod3n(5):(7,9-6)         R=  -0.7  p = 0.612     normal
  [Low1/32]mod3n(5):(8,9-6)         R=  -1.3  p = 0.737     normal
  [Low1/32]mod3n(5):(9,9-6)         R=  +0.0  p = 0.438     normal
  [Low1/32]mod3n(5):(10,9-6)        R=  -1.9  p = 0.857     normal
  [Low1/32]mod3n(5):(11,9-6)        R=  -1.1  p = 0.698     normal
  [Low1/32]mod3n(5):(12,9-6)        R=  +2.0  p = 0.135     normal
  [Low1/32]mod3n(5):(13,9-6)        R=  -1.5  p = 0.780     normal
  [Low1/32]mod3n(5):(14,9-6)        R=  -0.3  p = 0.519     normal
  [Low1/32]mod3n(5):(15,9-6)        R=  -2.8  p = 0.971     normal
  [Low1/32]TMFn(2+0):wl             R=  +1.0  p~= 0.4       normal
  [Low1/32]TMFn(2+1):wl             R=  +0.5  p~= 0.4       normal
  [Low1/32]TMFn(2+2):wl             R=  -1.5  p~= 0.7       normal
  [Low1/32]TMFn(2+3):wl             R=  -2.0  p~= 0.8       normal
  [Low1/32]TMFn(2+4):wl             R=  -0.3  p~= 0.6       normal
  [Low1/32]TMFn(2+5):wl             R=  -1.5  p~= 0.7       normal
  [Low1/32]TMFn(2+6):wl             R=  -1.2  p~= 0.7       normal
  [Low1/32]TMFn(2+7):wl             R=  -0.3  p~= 0.6       normal
  [Low1/32]TMFn(2+8):wl             R=  +0.7  p~= 0.4       normal
  [Low1/32]TMFn(2+9):wl             R=  +1.4  p~= 0.3       normal
  [Low1/32]TMFn(2+10):wl            R=  +0.6  p~= 0.4       normal
  [Low1/32]TMFn(2+11):wl            R=  -1.3  p~= 0.7       normal
```

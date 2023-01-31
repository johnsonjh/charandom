<!--
SPDX-License-Identifier: ISC
scspell-id: abe0e313-a0f8-11ed-a28d-80ee73e9b8e7
Copyright (c) 2023 The DPS8M Development Team
-->

# ChaRandom

- ChaCha-based random number generator derived from OpenBSD `arc4random(3)`.

## Testing

- This cryptographic random generator passes NIST-SP-800-22 (Rev 1).

### ent

```
$ test 2147483647 | ent
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

#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.95e+07  |1014457751|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
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

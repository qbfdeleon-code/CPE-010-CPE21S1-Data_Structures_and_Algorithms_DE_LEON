# Activity No. 11 – Basic Algorithm Analysis
**Course:** CPE010 Data Structures and Algorithms  |  **Instructor:** Engr. Roman M. Richard

## 3. Discussion – Fill-in answers
**Searching algorithm (worst case, x.length = n)**
- Operation 1 (`i = 0`): 1 time. Operations 5 and 6 (`return`) in total: 1. Total so far: **2**
- Operation 2 (`i < x.length`): **n + 1**
- Operation 3 (`i++`): **n**
- Operation 4 (`x[i] == target`): **n**
- Total number of operations: **3n + 3**

**Doubling question:** if n doubles, the worst-case work roughly doubles (3(2n)+3 = 6n+3). The work is linearly proportional to n.

**Best case:** 1 operation (target at index 0), constant for any n.
**Average case:** (1+2+…+n)/n = (n+1)/2 comparisons, which is still linear.

## 5. Procedure
### ILO A – Worst-case analysis of `diff`
- The loop in `diff` repeats n times, and each call to `search` needs m comparisons.
- Total number of comparisons in the worst case: **m × n**
- If m = n: **n²** comparisons (n² + n if the n loop-iteration checks are also counted, which matches the graph).

**Analysis:** The graph of n² + n is a curve that grows faster and faster. From the table, n = 10 gives 110 operations, n = 20 gives 420, and n = 30 gives 930. The increase from 10 to 20 is 310, and from 20 to 30 is 510. Because the increases keep getting larger, the growth is not linear. Doubling n (10 → 20) makes the work about four times larger (110 → 420, ≈ 4×), which is the signature of a quadratic function. The n² term dominates, so the worst-case running time of `diff` is **O(n²)**. It is practical only for small inputs.

### ILO B – Flu-shot program (Binary Search)
Source code: `activity11_vaccination.cpp` (copied exactly from the manual; compiled with C++20 and runs correctly).

**Table 11-1** (my run; times vary on every run and machine, and the searched student is random each run)

| Input Size (N) | Execution Speed | Screenshot | Observation(s) |
|---|---|---|---|
| 1,000 | 1 microsecond | (paste your own screenshot) | Student (782 753) needs vaccination |
| 10,000 | 1 microsecond | (paste your own screenshot) | Same student; time almost unchanged |
| 100,000 | 2 microseconds | (paste your own screenshot) | Same student; time only slightly higher |

Sample output:
```
Time taken to search = 1 microseconds
Student (782 753) needs vaccination.
Time taken to search = 1 microseconds
Student (782 753) needs vaccination.
Time taken to search = 2 microseconds
Student (782 753) needs vaccination.
```
> Run the program on your own computer and take your own screenshot for Table 11-1. Your numbers will differ (the manual's sample shows 45, 37, 53 microseconds).

**Analysis of the outcome:** The input grew 100 times (1,000 → 100,000), yet the search time stayed in the range of a few microseconds. This matches the theoretical O(log n) of binary search: each step halves the remaining range, so about log₂(1,000) ≈ 10 steps are needed for N = 1,000 and only about log₂(100,000) ≈ 17 steps for N = 100,000. A linear search would have needed up to 100 times more comparisons. Small differences or even decreases between runs come from timer resolution, caching and system noise, because these times are so tiny. Most random students were not found in the list (the names are pairs, so there are N² possible names for N entries), so the program reports "needs vaccination", which is the worst case for binary search. The sorting and list generation are outside the timed region, so only the search is measured.

## 6. Output
Paste the screenshot of the console output of `activity11_vaccination.cpp` and Table 11-1 above.

## 7. Supplementary Activity
Source code: `activity11_supplementary.cpp`

### Problem 1: Unique(A)
**Theoretical analysis (worst case, all elements unique):** The inner comparison runs (n−1) + (n−2) + … + 1 = n(n−1)/2 times = (n² − n)/2. The dominant term is n², so the running time is **O(n²)**. Best case: A[0] equals A[1], giving 1 comparison, O(1).

**Experimental analysis** (worst case, all unique):

| n | Comparisons counted | n(n−1)/2 | Time (µs) |
|---|---|---|---|
| 1,000 | 499,500 | 499,500 | 1,399 |
| 2,000 | 1,999,000 | 1,999,000 | 5,374 |
| 4,000 | 7,998,000 | 7,998,000 | 22,524 |
| 8,000 | 31,996,000 | 31,996,000 | 88,049 |
| 16,000 | 127,992,000 | 127,992,000 | 349,348 |

**Analysis and comparison:** The counted comparisons match n(n−1)/2 exactly. Each time n doubles, the comparisons and the measured time increase by about four times (1,399 → 5,374 → 22,524 → 88,049 → 349,348), as expected for a quadratic algorithm. So the experiment confirms O(n²).

### Problem 2: rpower vs brpower
**Theoretical analysis:**
- `rpower`: T(n) = T(n−1) + c, so there are n + 1 calls, giving **O(n)** time (and O(n) stack depth).
- `brpower`: T(n) = T(n/2) + c, because the exponent is halved on every call, giving about ⌊log₂ n⌋ + 2 calls, so **O(log n)** time.

**Experimental analysis** (x = 1 to avoid overflow):

| n | rpower calls | rpower (µs) | brpower calls | brpower (µs) |
|---|---|---|---|---|
| 1,000 | 1,001 | 28 | 11 | 0 |
| 2,000 | 2,001 | 24 | 12 | 0 |
| 4,000 | 4,001 | 50 | 13 | 0 |
| 8,000 | 8,001 | 112 | 14 | 0 |
| 16,000 | 16,001 | 254 | 15 | 0 |

**Analysis and comparison:** Doubling n doubles the number of `rpower` calls (linear) but adds only one call to `brpower` (logarithmic). The measured time of `rpower` grows with n, while `brpower` is too fast to register in microseconds. Both compute the same result, but `brpower` is far more efficient.

## 8. Conclusion
**Summary of lessons learned:** Algorithm efficiency is described by how the running time grows with input size n, not by exact seconds, which depend on hardware. Theoretical analysis counts operations, giving f(n) such as 3n + 3, n², or log n, and experimental analysis uses `std::chrono` to confirm it. Constant, logarithmic, linear, n-log-n, quadratic, cubic, exponential and factorial functions are ranked by growth rate, and the dominant term decides the Big-O.

**Analysis of the procedure:** Counting operations of the linear search gave 3n + 3 (worst), 1 (best) and (n+1)/2 (average). The nested `diff` search gave n², a quadratic curve. The binary search program for the flu shot list stayed in a few microseconds even when the list grew 100 times, which confirms O(log n).

**Analysis of the supplementary activity:** Unique(A) was quadratic in both theory and experiment (about 4× per doubling). `rpower` was linear while `brpower` was logarithmic, showing that divide-and-conquer can reduce a linear algorithm to a logarithmic one.

**Concluding statement / Feedback:** (Write your own, for example:) I understood how to count operations and match them to Big-O, and the experiments agreed with the theory. I need more practice with recurrence relations and with interpreting timing results that are too small to measure reliably.

# Google HashCode 2021 Online Qualifications: Traffic signaling
Our solution for Google HashCode 2021 Online Qualifications

## Problem
You can find the problem statements [here](problem/hashcode_2021_online_qualifications.pdf).

## Solution
The code for the solution is in [src.cpp](src.cpp). Our approach was a greedy algorithm.

The solution follows these steps:

1. Read the inputs

2. Duration of green light:

   1. Counts the number of vehicles passing through the each street.

   2. Divide the counts by the weight. (The weight for each file was found by grid search)
   
3. Order of green light:

   1. sorted by number of vehicles at the beginning.



## Results
| File  | Score |
| ------------- | ------------- |
| a.txt ([input](inputs/a.txt) \| [output](outputs/a.out)) | 2,002 |
| b.txt ([input](inputs/b.txt) \| [output](outputs/b.out)) | 4,566,011 |
| c.txt ([input](inputs/c.txt) \| [output](outputs/c.out)) | 1,299,333 |
| d.txt ([input](inputs/d.txt) \| [output](outputs/d.out)) | 1,606,638 |
| e.txt ([input](inputs/e.txt) \| [output](outputs/e.out)) | 728,661 |
| f.txt ([input](inputs/f.txt) \| [output](outputs/f.out)) | 1,411,047 |
| **Total** | **9,613,692** |


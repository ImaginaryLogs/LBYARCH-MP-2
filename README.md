# LBYARCH-MP-2
A C and x86 assembly code that adds vectors together.

Screenshot of Output (with analytics and correction check):
<img width="648" height="777" alt="Kernel Testing (Both)" src="https://github.com/user-attachments/assets/07bc1acb-3b1e-4c5f-9c40-19a6b74ecc3e" />


Analysis:


A brief view of the screenshots and data show that the C version of the program generally runs faster than the Assembly equivalent, albeit often within a small marigin. The performance of both kernels were incredibly fast when the size of the vectors where within 2^20 and 2^20. But as it came closer to 20^30, the runtime for both version lengthened rapidly from less than a second to almost half a minute. Despite this, both programs execute properly and pass the correctness checks, with a margin of error of 1e-9 (0.000000001). The highest vector size was set to 2^28 as the runtime was drastically longer when it was 2^30 and consumed almost 8GB worth of memory to run.

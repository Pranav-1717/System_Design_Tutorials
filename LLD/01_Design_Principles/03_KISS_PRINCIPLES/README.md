# KISS Principle — Keep It Simple, Stupid
```
“Complexity is the enemy of execution.”
                                        – Tony Robbins
```

The KISS principle is a reminder that the simplest solution is often the best solution.

In software (and life), complexity sneaks in when we try to be “too clever.” But clever code is fragile, hard to read, and painful to maintain. Simple code? Easy to debug, easy to change.

You’re asked to find the factorial.<br>
Anti-kiss version
```c++
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int factorial(int n) {
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1); 
    return accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
}
```
Kiss version
```c++
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

---
### Real Life Examples

1. Google Search
One box. One button. Done. Behind the scenes it’s rocket science, but the interface stays simple.

2. TV Remote
Old remotes had 50+ buttons. Modern remotes (Apple TV, Firestick) have ~5. Fewer buttons = fewer headaches.

---
### How to Apply KISS

Trim the fat → Does this feature/code/step really add value?

Write for humans → Code is read 10x more than it’s written.

Build only what’s needed → Don’t add what you might need “someday.”

Prefer clarity over cleverness → A junior dev should understand it.

Iterate later → Ship the simple version first, then refine if needed.

## 🧩 1. Static Array-Based Set
> Concept: manual memory juggling and element uniqueness.

### Exercise:
Implement a set of integers (max size 100) that supports:
* insert, remove, contains, union, intersection, difference
* Automatically sorts itself after each insertion.
* Rejects duplicates (obviously).
### Challenge Mode:
* Write isSubset(A, B) without using loops inside loops.
* Optimize your union/intersection to not do redundant comparisons (e.g., use sorted merging).

## 🧩 2. Dynamic Array-Based Set
> Concept: resizing logic, memory safety, and efficiency.

### Exercise:
Make a set that:
* Grows dynamically (start with small capacity like 4, double when full).
* Supports insert, remove, contains, resize.
* Maintains order of insertion (no sorting).
### Challenge Mode:
* Implement a shrink() that halves the capacity when it’s only 25% full — without breaking anything.
* Then test with random insertions/removals to detect leaks or logic errors using valgrind.

## 🧩 3. Linked List-Based Set

> Concept: pointer manipulation hell — welcome to it.

### Exercise:
Implement a set using a singly linked list with:

* insert, remove, contains, printSet.
* Keep it sorted at all times.
### Challenge Mode:
* Implement union, intersection, and difference recursively.
* Make your insert() and remove() tail-recursive if you’re self loathing.

## 🧩 4. Bit Vector / Bit Field Set
> Concept: bitwise wizardry.

### Exercise:
Implement a set of integers from 0–63 using unsigned long long.
Functions:

* add, remove, contains
* union, intersection, difference
* printBits() that prints something like {0, 3, 5}

### Challenge Mode:

* Implement a power set generator using bit manipulation.
Example: For {0,1,2}, output all 8 subsets as {}, {0}, {1}, {0,1}, etc.
* Do all bitset operations without loops — only with bitwise operations and recursion/macros.

## 🧩 5. Enum + Bitmask Set

> Concept: readable symbolic bit vectors.

### Exercise:
Use enums to define flags, e.g.:
```
enum Permission {
    READ = 1 << 0,
    WRITE = 1 << 1,
    EXEC = 1 << 2,
    ADMIN = 1 << 3
};
```

Implement:
* grant, revoke, hasPermission, and listPermissions.

### Challenge Mode:

* Implement a permission inheritance system:
e.g., if a user has ADMIN, they automatically have READ, WRITE, EXEC.
* Build a function compareUsers(a, b) that prints what permissions differ between them.

## 🧠 Bonus “Insanity Mode”
> Combine all knowledge into one monster:

* Implement a hybrid set: bit-vector for small values (0–63) and linked list for values beyond that.
* Operations like union and intersection must handle both parts seamlessly.
* If you can make that work correctly and efficiently, you’re officially better than half of undergrad CS majors.
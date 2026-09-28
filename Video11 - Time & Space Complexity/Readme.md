Big-O Notation (Time & Space Complexity)

📌 What is Big-O?

Big-O notation describes how the time or space required by an algorithm grows as the input size ("n") increases.

- It focuses on worst-case performance
- Ignores constants and lower-order terms
- Helps compare efficiency of algorithms

---

⏱️ Time Complexity Table

Big-O| Name| Example Algorithms| Description

O(1)| Constant| Array access| Always takes the same time

O(log n)| Logarithmic| Binary Search| Problem size halves each step

O(n)| Linear| Linear Search| Time grows with input size

O(n log n)| Linearithmic| Merge Sort, Quick Sort| Efficient sorting

O(n²)| Quadratic| Bubble Sort| Nested loops

O(n³)| Cubic| Matrix operations| Triple nested loops

O(2ⁿ)| Exponential| Recursive Fibonacci| Doubles each step

O(n!)| Factorial| Permutations| All possible arrangements

---

📦 Space Complexity Table

Big-O| Usage Example| Description

O(1)| Variables only| Fixed memory usage

O(n)| Array / Vector| Memory grows with input

O(n²)| Matrix| 2D storage

O(log n)| Recursion stack| Divide and conquer

---

📊 Complexity Ranking (Best → Worst)

O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)

---

🧠 How to Identify Time Complexity

1️⃣ Single Loop → O(n)

for(int i = 0; i < n; i++) {
    // constant work
}

---

2️⃣ Nested Loops → O(n²)

for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        // constant work
    }
}

---

3️⃣ Halving Input → O(log n)

int start = 0, end = n - 1;

while(start <= end) {
    int mid = (start + end) / 2;

    if(arr[mid] == key) return mid;
    else if(arr[mid] < key) start = mid + 1;
    else end = mid - 1;
}

---

4️⃣ Divide & Conquer → O(n log n)

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // merge step takes O(n)
    }
}

---

5️⃣ Exponential Recursion → O(2ⁿ)

int fib(int n) {
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

---

⚡ Important Notes

- Drop constants:
  
  O(2n) → O(n)

- Drop smaller terms:
  
  O(n² + n) → O(n²)

- Always consider worst case

---

🎯 Interview Tips

- Aim for:
  
  - Best: O(1), O(log n)
  - Good: O(n), O(n log n)

- Avoid:
  
  - O(n²) for large inputs
  - O(2ⁿ), O(n!) unless required

---

🔥 Quick Summary

- Loop → O(n)
- Nested loop → O(n²)
- Divide by 2 → O(log n)
- Recursion tree → often O(2ⁿ)

---

📌 Final Thought

The goal is not just to solve the problem,
but to solve it efficiently 🚀
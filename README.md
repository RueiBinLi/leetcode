# LeetCode Solving Record

這個 repository 用來記錄 LeetCode 解題程式碼、解題思路與複習狀態。

## Environment

- C++20 with Clang/LLVM
- clang-format for formatting
- CodeLLDB for debugging
- Python 3 for Python solutions and repository tooling

## Organization

Problems are grouped into inclusive ranges of 1,000 IDs. Each problem keeps its
primary runnable solution in `main.cpp` or `main.py`, structured information in
`meta.json`, optional study notes in `notes.md`, and additional approaches in
`alternatives/`.

```text
problems/
├── 0001-1000/
│   └── 0001_Two_Sum/
├── 1001-2000/
├── 2001-3000/
└── 3001-4000/
```

Topics live in metadata instead of directory names because one problem can belong
to several topics.

## Workflow

Create a solution folder:

```sh
python3 tools/leetcode.py new 347 "Top K Frequent Elements" \
  --difficulty medium --topics array,hash-table,heap
```

Regenerate this README after editing metadata:

```sh
python3 tools/leetcode.py index
```

Validate directory placement, metadata, languages, and the generated index:

```sh
python3 tools/leetcode.py check
```

Metadata accepts `easy`, `medium`, or `hard` for difficulty and `solved`,
`review`, or `mastered` for study status. Unknown imported historical values are
stored as `null` instead of being guessed.

## Problems

<!-- PROBLEM_INDEX_START -->
**Total: 103** · Solved: 100 · Review: 3 · Mastered: 0

| ID | Problem | Difficulty | Topics | Language | Status | Solved |
| ---: | --- | --- | --- | --- | --- | --- |
| 0001 | [Two Sum](problems/0001-1000/0001_Two_Sum) | — | — | cpp | solved | — |
| 0002 | [Add Two Numbers](problems/0001-1000/0002_Add_Two_Numbers) | — | — | cpp | solved | — |
| 0003 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) ([code](problems/0001-1000/0003_Longest_Substring_Without_Repeating_Characters)) | medium | Hash Table, String, Sliding Window, Set | cpp | solved | 2025-06-27 |
| 0004 | [Median of Two Sorted Arrays](problems/0001-1000/0004_Median_of_Two_Sorted_Arrays) | — | — | cpp | solved | — |
| 0005 | [Longest Palindromic Substring](problems/0001-1000/0005_Longest_Palindromic_Substring) | — | — | cpp | solved | — |
| 0006 | [Zigzag Conversion](problems/0001-1000/0006_Zigzag_Conversion) | — | — | cpp | solved | — |
| 0007 | [Reverse Integer](problems/0001-1000/0007_Reverse_Integer) | — | — | cpp | solved | — |
| 0008 | [String to Integer atoi](problems/0001-1000/0008_String_to_Integer_atoi) | — | — | cpp | solved | — |
| 0009 | [Palindrome Number](problems/0001-1000/0009_Palindrome_Number) | — | — | cpp | solved | — |
| 0010 | [Regular Expression Matching](problems/0001-1000/0010_Regular_Expression_Matching) | — | — | cpp | solved | — |
| 0011 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) ([code](problems/0001-1000/0011_Container_With_Most_Water)) | medium | Array, Two Pointers, Greedy | cpp | solved | 2026-03-29 |
| 0012 | [Integer to Roman](problems/0001-1000/0012_Integer_to_Roman) | — | — | cpp | solved | — |
| 0013 | [Roman to Integer](problems/0001-1000/0013_Roman_to_Integer) | — | — | cpp | solved | — |
| 0014 | [Longest Common Prefix](problems/0001-1000/0014_Longest_Common_Prefix) | — | — | cpp | solved | — |
| 0015 | [3Sum](https://leetcode.com/problems/3sum/) ([code](problems/0001-1000/0015_3Sum)) | medium | Array, Two Pointers, Sort | cpp | solved | 2026-03-13 |
| 0016 | [3Sum Closest](problems/0001-1000/0016_3Sum_Closest) | — | — | cpp | solved | — |
| 0017 | [Letter Combinations of a Phone Number](problems/0001-1000/0017_Letter_Combinations_of_a_Phone_Number) | — | — | cpp | solved | — |
| 0018 | [4Sum](https://leetcode.com/problems/4sum/) ([code](problems/0001-1000/0018_4Sum)) | medium | Array, Two Pointers, Sort | cpp | solved | 2026-03-13 |
| 0019 | [Remove Nth Node From End of List](problems/0001-1000/0019_Remove_Nth_Node_From_End_of_List) | — | — | cpp | solved | — |
| 0020 | [Valid Parentheses](problems/0001-1000/0020_Valid_Parentheses) | — | — | cpp, python | solved | — |
| 0021 | [Merge Two Sorted Lists](problems/0001-1000/0021_Merge_Two_Sorted_Lists) | — | — | cpp | solved | — |
| 0046 | [Permutations](https://leetcode.com/problems/permutations/) ([code](problems/0001-1000/0046_Permutations)) | medium | Array, Backtracking | python | solved | 2025-07-11 |
| 0070 | [Climbing Stairs](problems/0001-1000/0070_Climbing_Stairs) | — | — | cpp | solved | — |
| 0092 | [Reverse Linked List II](problems/0001-1000/0092_Reverse_Linked_List_II) | — | — | cpp | solved | — |
| 0100 | [Same Tree](problems/0001-1000/0100_Same_Tree) | — | — | cpp | solved | — |
| 0101 | [Symmetric Tree](problems/0001-1000/0101_Symmetric_Tree) | — | — | cpp | solved | — |
| 0104 | [Maximum Depth Of Binary Tree](problems/0001-1000/0104_Maximum_Depth_Of_Binary_Tree) | — | — | cpp | solved | — |
| 0110 | [Balanced Binary Tree](problems/0001-1000/0110_Balanced_Binary_Tree) | — | — | cpp | solved | — |
| 0141 | [Linked List Cycle](problems/0001-1000/0141_Linked_List_Cycle) | — | — | cpp | solved | — |
| 0142 | [Linked List Cycle II](problems/0001-1000/0142_Linked_List_Cycle_II) | — | — | cpp | solved | — |
| 0151 | [Reverse Words in a String](problems/0001-1000/0151_Reverse_Words_in_a_String) | — | — | cpp | solved | — |
| 0200 | [Number of Islands](https://leetcode.com/problems/number-of-islands/) ([code](problems/0001-1000/0200_Number_of_Islands)) | medium | Array, DFS, BFS, Union Find, Matrix | python | solved | 2025-07-11 |
| 0203 | [Remove Linked List](problems/0001-1000/0203_Remove_Linked_List) | — | — | cpp | solved | — |
| 0206 | [Reverse Linked List](problems/0001-1000/0206_Reverse_Linked_List) | — | — | cpp | solved | — |
| 0207 | [Course Schedule](problems/0001-1000/0207_Course_Schedule) | — | — | cpp | solved | — |
| 0226 | [Invert Binary Tree](problems/0001-1000/0226_Invert_Binary_Tree) | — | — | cpp | solved | — |
| 0234 | [Palindrome Linked List](problems/0001-1000/0234_Palindrome_Linked_List) | — | — | cpp | solved | — |
| 0238 | [Product of Array Except Self](problems/0001-1000/0238_Product_of_Array_Except_Self) | — | — | cpp | solved | — |
| 0283 | [Move Zeroes](problems/0001-1000/0283_Move_Zeroes) | — | — | cpp | solved | — |
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) ([code](problems/0001-1000/0300_Longest_Increasing_Subsequence)) | medium | Array, Binary Search, Dynamic Programming, Longest Increasing Subsequence | cpp | solved | 2026-08-15 |
| 0328 | [Odd Even Linked List](problems/0001-1000/0328_Odd_Even_Linked_List) | — | — | cpp | solved | — |
| 0334 | [Increasing Triplet Subsequence](problems/0001-1000/0334_Increasing_Triplet_Subsequence) | — | — | cpp | solved | — |
| 0338 | [Counting Bits](problems/0001-1000/0338_Counting_Bits) | — | — | cpp | solved | — |
| 0345 | [Reverse Vowels of a String](problems/0001-1000/0345_Reverse_Vowels_of_a_String) | — | — | cpp | solved | — |
| 0368 | [Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/) ([code](problems/0001-1000/0368_Largest_Divisible_Subset)) | medium | Array, Math, Dynamic Programming, Sort | cpp | review | 2025-04-06 |
| 0382 | [Linked List Random Node](problems/0001-1000/0382_Linked_List_Random_Node) | — | — | cpp | solved | — |
| 0392 | [Is Subsequence](problems/0001-1000/0392_Is_Subsequence) | — | — | cpp | solved | — |
| 0416 | [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) ([code](problems/0001-1000/0416_Partition_Equal_Subset_Sum)) | medium | Array, Dynamic Programming | cpp | review | 2025-04-07 |
| 0443 | [String Compression](problems/0001-1000/0443_String_Compression) | — | — | cpp | solved | — |
| 0543 | [Diameter Of Binary Tree](problems/0001-1000/0543_Diameter_Of_Binary_Tree) | — | — | cpp | solved | — |
| 0563 | [Binary Tree Tilt](problems/0001-1000/0563_Binary_Tree_Tilt) | — | — | cpp | solved | — |
| 0605 | [Can Place Flowers](problems/0001-1000/0605_Can_Place_Flowers) | — | — | cpp | solved | — |
| 0643 | [Maximum Average Subarray I](problems/0001-1000/0643_Maximum_Average_Subarray_I) | — | — | cpp | solved | — |
| 0700 | [Search in a Binary Search Tree](problems/0001-1000/0700_Search_in_a_Binary_Search_Tree) | — | — | cpp | solved | — |
| 0707 | [Design Linked List](problems/0001-1000/0707_Design_Linked_List) | — | — | cpp | solved | — |
| 0724 | [Find Pivot Index](problems/0001-1000/0724_Find_Pivot_Index) | — | — | cpp | solved | — |
| 0735 | [Asteroid Collision](problems/0001-1000/0735_Asteroid_Collision) | — | — | cpp | solved | — |
| 0817 | [Linked List Components](problems/0001-1000/0817_Linked_List_Components) | — | — | cpp | solved | — |
| 0841 | [Keys and Rooms](problems/0001-1000/0841_Keys_and_Rooms) | — | — | cpp | solved | — |
| 0876 | [Middle Of Linked List](problems/0001-1000/0876_Middle_Of_Linked_List) | — | — | cpp | solved | — |
| 0933 | [Number of Recent Calls](https://leetcode.com/problems/number-of-recent-calls/) ([code](problems/0001-1000/0933_Number_of_Recent_Calls)) | easy | Design, Queue, Data Stream | python | solved | 2025-07-11 |
| 0997 | [Find the Town Judge](problems/0001-1000/0997_Find_the_Town_Judge) | — | — | cpp | solved | — |
| 1004 | [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) ([code](problems/1001-2000/1004_Max_Consecutive_Ones_III)) | medium | Array, Binary Search, Sliding Window, Prefix Sum | cpp | solved | 2025-04-11 |
| 1071 | [Greatest Common Divisor of Strings](problems/1001-2000/1071_Greatest_Common_Divisor_of_Strings) | — | — | cpp | solved | — |
| 1123 | [Lowest Common Ancestor of Deepest Leaves](problems/1001-2000/1123_Lowest_Common_Ancestor_of_Deepest_Leaves) | — | — | cpp | solved | — |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) ([code](problems/1001-2000/1143_Longest_Common_Subsequence)) | medium | String, Dynamic Programming, Longest Common Subsequence | cpp | solved | 2026-08-15 |
| 1295 | [Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/) ([code](problems/1001-2000/1295_Find_Numbers_with_Even_Number_of_Digits)) | easy | Array, Math | cpp | solved | 2025-04-30 |
| 1358 | [Number of Substrings Containing All Three Characters](problems/1001-2000/1358_Number_of_Substrings_Containing_All_Three_Characters) | — | — | cpp | solved | — |
| 1385 | [Find the Distance Value Between Two Arrays](https://leetcode.com/problems/find-the-distance-value-between-two-arrays/) ([code](problems/1001-2000/1385_Find_the_Distance_Value_Between_Two_Arrays)) | easy | Array, Two Pointers, Binary Search, Sort | cpp | solved | 2026-08-22 |
| 1431 | [Kids With the Greatest Number of Candies](problems/1001-2000/1431_Kids_With_the_Greatest_Number_of_Candies) | — | — | cpp | solved | — |
| 1456 | [Maximum Number of Vowels in a Substring of Given Length](problems/1001-2000/1456_Maximum_Number_of_Vowels_in_a_Substring_of_Given_Length) | — | — | cpp | solved | — |
| 1534 | [Count Good Triplets](https://leetcode.com/problems/count-good-triplets/) ([code](problems/1001-2000/1534_Count_Good_Triplets)) | easy | Array, Enumeration | cpp | solved | 2025-04-14 |
| 1732 | [Find the Highest Altitude](problems/1001-2000/1732_Find_the_Highest_Altitude) | — | — | cpp | solved | — |
| 1768 | [Merge Strings Alternately](problems/1001-2000/1768_Merge_Strings_Alternately) | — | — | cpp | solved | — |
| 1780 | [Check if Number is a Sum of Powers of Three](problems/1001-2000/1780_Check_if_Number_is_a_Sum_of_Powers_of_Three) | — | — | cpp | solved | — |
| 1863 | [Sum of All Subset XOR Totals](problems/1001-2000/1863_Sum_of_All_Subset_XOR_Totals) | — | — | cpp | solved | — |
| 1922 | [Count Good Numbers](https://leetcode.com/problems/count-good-numbers/) ([code](problems/1001-2000/1922_Count_Good_Numbers)) | medium | Math, Recursion | cpp | solved | 2025-04-13 |
| 2014 | [Longest Subsequence Repeated k Times](https://leetcode.com/problems/longest-subsequence-repeated-k-times/) ([code](problems/2001-3000/2014_Longest_Subsequence_Repeated_k_Times)) | hard | String, Backtracking, Greedy, Counting, Enumeration | cpp | review | 2025-06-27 |
| 2140 | [Solving Questions With Brainpower](problems/2001-3000/2140_Solving_Questions_With_Brainpower) | — | — | cpp | solved | — |
| 2161 | [Partition Array According to Given Pivot](problems/2001-3000/2161_Partition_Array_According_to_Given_Pivot) | — | — | cpp | solved | — |
| 2206 | [Divide Array Into Equal Pairs](problems/2001-3000/2206_Divide_Array_Into_Equal_Pairs) | — | — | cpp | solved | — |
| 2215 | [Find the Difference of Two Arrays](problems/2001-3000/2215_Find_the_Difference_of_Two_Arrays) | — | — | cpp | solved | — |
| 2226 | [Maximum Candies Allocated to K Children](problems/2001-3000/2226_Maximum_Candies_Allocated_to_K_Children) | — | — | cpp | solved | — |
| 2300 | [Successful Pairs of Spells and Potions](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/) ([code](problems/2001-3000/2300_Successful_Pairs_of_Spells_and_Potions)) | medium | Array, Two Pointers, Binary Search, Sort | cpp | solved | 2026-08-23 |
| 2379 | [Minimum Recolors to Get K Consecutive Black Blocks](problems/2001-3000/2379_Minimum_Recolors_to_Get_K_Consecutive_Black_Blocks) | — | — | cpp | solved | — |
| 2390 | [Removing Stars From a String](problems/2001-3000/2390_Removing_Stars_From_a_String) | — | — | cpp | solved | — |
| 2401 | [Longest Nice Subarray](problems/2001-3000/2401_Longest_Nice_Subarray) | — | — | cpp | solved | — |
| 2460 | [Apply Operations to an Array](problems/2001-3000/2460_Apply_Operations_to_an_Array) | — | — | cpp | solved | — |
| 2523 | [Closest Prime Numbers in Range](problems/2001-3000/2523_Closest_Prime_Numbers_in_Range) | — | — | cpp | solved | — |
| 2529 | [Maximum Count of Positive Integer and Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/) ([code](problems/2001-3000/2529_Maximum_Count_of_Positive_Integer_and_Negative_Integer)) | easy | Array, Binary Search, Counting | cpp | solved | 2026-08-23 |
| 2570 | [Merge Two 2D Arrays by Summing Values](problems/2001-3000/2570_Merge_Two_2D_Arrays_by_Summing_Values) | — | — | cpp | solved | — |
| 2579 | [Count Total Number of Colored Cells](problems/2001-3000/2579_Count_Total_Number_of_Colored_Cells) | — | — | cpp | solved | — |
| 2685 | [Count the Number of Complete Components](problems/2001-3000/2685_Count_the_Number_of_Complete_Components) | — | — | cpp | solved | — |
| 2843 | [Count Symmetric Integers](https://leetcode.com/problems/count-symmetric-integers/) ([code](problems/2001-3000/2843_Count_Symmetric_Integers)) | easy | Math, Enumeration | cpp | solved | 2025-04-11 |
| 2873 | [Maximum Value of an Ordered Triplet I](problems/2001-3000/2873_Maximum_Value_of_an_Ordered_Triplet_I) | — | — | cpp | solved | — |
| 2874 | [Maximum Value of an Ordered Triplet II](problems/2001-3000/2874_Maximum_Value_of_an_Ordered_Triplet_II) | — | — | cpp | solved | — |
| 2962 | [Count Subarrays Where Max Element Appears at Least K Times](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/) ([code](problems/2001-3000/2962_Count_Subarrays_Where_Max_Element_Appears_at_Least_K_Times)) | medium | Array, Sliding Window | cpp | solved | 2025-04-29 |
| 2965 | [Find Missing and Repeated Values](problems/2001-3000/2965_Find_Missing_and_Repeated_Values) | — | — | cpp | solved | — |
| 3169 | [Count Days Without Meetings](problems/3001-4000/3169_Count_Days_Without_Meetings) | — | — | cpp | solved | — |
| 3191 | [Minimum Operations to Make Binary Array Elements Equal to One I](problems/3001-4000/3191_Minimum_Operations_to_Make_Binary_Array_Elements_Equal_to_One_I) | — | — | cpp | solved | — |
| 3208 | [Alternating Groups II](problems/3001-4000/3208_Alternating_Groups_II) | — | — | cpp | solved | — |
| 3375 | [Minimum Operations to Make Array Values Equal to K](https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/) ([code](problems/3001-4000/3375_Minimum_Operations_to_Make_Array_Values_Equal_to_K)) | easy | Array, Hash Table | cpp | solved | 2025-04-09 |
| 3396 | [Minimum Number of Operations to Make Elements in Array Distinct](https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/) ([code](problems/3001-4000/3396_Minimum_Number_of_Operations_to_Make_Elements_in_Array_Distinct)) | easy | Array, Hash Table | cpp | solved | 2025-04-08 |
<!-- PROBLEM_INDEX_END -->

<h2><a href="https://leetcode.com/problems/single-number">136. Single Number</a></h2><h3>Easy</h3><hr><p>Given a <strong>non-empty</strong>&nbsp;array of integers <code>nums</code>, every element appears <em>twice</em> except for one. Find that single one.</p>

<p>You must&nbsp;implement a solution with a linear runtime complexity and use&nbsp;only constant&nbsp;extra space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,2,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,1,2,1,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>


## Solution

We have an array where every number shows up exactly twice, except for one number that appears only once. Our job is to find that unique number.

The straightforward part is finding which number doesn't have a pair. The tricky part is the constraint: we need O(n) time and O(1) space. That rules out sorting (O(n log n)) and hash maps (O(n) space). So we need something cleverer.

The key observation here is that this problem is fundamentally about pairing. Every number has a partner except one. If we could somehow cancel out all the pairs, we'd be left with the answer.

Key Constraints:
nums.length <= 3 * 10^4 → Even O(n^2) would be roughly 9 * 10^8 operations, which is borderline. O(n) is ideal.
-3 * 10^4 <= nums[i] <= 3 * 10^4 → Values can be negative, so index-based tricks won't work directly.
Every element appears exactly twice except one → This is the structural guarantee we can exploit.

## Approach 1: Brute Force (Nested Loops)
Intuition
The most natural approach: for each element, check whether it has a duplicate somewhere else in the array. If no duplicate exists, that's our answer.

We pick each element one by one and scan the rest of the array looking for a match. If we finish scanning without finding one, we've found the single number.

Algorithm
For each element nums[i], set a flag indicating no duplicate has been found.
For each other element nums[j] where j != i, check if nums[i] == nums[j].
If a match is found, mark that a duplicate exists and break the inner loop.
If no match was found after the inner loop completes, return nums[i].

## Complexity Analysis

Time Complexity: O(n^2). For each of the n elements, we scan up to n elements looking for a duplicate. In the worst case, the single number is at the end, so we do roughly n * n comparisons.
Space Complexity: O(1). We only use a boolean flag and loop variables. No extra data structures.

## Approach 2: Hash Map (Count Occurrences)
Intuition
Instead of rescanning the array for every element, we can count how many times each number appears using a hash map. Then we just find the number with a count of 1.

This trades space for time. A single pass to build the frequency map, another pass to find the element that appears once. Much better than nested loops.

Algorithm
Create a hash map to store the count of each number.
Iterate through the array. For each number, increment its count in the map.
Iterate through the map and return the number whose count is 1.

Why does this work?

A hash map gives us O(1) average-time lookups and insertions. By recording each element's frequency in a single pass, we avoid the redundant comparisons of the brute force approach. The second pass through the map (which has at most (n+1)/2 entries) quickly identifies the element with count 1.

## Complexity Analysis

Time Complexity: O(n). One pass to build the map, one pass to find the single element. Both are O(n).
Space Complexity: O(n). The hash map stores up to (n+1)/2 unique elements, which is O(n).

## Approach 3: XOR (Bit Manipulation)
Intuition
This is where bit manipulation shines. The XOR operator has three properties that make it perfect for this problem:

Self-cancellation: a ^ a = 0 (any number XOR'd with itself becomes 0)
Identity: a ^ 0 = a (any number XOR'd with 0 stays the same)
Commutativity and Associativity: The order doesn't matter. a ^ b ^ a = a ^ a ^ b = 0 ^ b = b
So if we XOR all elements together, every pair cancels out to 0, and we're left with just the single number. It's like magic, except it's math.

Algorithm
Initialize a variable result to 0.
XOR every element in the array with result.
After the loop, result holds the single number.

## Complexity Analysis

Time Complexity: O(n). We iterate through the array exactly once, performing a constant-time XOR at each step.
Space Complexity: O(1). We only use a single integer variable result. No extra data structures needed.

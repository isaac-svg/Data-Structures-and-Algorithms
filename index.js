function binarySearch(arr, target) {
  let low = 0;
  let high = arr.length - 1;
  while (low <= high) {
    let midpoint = low + Math.floor((high - low) / 2);
    let value = arr[midpoint];
    if (target === value) {
      return midpoint;
    } else if (target < value) {
      high = midpoint - 1;
    } else if (target > value) {
      low = midpoint - 1;
    }
  }
  return -1;
}
/**
 *
 * @param {*array of intergers} arr
 * @param {*} low
 * @param {*} high
 * @param {*} target
 * @returns index of target if found else -1
 *
 * time Complexity O(logn)
 * space Complexity O(logn)
 */
function binarySearchRecurssive(arr, low, high, target) {
  // base case
  if (low > high) {
    return -1;
  }

  let mid = low + Math.floor((high - low) / 2);
  if (arr[mid] === target) {
    return mid;
  } else if (arr[mid] < target) {
    return binarySearchRecurssive(arr, low, mid + 1, target);
  } else {
    return binarySearchRecurssive(arr, mid - 1, high, target);
  }
}

// Given an array of n numbers, print the duplicate elements in the array.
/**
 * First approach: Exhaustive search or Brute force, for each element in array find if there is some other
element with the same value. This is done using two for loop, first loop to select the element and second
loop to find its duplicate entry.

time Complexity O(n^2) 
space Complexity O(1) 
 */

/**
 * BUBBLE SORT
 *
 * @param {number[]} nums
 */

function bubbleSort(nums) {
  for (let i = 0; i < nums.length; i++) {
    for (let j = 0; j < nums.length - 1 - i; j++) {
      if (nums[j] > nums[j + 1]) {
        [nums[j], nums[j + 1]] = [nums[j + 1], nums[j]];
      }
    }
  }
}
/**
 * Modified (improved) Bubble-Sort
When there is no more swap in one pass of the outer loop. It indicates that all the elements are already in
order so we should stop sorting. This sorting improvement in Bubble-Sort is extremely useful when we
know that, except few elements rest of the array is already sorted.
 * 
 * @param {number[]} nums 
 */
function modifiedBubbleSort(nums) {
  let swapped = true;
  for (let i = 0; i < nums.length && swapped; i++) {
    swapped = false;
    for (let j = 0; j < nums.length; j++) {
      if (nums[j] > nums[j + 1]) {
        [nums[j], nums[j + 1]] = [nums[j + 1], nums[j]];
        swapped = true;
      }
    }
  }
}
function printDuplicate(arr) {
  for (let i = 0; i < arr.length; i++) {
    for (let j = 1 + i; j < arr.length; j++) {
      if (arr[i] === arr[j]) {
        console.log(arr[i]);
      }
    }
  }
}
/**Second approach: Sorting, Sort all the elements in the array and after this in a single scan, we can find the
duplicates. 

Sorting algorithms take O(n.log(n)) time and single scan take O(n) time.
The Time Complexity of an algorithm is O(n.log(n)) and Space Complexity is O(1)

*/
function printDuplicate2(arr) {
  sortArr(arr);

  let i;
  let size = arr.length;
  for (i = 1; i < size; i++) {
    if (arr[i] === arr[i - 1]) {
      console.log(arr[i]);
    }
  }
} /**Third approach: Hash-Table, using Hash-Table, we can keep track of the elements we have already seen
and we can find the duplicates in just one scan. */

function printDuplicate3(arr) {
  let i;
  let map = new Map();
  for (i = 0; i < arr.length; i++) {
    if (map.has(arr[i])) {
      console.log(arr[i]);
    } else {
      map.set(arr[i], arr[i]);
    }
  }
}

// Given an array of n numbers, find the element, which appears maximum number of times.

/**First approach: Exhaustive search or Brute force, for each element in array find how many times this particular value appears in array. Keep track of the maxCount and when some element count is greater
than maxCount then update the maxCount. This is done using two for loop, first loop to select the element
and second loop to count the occurrence of that element.
The Time Complexity is O(n2), and Space Complexity is O(1)*/

function maxOccuring1(arr) {
  let max = arr[0];
  let count = 1;
  let maxCount = 1;
  for (let i = 0; i < arr.length; i++) {
    count = 1;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[i] === arr[j]) {
        count++;
      }
      if (count > maxCount) {
        maxCount = count;
        max = arr[i];
      }
    }
  }
  console.log(max);
  return max;
}
/**Second approach: Sorting, Sort all the elements in the array and after this in a single scan, we can find the
counts. Sorting algorithms take O(n.log(n)) time and single scan take O(n) time. The Time Complexity of
an algorithm is O(n.log(n)) and Space Complexity is O(1) */
function maxOccuring2(arr, size) {
  let max = arr[0],
    maxCount = 1,
    curr = arr[0],
    currCount = 1;
  let i;
  Sort(arr, size);
  for (i = 1; i < size; i++) {
    if (arr[i] == arr[i - 1]) currCount++;
    else {
      currCount = 1;
      curr = arr[i];
    }
    if (currCount > maxCount) {
      maxCount = currCount;
      max = curr;
    }
  }
  return max;
}
/**
 * Given an array of n elements. Find the majority element, which appears more than n/2 times. Return 0 in
case there is no majority element.
 */
function getMajority1(arr) {
  let count = 0;
  let maxCount = 0;
  let max = arr[0];
  let size = arr.length;
  let i, j;
  for (i = 0; i < size; i++) {
    for (j = i + 1; j < arr.length; j++) {
      if (arr[i] === arr[j]) {
        count++;
      }
      if (count > maxCount) {
        maxCount = count;
        max = arr[i];
      }
    }
  }

  if (maxCount > size / 2) {
    console.log(maxCount, size);
    return max;
  } else return 0;
}

// console.log(getMajority1(tesArr));

/**
 * Second approach: Sorting, Sort all the elements in the array. If there is a majority than the middle element
at the index n/2 must be the majority number. So just single scan can be used to find its count and see if the
majority is there or not.
Sorting algorithms take O(n.logn) time and single scan take O(n) time.
The Time Complexity of an algorithm is O(n.log n) and Space Complexity is O(1)
 */
function getMajority2(arr) {
  let majorityIndex = 0;
  let count = 1;
  let candidade;
  for (let i = 0; i < arr.length; i++) {
    if (arr[majorityIndex] == arr[i]) {
      count += 1;
    } else {
      count -= 1;
      if (count === 0) {
        majorityIndex = i;
        count = 1;
      }
    }
  }
  candidade = arr[majorityIndex];
  count = 0;
  for (let j = 0; j < arr.length; j++) {
    if (arr[j] == candidade) {
      count++;
    }
  }
  if (count > arr.length / 2) {
    return arr[majorityIndex];
  }
  return 0;
}
// const tesArr = [5, 5, 5, 1, 1, 5, 2, 2, 5, 2, 3, 5, 5];

// console.log(getMajority2(tesArr));

/**
 * Find the missing number in an Array
Given an array of n-1 elements, which are in the range of 1 to n. There are no duplicates in the array. One
of the integer is missing. Find the missing element.
 */

// don't get the question
function findMissing() {}

/**Find Pair in an Array
Given an array of n numbers, find two elements such that their sum is equal to “value”
 */

function findPair1(arr, target) {
  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      let Sum = arr[i] + arr[j];
      if (Sum == target) {
        return [arr[i], arr[j]];
      }
    }
  }
  return -1;
}

// const testArr = [1, 3, 2, 5, 4];
// console.log(findPair1(testArr, 7));

/**Second approach: Sorting, Steps are as follows:
1. Sort all the elements in the array.
2. Take two variable first and second. Variable first= 0 and second = size -1
3. Compute sum = arr[first]+arr[second]
4. If the sum is equal to the desired value, then we have the solution
5. If the sum is less than the desired value, then we will increase first
6. If the sum is greater than the desired value, then we will decrease the second
7. We repeat the above process till we get the desired pair or we get first >= second (don’t have a pair)
Sorting algorithms take O(n.log n) time and single scan take O(n) time.The Time Complexity of an algorithm is O(n.log n) and Space Complexity is O(1)
 */

function FindPair2(arr, size, value) {
  let first = 0,
    second = size - 1;
  let curr;
  Sort(arr, size);
  while (first < second) {
    curr = arr[first] + arr[second];
    if (curr == value) {
      console.log("The pair is %d, %d", arr[first], arr[second]);
      return 1;
    } else if (curr < value) first++;
    else second--;
  }
  return 0;
}

//

function FindPair3(arr, target) {
  let cache = new Map();

  for (let i = 0; i < arr.length; i++) {
    if (cache.has(arr[i])) {
      console.log(cache);
      return [arr[i], cache.get(arr[i])];
    } else {
      cache.set(target - arr[i], arr[i]);
    }
  }
  return -1;
}
// const testArr = [1, 2, 3, 4, 5];
// console.log(FindPair3(testArr, 7));
//
//  find the longest substring
const strings = [""];
function findMaxPrefix(arr) {
  let sortedArray = arr.sort();

  let cache = new Set();
  if (arr.length == 1) {
    return arr[0];
  }
  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      if (sortedArray[0][i] === sortedArray[j][i]) {
        cache.add(sortedArray[i][i], "");
      } else {
        console.log("hello");
        return ` ${Array.from(cache.keys()).join("")}`;
      }
    }
  }

  return "";
}

// console.log(findMaxPrefix(strings));

/**
 * Find the Pair in two Arrays
Given two array X and Y. Find a pair of elements (xi, yi) such that xi∈X and yi∈Y where xi+yi=value.
 */

/**
 * First approach: Exhaustive search or Brute force, loop through element xi of X and see if you can find
(value – xi) in Y. Two for loop.
The Time Complexity is O(n2) and Space Complexity is O(1)
 */
console.time("s1");

function findPairInTwo1(X, Y, target) {
  //  asuumption X and Y are of the same length

  for (let i = 0; i < X.length; i++) {
    for (let j = 0; j < Y.length; j++) {
      if (Y[j] === target - X[i]) {
        return [X[i], Y[j]];
      }
    }
  }
  return "pair not found";
}
console.timeEnd("s1");

// const tesArr1 = [1, 2, 3, 4, 5];
// const tesArr2 = [6, 7, 8, 9, 10];
// console.log(findPairInTwo1(tesArr1, tesArr2, 14));

/**
 * Second approach: Sorting, Sort all the elements in the second array Y. For each element if X you can see
if that element is there in Y by using binary search.
Sorting algorithms take O(m. log m) and searching will take O(n. log m) time.
The Time Complexity of an algorithm is O(n.log m) or O(m.log m) and Space Complexity is O(1)
 */
function findPairInTwo2() {}
/**
 * Third approach: Sorting, Steps are as follows:
1. Sort the elements of both X and Y in increasing order.
2. Take the sum of the smallest element of X and the largest element of Y.
3. If the sum is equal to value, we got our pair.
4. If the sum is smaller than value, take next element of X
5. If the sum is greater than value, take the previous element of Y
Sorting algorithms take O(n.log n) + O(m.log m) for sorting and searching will take O(n+m) time.
The Time Complexity of an algorithm is O(n.log n) Space Complexity is O(1)
 */

function findPairInTwo3(X, Y, target) {}

/**
 * Forth approach: Hash-Table, Steps are as follows:
1. Scan through all the elements in the array Y and insert them into Hashtable.
2. Now scan through all the elements of array X, let us suppose the current element is xi see if you can
find (value - xi) in the Hashtable.
3. If you find the value, you got your pair.
4. If not, then go to the next value in the array X.
Hash-Table insert and find take constant time O(1) so the total Time Complexity of the algorithm is O(n)
time. Space Complexity is also O(n)
 */
console.time("start");
function findPairInTwo4(X, Y, target) {
  let cache = new Map();
  for (let i = 0; i < X.length; i++) {
    cache.set(target - X[i], X[i]);
  }
  for (let j = 0; j < Y.length; j++) {
    if (cache.has(Y[j])) {
      return [cache.get(Y[j]), Y[j]];
    }
  }
}
console.timeEnd("start");

// const tesArr1 = [1, 2, 3, 4, 5];
// const tesArr2 = [6, 7, 8, 9, 10];
// console.log(findPairInTwo4(tesArr1, tesArr2, 14));

/**
 * Two elements whose sum is closest to zero
Given an Array of integers, both +ve and -ve. You need to find the two elements such that their sum is
closest to zero.
 */

/**
 * First approach: Exhaustive search or Brute force, for each element in array find the other element whose
value when added will give minimum absolute value. This is done using two for loop, first loop to select
the element and second loop to find the element that should be added to it so that the absolute of the sum
will be minimum or close to zero.
The Time Complexity is O(n2) and Space Complexity is O(1)
 */
console.time("closestSumToZero1");
function closestSumToZero1(arr) {
  let minSum, minFirst, minSecond, sum;
  // Inialization of variables
  minFirst = 0;
  minSecond = 1;

  // check if array size is greater than two
  if (arr.length < 2) {
    return;
  }

  minSum = Math.abs(arr[minFirst] + arr[minSecond]);
  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      sum = Math.abs(arr[i] + arr[j]);
      if (sum < minSum) {
        minFirst = i;
        minSecond = j;
        minSum = sum;
      }
    }
  }
  return [arr[minFirst], arr[minSecond]];
}
// const testData = [-1, 2, 4, -3, 9, -7, -1, 2, 4, -3, 9, -7];
// console.log(closestSumToZero1(testData));
console.timeEnd("closestSumToZero1");

/**
 * Second approach: Sorting
Steps are as follows:
1. Sort all the elements in the array.
2. Take two variable firstIndex = 0 and secondIndex = size -1
3. Compute sum = arr[firstIndex]+arr[secondIndex]
4. If the sum is equal to the 0 then we have the solution
5. If the sum is less than the 0 then we will increase first
6. If the sum is greater than the 0 then we will decrease the second
7. We repeat the above process 3 to 6, till we get the desired pair or we get first >= second
 */

function closestSumToZero2(arr) {
  let minFirst, minSecond, sum, minSum, left, right;

  //  check if array length is leaa than two

  if (arr.length < 2) {
    return;
  }

  //  sort the array
  sort(arr);

  //  inialize variables
  minFirst = 0;
  minSecond = arr.length - 1;
  minSum = Math.abs(arr[minFirst] + arr[minSecond]);

  for (left = 0; left < arr.length; left++) {
    sum = Math.abs(arr[minFirst] + arr[minSecond]);
    if (sum < minSum) {
      minSum = sum;
      minFirst = left;
      minSecond = right;
    }
    if (sum < 0) {
      left++;
    }
    if (sum > 0) {
      right--;
    } else {
      break;
    }
  }
}

/**
 * Find maxima in a bitonic array
A bitonic array comprises of an increasing sequence of integers immediately followed by a decreasing
sequence of integers. Since the elements are sorted in some order, we should go for algorithm similar to
binary search. The steps are as follows:
1. Take two variable for storing start and end index. Variable start=0 and end=size-1
2. Find the middle element of the array.
3. See if the middle element is the maxima. If yes, return the middle element.
4. Alternatively, If the middle element in increasing part, then we need to look for in mid+1 and end.
5. Alternatively, if the middle element is in the decreasing part, then we need to look in the start and mid-
1.
6. Repeat step 2 to 5 until we get the maxima.
 */

function SearchBiotinicArrayMax(arr) {
  let start = 0;
  let end = arr.length - 1;
  let maximaFound = 0;
  let mid;

  while (start <= end) {
    mid = Math.floor((start + end) / 2);
    if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
      //maxima
      maximaFound = 1;
      break;
    } else if (arr[mid - 1] < arr[mid] && arr[mid + 1] > arr[mid]) {
      //increasing
      start = mid + 1;
    } else if (arr[mid - 1] > arr[mid] && arr[mid + 1] < arr[mid]) {
      //decreasing
      end = mid - 1;
    }
  }
  if (maximaFound == 0) {
    return -1;
  }

  return arr[mid];
}
// const testData = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 6, 5, 4, 3, 2, 1, 0];
// console.log(SearchBiotinicArrayMax(testData));

/**
 * Search element in a bitonic array
A bitonic array comprises of an increasing sequence of integers immediately followed by a decreasing
sequence of integer s. To search an element in a bitonic array :
1. Find the index or maximum element in the array. By finding the end of increasing part of the array, using
modified binary search.
2. Once we have the maximum element, search the given value in increasing part of the array using binary
search.
3. If the value is not found in increasing part, search the same value in decreasing part of the array using
binary search.
 */
function SearchBiotinicArray(arr, target) {
  let mid;
  let start = 0;
  let end = arr.length - 1;
  while (start <= end) {
    mid = Math.floor((start + end) / 2);

    if (arr[mid] === target) {
      return mid;
    }
    if (arr[mid] > target) {
      start = mid + 1;
    }
    if (arr[mid] < target) {
      end = mid - 1;
    } else {
      break;
    }
  }
  return -1;
}

/**
 * Occurrence counts in sorted Array
Given a sorted array arr[] find the number of occurrences of a number.
 */

/**
 * First approach: Brute force, Traverse the array and in linear time we will get the occurrence count of the
number. This is done using one loop.
The Time Complexity is O(n) and Space Complexity is O(1).
 */
// const testData = [1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 7, 7, 14.15, 16];
console.time("brute force");
function findKeyCount1(arr, key) {
  let count = 0;
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === key) {
      count++;
    }
  }
  return count;
}
// console.log(findKeyCount1(testData, 7));
console.timeEnd("brute force");

console.time("optimised");
function findKeyCount2(arr, key) {
  // we will do binary search to find the element and then we will check for the first and last occurrence of the key using square root jump then start a linear search over the square root length

  let firstIndex;
  let lastIndex;
  let firstFoundByBinarySearch;
  let squareRoot = Math.floor(Math.sqrt(arr.length));

  let start = 0;
  let end = arr.length;
  let mid;
  while (start <= end) {
    mid = start + Math.floor((end - start) / 2);
    console.log(mid);
    if (arr[mid] == key) {
      console.log(mid, "mid", key, "key");
      break;
    }
    if (arr[mid] > key) {
      end = mid + 1;
    }
    if (arr[mid] < key) {
      start = mid - 1;
    } else {
      return "not clear";
    }
  }

  //  find first occurrence

  //  substract square  root length from the midpoint
  //  if value is less than zero start search from index 0
  firstFoundByBinarySearch = mid;
  mid = mid - squareRoot;
  while (arr[mid] === key) {
    mid = mid - squareRoot;
    if (mid < 0) {
      mid = 0;
      break;
    }
  }
  // //  for loop to walk linearly through m*(sqrt(n))
  for (let i = mid; i <= firstFoundByBinarySearch; i++) {
    if (arr[i] === key) {
      firstIndex = i;
      console.log("found first at ", firstIndex);
      break;
    }
  }
  // //  find last  occurrence

  // //  add square  root length from the midpoint
  // //  if value is greater than arr.length -1 end search at arr.lenght-1

  mid = firstFoundByBinarySearch + squareRoot;
  while (arr[mid] === key) {
    mid = mid + squareRoot;
    if (mid > arr.length - 1) {
      mid = arr.length - 1;
      break;
    }
  }
  // //  for loop to walk linearly through m*(sqrt(n))
  for (let j = firstFoundByBinarySearch; j <= mid; j++) {
    if (arr[j] !== key) {
      lastIndex = j;
      console.log("found last at ", lastIndex - 1);
      break;
    }
  }
  return Math.abs(firstIndex - lastIndex);
}
// console.log(findKeyCount2(testData, 7));
// console.timeEnd("optimised");

/**
 * Separate even and odd numbers in Array
Given an array of even and odd numbers, write a program to separate even numbers from the odd
numbers.
 */
/**
 * First approach: allocate a separate array, then scan through the given array, and fill even numbers from the
start and odd numbers from the end.
 */
function seperateEvenAndOdd1(arr) {
  const separatedArr = [];

  for (const num of arr) {
    if (num % 2 == 0) {
      separatedArr.unshift(num);
    } else {
      separatedArr.push(num);
    }
  }
  return separatedArr;
}
const testData = [2, 1, 3, 6, 7, 8, 9, 10];

console.log(seperateEvenAndOdd1(testData));

/**
 * Second approach: Algorithm is as follows.
1. Initialize the two variable left and right. Variable left=0 and right= size-1.
2. Keep increasing the left index until the element at that index is even.
3. Keep decreasing the right index until the element at that index is odd.
4. Swap the number at left and right index.
 */
function swap(a, b) {
  let temp = a;
  a = b;
  b = temp;
}

function seperateEvenAndOdd2(arr) {
  let left = 0;
  let right = arr.length - 1;

  while (left <= right) {
    if (arr[left] % 2 === 0) {
      left++;
    } else if (arr[right] % 2 === 1) {
      right--;
    } else {
      [arr[left], arr[right]] = [arr[right], arr[left]];
      left++;
      right--;
    }
  }
  return arr;
}

// console.log(seperateEvenAndOdd2(testData));

/**
 * Stock purchase-sell problem
Given an array, whose nth element is the price of the stock on nth day. You are asked to buy once and sell
once, on what date you will be buying and at what date you will be selling to get maximum profit.
Or
Given an array of numbers, you need to maximize the difference between two numbers, such that you can
subtract the number, which appear before from the number that appear after it.
 */

/*
First approach: Brute force, for each element in array find if there is some other element whose difference
is maximum. This is done using two for loop, first loop to select, buy date index and the second loop to
find its selling date entry.
The Time Complexity is O(n2) and Space Complexity is O(1)Second approach: 
*/

/**
 * Another clever solution is to keep track of the smallest value seen so far from the start.
At each point, we can find the difference and keep track of the maximum profit. This is a linear solution.
The Time Complexity of the algorithm is O(n) time. Space Complexity for creating count array is also
O(1)
 */
function maxProfit(stock) {
  let currMin = 0;
  let maxProfit = 0;
  let currProfit = 0;
  let buy = 0;
  let sell = 0;
  let i;
  for (i = 1; i <= arr.length - 1; i++) {
    if (stock[i] < stock[currMin]) {
      currMin = i;
    }
    currProfit = stock[i] - stock[currMin];
    if (currProfit > maxProfit) {
      maxProfit = currProfit;
      buy = currMin;
      sell = maxProfit;
    }
  }
}

/**
 * Given an array of 0’s and 1’s. All the 0’s come before 1’s. Write an algorithm to find the index of the first
1.
Or
You are given an array which contains either 0 or
 */

function findFirstIndex(nums) {
  let start = 0;
  let end = nums.length - 1;
  while (start <= end) {
    let midpoint = start + Math.floor((end - start) / 2);
    if (nums[midpoint - 1] == 0 && nums[midpoint] === 1) {
      return midpoint;
    } else if (nums[midpoint - 1] === 1 && nums[midpoint + 1] === 1) {
      end = midpoint - 1;
    } else {
      start = midpoint + 1;
    }
  }
}

// console.log(
//   findFirstIndex([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1])
// );

/**
 * Transform Array
How would you swap elements of an array like [a1 a2 a3 a4 b1 b2 b3 b4] to convert it into [a1 b1 a2 b2
a3 b3 a4 b4]?

Approach:
· First swap elements in the middle pair
· Next swap elements in the middle two pairs
· Next swap elements in the middle three pairs
· Iterate n-1 steps.
 */

function transformArrayAB1(nums) {
  let midpoint = Math.floor(nums.length / 2);
}

/**
 * Check if two arrays are permutation of each other
Given two integer arrays. You have to check whether they are permutation of each other.
 */

/**
 * First approach: Sorting, Sort all the elements of both the arrays and Compare each element of both the
arrays from beginning to end. If there is no mismatch, return true. Otherwise, false.
Sorting algorithms take O(n.log n) time and comparison take O(n) time.
The Time Complexity of an algorithm is O(n.log n) and Space Complexity is O(1)
 */

/**
 * Second approach: Hash-Table (Assumption: No duplicates).
Steps are:
1. Create a Hash-Table for all the elements of the first array.
2. Traverse the other array from beginning to the end and search for each element in the Hash-Table.
3. If all the elements are found in the Hash-Table, return true otherwise return false.
Hash-Table insert and find take constant time O(1) so the total Time Complexity of the algorithm is O(n)
time. Space Complexity is also O(n)
Time Complexity = O(n) (For creation of Hash-Table and look-up),
Space Complexity = O(n) (For creation of Hash-Table).
 */
function checkPermutation(nums1, nums2) {
  if (nums1.length !== nums2.length) {
    return false;
  }
  const cache = new Map();

  for (let i = 0; i < nums1.length; i++) {
    cache.set(nums1[i], "");
  }
  for (let j = 0; j < nums2.length; j++) {
    if (!cache.has(nums1[j])) return flse;
  }
  return true;
}

/**Remove duplicates in an integer array */
function removeDuplicates(nums) {
  let cache = new Set();

  for (let i = 0; i < nums.length; i++) {
    cache.add(nums[i]);
  }
  return [...cache.values()];
}
// console.log(removeDuplicates([1, 2, 3, 4, 5, 6, 7, 2, 1, 4, 5, 8, 9, 1, 3, 0]));
/**
 * Second approach: Sorting
Steps are as follows:
1. Sort the array.
2. Take two pointers. A subarray will be created with all unique elements starting from 0 to the first
pointer (The first pointer points to the last index of the subarray). The second pointer iterates through
the array from 1 to the end. Unique numbers will be copied from the second pointer location to first
pointer location and the same elements are ignored.
Time Complexity calculation :
Time to sort the array = O(nlogn).
Time to remove duplicates = O(n). Overall Time Complexity = O(nlogn).
No additional space is required so Space Complexity is O(1)
 */
function removeDuplicates2(nums) {
  let j = 0;
  let i;
  if (nums.length == 0) return 0;
  sort(nums);

  for (i = 1; i < nums.length; i++) {
    if (nums[i] != nums[j]) {
      j++;
      nums[j] = nums[i];
    }
  }
  return j + 1;
}
// console.log(removeDuplicates2([1, 1, 1, 2, 2, 3, 4, 5, 6, 6]));
/**
 * Given an array of n elements, write an algorithm to find three elements in an array whose sum is a
given value.
Hint: Try to do this problem using a brute force approach. Then try to apply the sorting approach along
with a brute force approach. The Time Complexity will be O(n2)
 */

//  DNA Sequence

function DNASequence(DNA) {
  let DNALength = DNA.length;
  let substringLength = Math.floor(DNALength / 10);
  let reminder = DNALength % 10;
  let uniqueSequence = [];
  if (substringLength == 1) {
    return DNA.substring(0, substringLength);
  }
  let cache = new Map();
  let substring;
  let lower = 0;
  let upper = 10;
  let count = 1;
  while (upper <= DNALength - reminder) {
    substring = DNA.substring(lower, upper);

    let sorted = substring.split("").sort().join("");

    if (cache.has(sorted)) {
      count += 1;
      cache.set(substring, count);
    } else {
      count = 1;
      cache.set(sorted, count);
    }
    lower += 10;
    upper += 10;
  }
  cache.forEach((value, key) => {
    if (value > 1) {
      for (let i = 0; i < value; i++) {
        uniqueSequence.push(key);
      }
    }
  });
  return uniqueSequence;
}
// console.log(DNASequence("AAAAACCCCCAAAAACCCCCAAAAACCCCCAAAAAGGGTTT"));

function aa(num) {
  let c = num;
  let d = c.toString();
  let count = 0;
  let start = 0;
  let end = d.length - 1;
  while (start <= end) {
    if (d[start] == "1") {
      count++;
    }
    if (d[end] == "1") {
      count++;
    }
    start++;
    end--;
  }
  return count;
}
// console.log(aa("0000000000000000000000001011"));

//Minimum Size SubArray Sum
function MinimumSubarray(nums) {
  let startPivot = 0;
}
// leetcode
function containsDuplicate2(nums, k) {
  let left = 0;
  let right = nums.length - 1;
  let diff;
  for (let i = 0; i <= right; i++) {
    diff = Math.abs(left - right);
    if (diff <= k) {
      return true;
    } else {
      right--;
    }
  }
  return false;
}
console.log(containsDuplicate2([1, 0, 1, 1], 1));
//leetcode
function containsDuplicate3(nums, indexDiff, valueDiff) {
  let start = 0;
  let end = nums.length - 1;
  let idxDiff;
  let valDiff;
  for (let i = 0; i < nums.length; i++) {
    idxDiff = Math.abs(end - i);
    valDiff = Math.abs(nums[start] - nums[end]);
    if (idxDiff <= valueDiff && valDiff <= valueDiff) {
      return true;
    }
    if (idxDiff > indexDiff) {
      end--;
    }
  }
}
function proffessionalRober(nums) {
  if (nums == null || nums.length == 0) {
    return 0;
  }
  if (nums.length == 1) {
    return nums[0];
  }
  if (nums.length == 2) {
    return Math.max(nums[0], nums[1]);
  }
  const robMax = [];
  robMax[0] = nums[0];
  robMax[1] = Math.max(nums[0], nums[1]);

  for (let i = 2; i < nums.length; i++) {
    robMax[i] = Math.max(nums[i] + robMax[i - 2], robMax[i - 1]);
  }
  console.log(robMax);
  return robMax[nums.length - 1];
}
console.log(proffessionalRober([1, 2, 3, 1]));

// closest sum to 0

function aaa(nums) {}

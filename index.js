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
const testArr = [1, 2, 3, 4, 5];
// console.log(FindPair3(testArr, 7));
//
//  find the longest substring
const strings = ["abc", "abc", "ab"];
function findMaxPrefix(arr) {
  let sortedArray = arr.sort();

  let cache = new Set();

  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      if (sortedArray[0][i] === sortedArray[j][i]) {
        // prefix += sortedArray[i][i];
        cache.add(sortedArray[i][i], "hello");
      } else {
        return ` ${Array.from(cache.keys()).join("")}`;
      }
    }
  }
  return ` ${Array.from(cache.keys()).join("")}`;
}

// console.log(findMaxPrefix(strings));

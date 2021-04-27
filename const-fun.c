//A5Q1
#include "const-fun.h"
#include "cs136-trace.h"
#include <assert.h>

//
// The Implementation of the function is the "const-fun.h" file

/////////////////////////////////////////////////////////////////////////////
// BLACK QUESTION

// spread(a, len) finds the difference between the largest element and the
//   smallest element in a (i.e., max - min)
// example: {1, 3, 6} => 5
// example: {1, 3, -6} => 9
// example: {1} => 0
int spread(const int a[], int len) {
  assert(len >= 0);
  assert(a);
  int max = 0;
  int min = 0;
  for (int i = 0; i < len; i++) {
    if (a[i] > max || i == 0) {
      max = a[i];
    }
    if (a[i] < min || i == 0) {
      min = a[i];
    }
  }
  return (max - min);
}



/////////////////////////////////////////////////////////////////////////////
// GOLD QUESTIONS
// unique(a, len) determines whether all of the elements of a are "unique",
//   or in other words, if there are no duplicates in a
// examples: {1, 3, 6} => true
//           {1, 3, 1} => false

bool unique(const int a[], int len) {
  assert (len >= 0);
  assert (a);
  int compare;
  for (int i = 0; i < len; i++) {
    compare = a[i];
    for (int j = i + 1; j < len; j++) {
      if (compare == a[j]) {
        return false;
      }
    }
  }
  return true;
}

// skew(a, len) finds the "skewness" of the array a, which involves
//   comparing all elements to the mean
// notes: returns 1 if more elements are higher than the mean than lower
//        returns -1 if more elements are lower than the mean than higher
//        returns 0 if there are exactly the same number of values
//          higher than the mean and lower than the mean
//        uses the "true" mean (no rounding)
// examples: {1, 3, 4} => 1
//           {1, 3, 6} => -1
//           {1} => 0


int skew(const int a[], int len) {
  assert(len >= 0);
  assert(a);
  int sum = 0;
  int mean = 0;
  int higher_mean = 0;
  int lower_mean = 0;
  for (int i = 0; i < len; i++) {
    sum += a[i];
  }
  mean = (sum * 10) / len;
  for (int j = 0; j < len; j++) {
    if ((a[j] * 10) > mean) {
      higher_mean++;
    }
    else if ((a[j] * 10) < mean) {
      lower_mean++;
    }
  }
  if (lower_mean > higher_mean) {
    return -1;
  }
  else if (higher_mean > lower_mean) {
    return 1;
  }
  else {
    return 0;
  }
}

// longest_sorted(a, len) finds the length of the longest consecutive
//   sequence or "subarray" that contains elements that are sorted
//   in either non-descending (e.g., ascending) or non-increasing order
// examples: {5, 1, 3, 6, 2} => 3 (1 <= 3 <= 6)
//           {3, 2, 2, 1} => 4 (3 >= 2 >= 2 >= 1)

int longest_sorted(const int a[], int len) {
  assert(len >= 0);
  assert(a);
  bool decr = true;
  bool incr = true;
  bool equal = true;
  int add_on_sequence = 0;
  int highest_sorted_sequence = 1;
  int sorted_sequence = 1;

  for (int i = 0; i < len; i++) {
    if (sorted_sequence > highest_sorted_sequence) {
      highest_sorted_sequence = sorted_sequence;
    }
    if (decr == true && a[i] >= a[i + 1]) {

      trace_int (sorted_sequence);
      if (a[i] == a[i + 1] && equal == true) {
        add_on_sequence++;
        equal = true;
      }
       else {
        add_on_sequence = 0;
        equal = false;
        incr = false;
      }
      sorted_sequence++;
      decr = true;
    }
    else if (incr == true && a[i] <= a[i + 1]) {

      trace_int (sorted_sequence);
      if (a[i] == a[i + 1] && equal == true) {
        add_on_sequence++;
        equal = true;
      }
      else {
        add_on_sequence = 0;
        equal = false;
        decr = false;
      }
      sorted_sequence++;
      incr = true;
    }
    else {
      if (highest_sorted_sequence < sorted_sequence) {
        highest_sorted_sequence = sorted_sequence;
        sorted_sequence = (1 + add_on_sequence);
        if (a[i] > a[i + 1]) {
          incr = false;
          decr = true;
          sorted_sequence++;
        }
        else if (a[i] < a[i + 1]) {
          incr = true;
          decr = false;
          sorted_sequence++;
        }
      }
    }
  }
  return highest_sorted_sequence;
}

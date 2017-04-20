#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
};

bool compare(Interval A, Interval B) {
  if (A.start != B.start) {
    return A.start < B.start;
  } else {
    return A.end >= B.end;
  }
}

void addInterval(vector<Interval> &out, Interval interval) {
  int last = out.size() - 1;
  // Check if not repeated interval
  if (out.empty() ||
      (out[last].start != interval.start && out[last].end != interval.end)) {
    out.push_back(interval);
  }
}

vector<Interval> merge(vector<Interval> &A) {
  vector<Interval> out;
  sort(A.begin(), A.end(), compare);
  Interval interval = A[0];

  for (int i = 1; i < A.size(); i++) {
    if (interval.start == interval.end ||
        (A[i].start > interval.start && A[i].start > interval.end)) {
      addInterval(out, interval);
      interval = A[i];
    } else if (A[i].start >= interval.start && A[i].end > interval.end) {
      // Increase interval range
      interval.end = A[i].end;
    }
    // Else it's inside the interval
  }

  addInterval(out, interval);

  return out;
}

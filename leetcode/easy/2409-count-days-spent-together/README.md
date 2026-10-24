# Count Days Spent Together

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Alice and Bob are traveling to Rome for separate business meetings.

You are given 4 strings `arriveAlice`, `leaveAlice`, `arriveBob`, and `leaveBob`. Alice will be in the city from the dates `arriveAlice` to `leaveAlice` (**inclusive**), while Bob will be in the city from the dates `arriveBob` to `leaveBob` (**inclusive**). Each will be a 5-character string in the format `"MM-DD"`, corresponding to the month and day of the date.

Return *the total number of days that Alice and Bob are in Rome together.* 

You can assume that all dates occur in the  **same**  calendar year, which is  **not**  a leap year. Note that the number of days per month can be represented as: `[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]`.

 

 **Example 1:** 

```
Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
Output: 3
Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.

```

 **Example 2:** 

```
Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
Output: 0
Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.

```

 

 **Constraints:** 

- All dates are provided in the format "MM-DD".
- Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
- The given dates are valid dates of a non-leap year.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 7.7 MB (beats 100.00%)  
**Submitted:** 2026-10-24T16:18:46.598Z  

```cpp
class Solution {
public:
    // Convert "MM-DD" into day of the year (1 - 365)
    int dateToDayOfYear(string date, int months[]) {
        int m = (date[0] - '0') * 10 + (date[1] - '0');
        int d = (date[3] - '0') * 10 + (date[4] - '0');

        int dayOfYear = d;
        for (int i = 0; i < m - 1; ++i) {
            dayOfYear += months[i];
        }
        return dayOfYear;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int aliceStart = dateToDayOfYear(arriveAlice, months);
        int aliceEnd   = dateToDayOfYear(leaveAlice, months);
        int bobStart   = dateToDayOfYear(arriveBob, months);
        int bobEnd     = dateToDayOfYear(leaveBob, months);

        // Find overlapping period
        int start = max(aliceStart, bobStart);
        int end   = min(aliceEnd, bobEnd);

        return (end >= start) ? (end - start + 1) : 0;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-days-spent-together/)
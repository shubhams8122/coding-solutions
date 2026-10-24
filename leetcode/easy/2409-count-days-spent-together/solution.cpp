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
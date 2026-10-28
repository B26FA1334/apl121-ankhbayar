# Pseudocode - Голч дүн (GPA)

## Function GradeInfo(Score, pts[], grade[], k)
```
IF Score >= 90 THEN grade[k] = "A", pts[k] = 4
ELSE IF Score >= 80 THEN grade[k] = "B", pts[k] = 3
ELSE IF Score >= 70 THEN grade[k] = "C", pts[k] = 2
ELSE IF Score >= 60 THEN grade[k] = "D", pts[k] = 1
ELSE grade[k] = "F", pts[k] = 0
```

## Main
```
1.  DECLARE variables and arrays (size 8)
2.  failCount = 0, totalCredit = 0, weighted = 0, p = 0, L = ""
3.  FOR i = 0 TO 7: used[i] = 0
4.  DO
        OUTPUT "Number of courses (3-8)"
        INPUT n
        IF n < 3 OR n > 8 THEN OUTPUT "Invalid"
    WHILE n < 3 OR n > 8
5.  FOR i = 0 TO n-1
        INPUT name[i]
        DO  INPUT credit[i]; IF credit[i] < 1 OR > 6 THEN OUTPUT "Invalid"
        WHILE credit[i] < 1 OR credit[i] > 6
        DO  INPUT score[i];  IF score[i] < 0 OR > 100 THEN OUTPUT "Invalid"
        WHILE score[i] < 0 OR score[i] > 100
        CALL GradeInfo(score[i], pts, grade, i)
        p = pts[i];  L = grade[i]
        weighted = weighted + p * credit[i]
        totalCredit = totalCredit + credit[i]
        IF L == "F" THEN failCount = failCount + 1
6.  gpa = weighted / totalCredit
7.  OUTPUT table header
    FOR i = 0 TO n-1: OUTPUT i+1, name[i], score[i], grade[i], credit[i]
8.  OUTPUT totalCredit, gpa
9.  IF gpa >= 3.5 AND failCount == 0 THEN OUTPUT "Honors student"
    ELSE OUTPUT "Normal"
10. OUTPUT "Top 3 scores"
    FOR rank = 1 TO 3
        best = -1, maxScore = -1
        FOR i = 0 TO n-1
            IF used[i] == 0 AND score[i] > maxScore THEN
                maxScore = score[i], best = i
        used[best] = 1
        OUTPUT rank, name[best], score[best]
```

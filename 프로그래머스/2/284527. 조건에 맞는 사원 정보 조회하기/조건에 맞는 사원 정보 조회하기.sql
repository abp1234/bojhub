WITH TotalScores AS (
    SELECT
        g.EMP_NO,
        SUM(g.SCORE) AS SCORE
    FROM
        HR_GRADE g
    WHERE
        g.YEAR = 2022
    GROUP BY
        g.EMP_NO
)
SELECT
    ts.SCORE,
    e.EMP_NO,
    e.EMP_NAME,
    e.POSITION,
    e.EMAIL
FROM
    TotalScores ts
JOIN
    HR_EMPLOYEES e
ON
    ts.EMP_NO = e.EMP_NO
WHERE
    ts.SCORE = (SELECT MAX(SCORE) FROM TotalScores)
ORDER BY
    e.EMP_NO;
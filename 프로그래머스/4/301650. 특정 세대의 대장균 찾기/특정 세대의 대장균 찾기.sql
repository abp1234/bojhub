-- 코드를 작성해주세요
SELECT DISTINCT
    C.ID
FROM
    ECOLI_DATA AS A
    JOIN ECOLI_DATA AS B
    ON A.ID = B.PARENT_ID
    JOIN ECOLI_DATA AS C
    ON B.ID = C.PARENT_ID
WHERE
    A.PARENT_ID IS NULL
ORDER BY
    C.ID ASC;
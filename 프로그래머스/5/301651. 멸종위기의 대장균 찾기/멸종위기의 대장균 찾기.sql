-- 코드를 작성해주세요
WITH RECURSIVE GenerationHierarchy AS(

    SELECT
        ID,
        PARENT_ID,
        1 AS GENERATION
    FROM
        ECOLI_DATA
    WHERE
        PARENT_ID IS NULL
    UNION ALL
    
    SELECT
        E.ID,
        E.PARENT_ID,
        G.GENERATION+1 AS GENERATION
    FROM
        ECOLI_DATA E
    INNER JOIN GenerationHierarchy G
    ON
        E.PARENT_ID = G.ID
),
ChildCheck AS(
    SELECT
        ID,
        GENERATION,
        CASE
            WHEN EXISTS(
                SELECT 1
                FROM ECOLI_DATA
                WHERE PARENT_ID = G.ID
            ) THEN 0
        ELSE 1
        END AS HAS_NO_CHILD
    FROM
        GenerationHierarchy G
)

SELECT
    COUNT(*) AS COUNT,
    GENERATION
FROM
    ChildCheck
WHERE
    HAS_NO_CHILD = 1
GROUP BY
    GENERATION
ORDER BY
    GENERATION ASC;
-- 코드를 작성해주세요
SELECT
    d.ID,
    d.EMAIL,
    d.FIRST_NAME,
    d.LAST_NAME
FROM
    DEVELOPERS d
WHERE
    (d.SKILL_CODE & (
        SELECT SUM(CODE)
        FROM SKILLCODES
        WHERE NAME IN('Python','C#')
    ))>0
ORDER BY
    d.ID ASC;
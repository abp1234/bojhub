-- -- FIRST_HALF 테이블 생성
-- CREATE TABLE FIRST_HALF (
--     SHIPMENT_ID INTEGER PRIMARY KEY,
--     FLAVOR TEXT,
--     TOTAL_ORDER INTEGER
-- );

-- -- 데이터 삽입
-- INSERT INTO FIRST_HALF (SHIPMENT_ID, FLAVOR, TOTAL_ORDER) VALUES
-- (101, 'chocolate', 3200),
-- (102, 'vanilla', 2800),
-- (103, 'mint_chocolate', 1700),
-- (104, 'caramel', 2600),
-- (105, 'white_chocolate', 3100),
-- (106, 'peach', 2450),
-- (107, 'watermelon', 2150),
-- (108, 'mango', 2900),
-- (109, 'strawberry', 3100),
-- (110, 'melon', 3150),
-- (111, 'orange', 2900),
-- (112, 'pineapple', 2900);

-- -- ICECREAM_INFO 테이블 생성
-- CREATE TABLE ICECREAM_INFO (
--     FLAVOR TEXT PRIMARY KEY,
--     INGREDIENT_TYPE TEXT
-- );

-- -- 데이터 삽입
-- INSERT INTO ICECREAM_INFO (FLAVOR, INGREDIENT_TYPE) VALUES
-- ('chocolate', 'sugar_based'),
-- ('vanilla', 'sugar_based'),
-- ('mint_chocolate', 'sugar_based'),
-- ('caramel', 'sugar_based'),
-- ('white_chocolate', 'sugar_based'),
-- ('peach', 'fruit_based'),
-- ('watermelon', 'fruit_based'),
-- ('mango', 'fruit_based'),
-- ('strawberry', 'fruit_based'),
-- ('melon', 'fruit_based'),
-- ('orange', 'fruit_based'),
-- ('pineapple', 'fruit_based');

SELECT a.FLAVOR
FROM FIRST_HALF AS a
LEFT JoIN ICECREAM_INFO AS b
ON a.FLAVOR = b.FLAVOR
WHERE a.TOTAL_ORDER > 3000 AND b.INGREDIENT_TYPE LIKE 'fruit_based'
ORDER BY a.TOTAL_ORDER DESC;

해당 SQL 쿼리는 다음과 같은 작업을 수행합니다:

1. **테이블과 조인**
   - `FIRST_HALF AS a`와 `ICECREAM_INFO AS b` 두 개의 테이블을 조인합니다.
   - `FIRST_HALF` 테이블은 `a`라는 별칭으로 사용됩니다.
   - `ICECREAM_INFO` 테이블은 `b`라는 별칭으로 사용됩니다.

2. **조인 조건**
   - `a.FLAVOR = b.FLAVOR` 조건을 사용하여 두 테이블을 `FLAVOR` 열을 기준으로 조인합니다.
   - 이는 `FIRST_HALF` 테이블의 `FLAVOR`와 `ICECREAM_INFO` 테이블의 `FLAVOR`가 동일한 경우에만 조인됨을 의미합니다.

3. **조건 필터링**
   - `WHERE a.TOTAL_ORDER > 3000 AND b.INGREDIENT_TYPE LIKE 'fruit_based'` 조건을 사용하여 결과를 필터링합니다.
     - `a.TOTAL_ORDER > 3000`: `FIRST_HALF` 테이블에서 `TOTAL_ORDER`가 3000을 초과하는 행만 선택합니다.
     - `b.INGREDIENT_TYPE LIKE 'fruit_based'`: `ICECREAM_INFO` 테이블에서 `INGREDIENT_TYPE`이 'fruit_based'인 행만 선택합니다.
       - `LIKE` 연산자와 `'fruit_based'` 문자열은 일치하는 패턴을 찾기 위해 사용됩니다. 이 경우 와일드카드는 없으므로 정확히 'fruit_based'와 일치하는 값만 필터링됩니다.

4. **결과 정렬**
   - `ORDER BY a.TOTAL_ORDER DESC`: 최종 결과를 `FIRST_HALF` 테이블의 `TOTAL_ORDER` 열을 기준으로 내림차순으로 정렬합니다.

따라서 이 SQL 쿼리는 'FIRST_HALF' 테이블에서 'TOTAL_ORDER'가 3000을 초과하고, 'ICECREAM_INFO' 테이블에서 'INGREDIENT_TYPE'이 'fruit_based'인 행에 대해 조인하여, 결과를 'FLAVOR' 열로 선택하고 'TOTAL_ORDER'를 내림차순으로 정렬한 후 반환합니다.
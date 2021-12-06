# Write your MySQL query statement below
with t as (
    SELECT
        class,
        count(distinct student) as cnt
    FROM
        Courses
    group by 1
)
SELECT
    class
FROM
    t
WHERE
    cnt >= 5

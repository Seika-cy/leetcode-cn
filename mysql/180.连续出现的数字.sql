--
-- @lc app=leetcode.cn id=180 lang=mysql
--
-- [180] 连续出现的数字
--
-- @lc code=start
# Write your MySQL query statement below
WITH t AS (
    SELECT
        *,
        (
            ROW_NUMBER() OVER (
                ORDER BY
                    id
            ) - ROW_NUMBER () OVER (
                PARTITION BY num
                ORDER BY
                    id
            )
        ) AS sub
    FROM
        LOGS
)
SELECT
    DISTINCT num AS ConsecutiveNums
FROM
    (
        SELECT
            num,
            count(*) AS cnt
        FROM
            t
        GROUP BY
            num,
            sub
        HAVING
            count(*) >= 3
    ) AS tt;

-- @lc code=end
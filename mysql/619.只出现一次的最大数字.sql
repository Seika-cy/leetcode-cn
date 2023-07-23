--
-- @lc app=leetcode.cn id=619 lang=mysql
--
-- [619] 只出现一次的最大数字
--
-- @lc code=start
# Write your MySQL query statement below
WITH SingleNumber AS (
    SELECT
        *,
        COUNT(*) AS cnt
    FROM
        MyNumbers
    GROUP BY
        num
)
SELECT
    MAX(num) AS num
FROM
    SingleNumber
WHERE
    cnt = 1;

-- @lc code=end
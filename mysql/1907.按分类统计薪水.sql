--
-- @lc app=leetcode.cn id=1907 lang=mysql
--
-- [1907] 按分类统计薪水
--
-- @lc code=start
# Write your MySQL query statement below
WITH t AS (
    SELECT
        income
    FROM
        Accounts
    ORDER BY
        income
)
SELECT
    'Low Salary' AS category,
    COUNT(*) AS accounts_count
FROM
    t
WHERE
    income < 20000
UNION
SELECT
    'Average Salary',
    COUNT(*)
FROM
    t
WHERE
    income >= 20000
    AND income <= 50000
UNION
SELECT
    'High Salary',
    COUNT(*)
FROM
    t
WHERE
    income > 50000;

-- @lc code=end
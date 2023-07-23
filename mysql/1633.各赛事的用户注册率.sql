--
-- @lc app=leetcode.cn id=1633 lang=mysql
--
-- [1633] 各赛事的用户注册率
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    contest_id,
    ROUND(
        COUNT(*) * 100 /(
            SELECT
                COUNT(*)
            FROM
                Users
        ),
        2
    ) AS percentage
FROM
    Register
GROUP BY
    contest_id
ORDER BY
    percentage DESC,
    contest_id;

-- @lc code=end
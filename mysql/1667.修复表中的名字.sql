--
-- @lc app=leetcode.cn id=1667 lang=mysql
--
-- [1667] 修复表中的名字
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    user_id,
    CONCAT(
        UPPER(LEFT(name, 1)),
        LOWER(RIGHT(name, CHAR_LENGTH(name) -1))
    ) AS name
FROM
    Users
ORDER BY
    user_id;

-- @lc code=end
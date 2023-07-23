--
-- @lc app=leetcode.cn id=197 lang=mysql
--
-- [197] 上升的温度
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    w1.id AS Id
FROM
    Weather AS w1,
    Weather AS w2
WHERE
    DATEDIFF(w1.recordDate, w2.recordDate) = 1
    AND w1.Temperature > w2.Temperature
ORDER BY Id;
-- @lc code=end
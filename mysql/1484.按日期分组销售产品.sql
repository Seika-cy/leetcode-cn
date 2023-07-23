--
-- @lc app=leetcode.cn id=1484 lang=mysql
--
-- [1484] 按日期分组销售产品
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product) AS products
FROM
    Activities
GROUP BY
    sell_date
ORDER BY
    sell_date;

-- @lc code=end
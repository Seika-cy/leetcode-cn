--
-- @lc app=leetcode.cn id=1327 lang=mysql
--
-- [1327] 列出指定时间段内所有的下单产品
--
-- @lc code=start
# Write your MySQL query statement below
WITH t AS (
    SELECT
        product_id,
        SUM(unit) AS unit
    FROM
        Orders
    WHERE
        order_date LIKE '%2020-02%'
    GROUP BY
        product_id
    HAVING
        SUM(unit) >= 100
)
SELECT
    p.product_name,
    t.unit
FROM
    t
    JOIN Products AS p ON p.product_id = t.product_id;

-- @lc code=end
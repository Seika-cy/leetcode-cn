--
-- @lc app=leetcode.cn id=1251 lang=mysql
--
-- [1251] 平均售价
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    Prices.product_id,
    ROUND(SUM(price * units) / SUM(units), 2) AS average_price
FROM
    UnitsSold
    INNER JOIN Prices ON UnitsSold.product_id = Prices.product_id
    AND DATEDIFF(start_date, purchase_date) <= 0
    AND DATEDIFF(end_date, purchase_date) >= 0
GROUP BY
    Prices.product_id;

-- @lc code=end 
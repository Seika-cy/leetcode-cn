--
-- @lc app=leetcode.cn id=1164 lang=mysql
--
-- [1164] 指定日期的产品价格
--
-- @lc code=start
# Write your MySQL query statement below
WITH t AS(
    SELECT
        product_id,
        MAX(change_date) AS date
    FROM
        Products
    WHERE
        change_date <= DATE('2019-08-16')
    GROUP BY
        product_id
)
SELECT
    Products.product_id AS product_id,
    Products.new_price AS price
FROM
    Products
    JOIN t ON Products.product_id = t.product_id
    AND products.change_date = t.date
UNION
SELECT
    product_id,
    10
FROM
    Products
WHERE
    product_id NOT IN (
        SELECT
            product_id
        FROM
            t
    )
ORDER BY
    product_id;

-- @lc code=end
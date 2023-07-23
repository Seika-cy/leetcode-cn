--
-- @lc app=leetcode.cn id=1045 lang=mysql
--
-- [1045] 买下所有产品的客户
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    customer_id
FROM
    Customer
    INNER JOIN Product ON Product.product_key = Customer.product_key
GROUP BY
    customer_id
HAVING
    COUNT(DISTINCT Customer.product_key) = (
        SELECT
            COUNT(*)
        FROM
            Product
    );

-- @lc code=end
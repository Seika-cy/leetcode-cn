--
-- @lc app=leetcode.cn id=1084 lang=mysql
--
-- [1084] 销售分析III
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    product_id,
    product_name
FROM
    Product
WHERE
    product_id NOT IN(
        SELECT
            Sales.product_id
        FROM
            Sales
        WHERE
            sale_date < '2019-01-01'
            OR sale_date > '2019-03-31'
    )
    AND product_id IN(
        SELECT
            Sales.product_id
        FROM
            Sales
    );

-- @lc code=end
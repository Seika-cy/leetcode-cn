--
-- @lc app=leetcode.cn id=1174 lang=mysql
--
-- [1174] 即时食物配送 II
--
-- @lc code=start
# Write your MySQL query statement below
WITH T AS(
    SELECT
        customer_id,
        MIN(order_date) AS earliest
    FROM
        Delivery
    GROUP BY
        customer_id
)
SELECT
    ROUND(
        COUNT(*) * 100 /(
            SELECT
                COUNT(*)
            FROM
                T
        ),
        2
    ) AS immediate_percentage
FROM
    Delivery
    INNER JOIN T ON T.customer_id = Delivery.customer_id
    AND earliest = order_date
WHERE
    DATEDIFF(order_date, customer_pref_delivery_date) = 0;

-- @lc code=end
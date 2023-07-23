--
-- @lc app=leetcode.cn id=1581 lang=mysql
--
-- [1581] 进店却未进行过交易的顾客
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    customer_id,
    COUNT(customer_id) AS count_no_trans
FROM
    Visits
    LEFT OUTER JOIN Transactions ON Visits.visit_id = Transactions.visit_id
WHERE
    transaction_id IS NULL
GROUP BY
    customer_id
ORDER BY customer_id;

-- @lc code=end
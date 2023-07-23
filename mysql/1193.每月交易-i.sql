--
-- @lc app=leetcode.cn id=1193 lang=mysql
--
-- [1193] 每月交易 I
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    COUNT(*) AS trans_count,
    SUM(
        CASE
            WHEN state = 'declined' THEN 0
            ELSE 1
        END
    ) AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(CASE
            WHEN state = 'declined' THEN 0
            ELSE amount
        END) AS approved_total_amount
FROM
    Transactions
GROUP BY
    month,
    country;

-- @lc code=end
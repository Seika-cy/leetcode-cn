--
-- @lc app=leetcode.cn id=1321 lang=mysql
--
-- [1321] 餐馆营业额变化增长
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    *,
    round((amount / 7), 2) AS average_amount
FROM
    (
        SELECT
            visited_on,
            SUM(amount_day) OVER (
                ORDER BY
                    visited_on ROWS 6 PRECEDING
            ) AS amount
        FROM
            (
                SELECT
                    visited_on,
                    SUM(amount) AS amount_day
                FROM
                    Customer
                GROUP BY
                    visited_on
                ORDER BY
                    visited_on
            ) AS t
        ORDER BY
            visited_on
        LIMIT
            10000000000 OFFSET 6
    ) AS tt;

-- @lc code=end
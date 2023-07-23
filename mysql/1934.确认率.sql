--
-- @lc app=leetcode.cn id=1934 lang=mysql
--
-- [1934] 确认率
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    T.user_id,
    ROUND(SUM(confirm_cnt) / COUNT(*), 2) AS confirmation_rate
FROM
    (
        SELECT
            Signups.user_id,
            (
                CASE
                    WHEN action = 'timeout'
                    OR ACTION IS NULL THEN 0
                    ELSE 1
                END
            ) AS confirm_cnt
        FROM
            Signups
            LEFT OUTER JOIN Confirmations ON Signups.user_id = Confirmations.user_id
    ) AS T
GROUP BY
    T.user_id
ORDER BY
    confirmation_rate,
    T.user_id;

-- @lc code=end
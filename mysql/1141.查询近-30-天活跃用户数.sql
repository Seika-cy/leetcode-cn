--
-- @lc app=leetcode.cn id=1141 lang=mysql
--
-- [1141] 查询近30天活跃用户数
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    activity_date AS day,
    COUNT(DISTINCT user_id ) AS active_users
FROM
    Activity
WHERE
    DATEDIFF(activity_date, DATE("2019-07-27")) <= 0
    AND DATEDIFF(activity_date, DATE("2019-07-27")) > -30
GROUP BY
    activity_date;

-- @lc code=end
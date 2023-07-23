--
-- @lc app=leetcode.cn id=1661 lang=mysql
--
-- [1661] 每台机器的进程平均运行时间
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    t1.machine_id,
    ROUND(AVG(t2.timestamp - t1.timestamp), 3) AS processing_time
FROM
    Activity AS t1,
    Activity AS t2
WHERE
    t1.machine_id = t2.machine_id
    AND t1.process_id = t2.process_id
    AND t1.activity_type = 'start'
    AND t2.activity_type = 'end'
GROUP BY
    t1.machine_id;

-- @lc code=end
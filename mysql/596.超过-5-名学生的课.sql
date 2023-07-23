--
-- @lc app=leetcode.cn id=596 lang=mysql
--
-- [596] 超过5名学生的课
--
-- @lc code=start
# Write your MySQL query statement below
WITH T AS (
    SELECT
        class,
        COUNT(student) AS student_cnt
    FROM
        Courses
    GROUP BY
        class
)
SELECT
    class
FROM
    T
WHERE
    student_cnt >= 5;

-- @lc code=end
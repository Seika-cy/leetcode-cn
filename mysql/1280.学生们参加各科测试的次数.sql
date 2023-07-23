--
-- @lc app=leetcode.cn id=1280 lang=mysql
--
-- [1280] 学生们参加各科测试的次数
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    Students.student_id,
    Students.student_name,
    Subjects.subject_name,
    COUNT(Examinations.subject_name) AS attended_exams
FROM
    Students
    INNER JOIN Subjects
    LEFT OUTER JOIN Examinations ON Students.student_id = Examinations.student_id
    AND Subjects.subject_name = Examinations.subject_name
GROUP BY
    Students.student_id,
    Subjects.subject_name
ORDER BY
    Students.student_id,
    Subjects.subject_name;

-- @lc code=end
--
-- @lc app=leetcode.cn id=577 lang=mysql
--
-- [577] 员工奖金
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    name,
    bonus
FROM
    Employee
    LEFT OUTER JOIN Bonus ON Employee.empId = Bonus.empId
WHERE
    bonus < 1000
    OR bonus IS NULL;

-- @lc code=end
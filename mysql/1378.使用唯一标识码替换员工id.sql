--
-- @lc app=leetcode.cn id=1378 lang=mysql
--
-- [1378] 使用唯一标识码替换员工ID
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    unique_id,
    name
FROM
    Employees
    LEFT OUTER JOIN EmployeeUNI ON Employees.id = EmployeeUNI.id;

-- @lc code=end
--
-- @lc app=leetcode.cn id=1789 lang=mysql
--
-- [1789] 员工的直属部门
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    employee_id,
    department_id
FROM
    Employee
WHERE
    primary_flag = 'Y'
UNION
SELECT
    employee_id,
    department_id
FROM
    Employee
GROUP BY
    employee_id
HAVING
    COUNT(*) = 1
ORDER BY 
    employee_id ;

-- @lc code=end
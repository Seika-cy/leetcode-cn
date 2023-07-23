--
-- @lc app=leetcode.cn id=185 lang=mysql
--
-- [185] 部门工资前三高的所有员工
--
-- @lc code=start
# Write your MySQL query statement below
WITH t AS (
    SELECT
        *,
        DENSE_RANK() OVER (
            PARTITION BY departmentId
            ORDER BY
                salary DESC
        ) AS rank_num
    FROM
        Employee
)
SELECT
    Department.name AS Department,
    t.name AS Employee,
    salary AS Salary
FROM
    t
    JOIN Department ON t.departmentId = Department.id
WHERE
    rank_num <= 3
ORDER BY
    departmentId,
    salary DESC;

-- @lc code=end
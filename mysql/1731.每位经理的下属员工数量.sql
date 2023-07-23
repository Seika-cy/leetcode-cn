--
-- @lc app=leetcode.cn id=1731 lang=mysql
--
-- [1731] 每位经理的下属员工数量
--
-- @lc code=start
# Write your MySQL query statement below
WITH T AS(
    SELECT
        reports_to AS employee_id,
        COUNT(*) AS reports_count
    FROM
        Employees
    WHERE
        reports_to IS NOT NULL
    GROUP BY
        reports_to
)
SELECT
    T.employee_id,
    (
        SELECT
            name
        FROM
            Employees
        WHERE
            T.employee_id = Employees.employee_id
    ) AS name,
    T.reports_count,
    ROUND(AVG(Employees.age)) AS average_age
FROM
    T,
    Employees
WHERE
    T.employee_id = Employees.reports_to
GROUP BY
    Employees.reports_to
ORDER BY
    T.employee_id;

-- @lc code=end
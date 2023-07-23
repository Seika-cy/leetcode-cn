--
-- @lc app=leetcode.cn id=570 lang=mysql
--
-- [570] 至少有5名直接下属的经理
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    name
FROM
    Employee
WHERE
    id IN (
        SELECT
            t1.managerId
        FROM
            Employee AS t1,
            Employee AS t2
        WHERE
            t1.managerId = t2.id
        GROUP BY
            t1.managerId
        HAVING
            count(t1.managerId) >= 5
    );

-- @lc code=end
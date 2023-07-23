--
-- @lc app=leetcode.cn id=176 lang=mysql
--
-- [176] 第二高的薪水
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    IFNULL (
        (
            SELECT
                salary
            FROM
                (
                    SELECT
                        *,
                        RANK() OVER(
                            ORDER BY
                                salary DESC
                        ) AS rank_num
                    FROM
                        (
                            SELECT
                                DISTINCT salary
                            FROM
                                Employee
                            ORDER BY
                                salary
                        ) AS t
                ) AS tt
            WHERE
                rank_num = 2
        ),
        NULL
    ) AS SecondHighestSalary;
-- # Write your MySQL query statement below
-- SELECT
--     IFNULL(
--         (
--             SELECT
--                 DISTINCT Salary
--             FROM
--                 Employee
--             ORDER BY
--                 Salary DESC
--             LIMIT
--                 1 OFFSET 1
--         ),
--         NULL
--     ) AS SecondHighestSalary;

-- @lc code=end
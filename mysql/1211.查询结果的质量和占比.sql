--
-- @lc app=leetcode.cn id=1211 lang=mysql
--
-- [1211] 查询结果的质量和占比
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    query_name,
    ROUND(AVG(rating / position), 2) AS quality,
    ROUND(
        AVG(
            (
                CASE
                    WHEN rating < 3 THEN 1
                    ELSE 0
                END
            ) * 100
        ),
        2
    ) AS poor_query_percentage
FROM
    Queries
GROUP BY
    query_name;

-- @lc code=end
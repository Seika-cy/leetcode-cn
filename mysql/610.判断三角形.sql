--
-- @lc app=leetcode.cn id=610 lang=mysql
--
-- [610] 判断三角形
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    *,
    (
        CASE
            WHEN x > 0
            AND y > 0
            AND z > 0
            AND x < y + z
            AND y < z + x
            AND z < x + y THEN "Yes"
            ELSE "No"
        END
    ) AS triangle
FROM
    Triangle;

-- @lc code=end
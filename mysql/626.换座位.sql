--
-- @lc app=leetcode.cn id=626 lang=mysql
--
-- [626] 换座位
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    IF(
        id % 2 = 0,
        id -1,
        IF(
            id =(
                SELECT
                    max(id)
                FROM
                    Seat
            ),
            id,
            id + 1
        )
    ) AS id,
    student
FROM
    Seat
ORDER BY
    id;
-- @lc code=end
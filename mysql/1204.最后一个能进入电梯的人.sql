--
-- @lc app=leetcode.cn id=1204 lang=mysql
--
-- [1204] 最后一个能进入电梯的人
--
-- @lc code=start
# Write your MySQL query statement below
WITH t AS(
    SELECT
        turn,
        SUM(weight) OVER(
            ORDER BY
                turn
        ) AS sum
    FROM
        Queue
)
SELECT
    person_name
FROM
    Queue
WHERE
    turn = (
        SELECT
            turn
        FROM
            (
                SELECT
                    t.turn -1 AS turn
                FROM
                    t
                WHERE
                    sum IN(
                        SELECT
                            MIN(sum)
                        FROM
                            t
                        WHERE
                            sum > 1000
                    )
                UNION
                SELECT
                    MAX(turn)
                FROM
                    Queue
                ORDER BY
                    turn
            ) AS tt
        LIMIT
            1
    );

-- @lc code=end
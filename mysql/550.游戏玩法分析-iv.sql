--
-- @lc app=leetcode.cn id=550 lang=mysql
--
-- [550] 游戏玩法分析 IV
--
-- @lc code=start
# Write your MySQL query statement below
WITH first_login AS (
    SELECT
        player_id,
        MIN(event_date) AS earliest
    FROM
        Activity
    GROUP BY
        player_id
)
SELECT
    ROUND(
        COUNT(*) /(
            SELECT
                COUNT(*)
            FROM
                first_login
        ),
        2
    ) AS fraction
FROM
    Activity AS t1,
    Activity AS t2
WHERE
    t1.player_id = t2.player_id
    AND t1.event_date IN (
        SELECT
            earliest
        FROM
            first_login
        WHERE
            first_login.player_id = t1.player_id
    )
    AND DATEDIFF(t2.event_date, t1.event_date) = 1;

-- @lc code=end
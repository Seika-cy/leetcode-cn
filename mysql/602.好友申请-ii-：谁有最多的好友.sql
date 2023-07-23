--
-- @lc app=leetcode.cn id=602 lang=mysql
--
-- [602] 好友申请 II ：谁有最多的好友
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    id,
    COUNT(*) AS num
FROM
    (
        SELECT
            requester_id AS id
        FROM
            RequestAccepted
        UNION
        ALL
        SELECT
            accepter_id AS id
        FROM
            RequestAccepted
    ) AS t
GROUP BY
    id
ORDER BY
    num DESC
LIMIT
    1;

-- @lc code=end
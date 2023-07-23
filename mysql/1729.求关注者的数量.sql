--
-- @lc app=leetcode.cn id=1729 lang=mysql
--
-- [1729] 求关注者的数量
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    user_id,
    COUNT(follower_id) AS followers_count
FROM
    Followers
GROUP BY
    user_id
ORDER BY
    user_id;

-- @lc code=end
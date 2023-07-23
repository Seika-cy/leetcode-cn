--
-- @lc app=leetcode.cn id=1341 lang=mysql
--
-- [1341] 电影评分
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    name AS results
FROM
    (
        SELECT
            name
        FROM
            MovieRating AS m
            JOIN Users AS u ON m.user_id = u.user_id
        GROUP BY
            u.user_id,
            name
        ORDER BY
            COUNT(*) DESC,
            name
        LIMIT
            1
    ) AS t1
UNION ALL
SELECT
    title
FROM
    (
        SELECT
            title
        FROM
            MovieRating AS m1
            JOIN Movies AS m2 ON m1.movie_id = m2.movie_id
        WHERE
            created_at LIKE '%2020-02%'
        GROUP BY
            m1.movie_id,
            title
        ORDER BY
            AVG(rating) DESC,
            title
        LIMIT
            1
    ) AS t2;

-- @lc code=end
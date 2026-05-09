# Write your MySQL query statement below
-- using ORDER BY and LIMIT in both SELECT statements before the UNION, which MySQL doesn’t allow
SELECT results
FROM(
    SELECT u.name AS results
    FROM Users u
    LEFT JOIN MovieRating mr
    ON mr.user_id = u.user_id
    GROUP BY u.name
    ORDER BY COUNT(mr.rating) DESC, u.name
    LIMIT 1
) AS t1

UNION ALL

SELECT results
FROM (
    SELECT m.title AS results
    FROM Movies m
    LEFT JOIN MovieRating mr
    ON mr.movie_id = m.movie_id
    WHERE mr.created_at >= '2020-02-01' AND mr.created_at < '2020-03-01'
    GROUP BY m.title
    ORDER BY AVG(mr.rating) DESC ,m.title  
    LIMIT 1
) AS t2





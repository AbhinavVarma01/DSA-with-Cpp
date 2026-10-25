(
    SELECT u.name AS results
    FROM Users u
    JOIN MovieRating m
        ON u.user_id = m.user_id
    GROUP BY u.user_id, u.name
    ORDER BY COUNT(*) DESC, u.name ASC
    LIMIT 1
)

UNION ALL

(
    SELECT mo.title AS results
    FROM Movies mo
    JOIN MovieRating mr
        ON mo.movie_id = mr.movie_id
    WHERE mr.created_at >= '2020-02-01'
      AND mr.created_at < '2020-03-01'
    GROUP BY mo.movie_id, mo.title
    ORDER BY AVG(mr.rating) DESC, mo.title ASC
    LIMIT 1
);
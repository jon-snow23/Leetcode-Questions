# Write your MySQL query statement below
(select name as results
from MovieRating m
left join Users u on u.user_id = m.user_id
group by 1
order by count(rating) desc, 1 asc
limit 1)
UNION ALL
(
select title AS results
from Movies mv
left join MovieRating m ON m.movie_id = mv.movie_id
where month(created_at) = 2 AND year(created_at) = 2020
group by 1
order by avg(rating) desc, 1 asc
limit 1
)


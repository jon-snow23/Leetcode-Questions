# Write your MySQL query statement below
with recursive cte as(
    select person_name,turn,weight as total
    from queue
    where turn=1
    union all
    select q.person_name,q.turn,q.weight+cte.total as total
    from queue q
    join cte on cte.turn+1=q.turn
    where cte.total+q.weight<=1000
)
select person_name from cte order by total desc limit 1
# Write your MySQL query statement below
select id, case 
when count(*)%2=1 and id%2= 1 and id =(select max(id) from Seat) then student 
when id%2= 0 and id then lag(student) over(order by id) 
else lead(student) over(order by id) end as student 
from Seat group by id
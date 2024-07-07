# Write your MySQL query statement below
select visited_on,
        sum(amount) over ( rows between 6 preceding and current row) as amount,
        round(avg(amount) over ( rows between 6 preceding and current row),2) as average_amount
from
(select visited_on,sum(amount) as amount
from Customer
group by visited_on ) daily_amount
order by visited_on
limit 10000000 offset 6
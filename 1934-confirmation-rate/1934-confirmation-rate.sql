select s.user_id,
case when c.time_stamp is null then 0.00
else Round(sum(action='confirmed')/count(*),2)
end as confirmation_rate
from Signups s
left  join Confirmations c
on c.user_id=s.user_id
group by s.user_id
# Write your MySQL query statement below
select a.product_id,coalesce(round(sum((units*price))/sum(units),2),0) as average_price  from Prices a
left join UnitsSold b
on a.product_id = b.product_id
and start_date <= purchase_date
and end_date >= purchase_date
group by a.product_id
# Write your MySQL query statement below
select product_name,year,price from Sales
left join Product
on Sales.product_id = Product.product_id 
where sale_id is not null;
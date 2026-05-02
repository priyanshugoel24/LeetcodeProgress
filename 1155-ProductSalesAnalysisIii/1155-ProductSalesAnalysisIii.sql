-- Last updated: 02/05/2026, 22:41:36
# Write your MySQL query statement below
select product_id, year as first_year, quantity, price from sales where (product_id, year) in (select product_id, min(year) as year from sales group by product_id);
-- Last updated: 02/05/2026, 22:44:04
# Write your MySQL query statement below
select * from cinema where mod(id, 2) = 1 and description != 'boring' order by rating desc;
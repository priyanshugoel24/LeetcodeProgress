-- Last updated: 02/05/2026, 22:46:45
# Write your MySQL query statement below
select max(e1.salary) as SecondHighestSalary
from employee e1 inner join employee e2
where e1.salary < e2.salary
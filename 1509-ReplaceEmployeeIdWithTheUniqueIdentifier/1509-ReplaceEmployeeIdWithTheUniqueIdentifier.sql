-- Last updated: 02/05/2026, 22:39:55
# Write your MySQL query statement below
select eu.unique_id as unique_id, e.name as name
from employeeuni eu
right join employees e
on eu.id = e.id;
-- Last updated: 02/05/2026, 22:37:42
# Write your MySQL query statement below
select e1.employee_id 
from employees e1
where manager_id not in (

    select e2.employee_id from employees e2
) and e1.salary < 30000
order by e1.employee_id
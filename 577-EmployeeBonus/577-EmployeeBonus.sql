-- Last updated: 02/05/2026, 22:44:18
# Write your MySQL query statement below
select name, bonus from employee e left join bonus b on e.empId = b.empId where b.bonus < 1000 or b.bonus is null
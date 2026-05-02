-- Last updated: 02/05/2026, 22:41:33
# Write your MySQL query statement below
select p.project_id, round(sum(e.experience_years) / count(distinct e.employee_id), 2) as average_years from project p left join employee e on p.employee_id = e.employee_id group by p.project_id;
-- Last updated: 02/05/2026, 22:39:12
# Write your MySQL query statement below
select *
from patients
where conditions like ('DIAB1%') or conditions like ('% DIAB1%')
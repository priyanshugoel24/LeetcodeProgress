-- Last updated: 02/05/2026, 22:44:10
# Write your MySQL query statement below
select class from courses group by class having count(class) >=5;
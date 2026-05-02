-- Last updated: 02/05/2026, 22:37:55
# Write your MySQL query statement below
select "Low Salary" as category,
count(income) as accounts_count
from accounts
where income < 20000
union
select "Average Salary" as category,
count(income) as accounts_count
from accounts
where income >= 20000 and income <= 50000
union
select "High Salary" as category,
count(income) as accounts_count
from accounts
where income > 50000
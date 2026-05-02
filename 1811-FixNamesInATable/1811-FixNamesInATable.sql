-- Last updated: 02/05/2026, 22:38:49
# Write your MySQL query statement below
select user_id, 
    concat(upper(left(name, 1)), lower(right(name, length(name) - 1))) as name
from users
order by user_id
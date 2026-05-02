-- Last updated: 02/05/2026, 22:44:06
# Write your MySQL query statement below
select *, if(x + y > z and y + z > x and x + z > y, 'Yes', 'No') as triangle
from triangle
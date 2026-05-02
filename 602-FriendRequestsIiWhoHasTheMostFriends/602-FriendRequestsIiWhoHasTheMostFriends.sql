-- Last updated: 02/05/2026, 22:44:09
# Write your MySQL query statement below
select id, count(*) as num
from (select requester_id as id 
from requestaccepted
union all

select accepter_id
from requestaccepted) as friend_count
group by id
order by num desc limit 1
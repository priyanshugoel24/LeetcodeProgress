-- Last updated: 02/05/2026, 22:38:51
# Write your MySQL query statement below
select machine_id , round(sum(case when activity_type = 'start' then timestamp*-1 else timestamp end)*1.0 / (select count(distinct process_id)), 3) as processing_time
from activity group by machine_id
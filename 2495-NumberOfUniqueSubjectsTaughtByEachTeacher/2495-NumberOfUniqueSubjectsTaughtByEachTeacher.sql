-- Last updated: 02/05/2026, 22:35:57
# Write your MySQL query statement below
select teacher_id, count( distinct subject_id) as cnt from teacher group by teacher_id;
-- Last updated: 02/05/2026, 22:41:12
# Write your MySQL query statement below
select distinct author_id as id from views where author_id = viewer_id order by author_id;
-- Last updated: 02/05/2026, 22:38:52
# Write your MySQL query statement below
select contest_id, round(count(distinct user_id) * 100/ (select count(user_id) from users), 2) as percentage from register group by contest_id order by percentage desc, contest_id;
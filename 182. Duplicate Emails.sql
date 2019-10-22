# Write your MySQL query statement below
select distinct a.Email as Email
from Person a
where a.Email in
(select Email from Person group by Email having count(Email) > 1)
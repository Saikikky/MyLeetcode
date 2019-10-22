# Write your MySQL query statement below
select a.Name as Employee
from Employee a left join Employee b
on a.ManagerId = b.Id 
where a.Salary > b.Salary

# 将两个相同的表联合查询
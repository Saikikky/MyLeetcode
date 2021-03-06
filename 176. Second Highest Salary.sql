# Write your MySQL query statement below
select IFNULL(
    (select distinct Salary from Employee 
order by Salary desc
limit 1 offset 1),null) as SecondHighestSalary



# Write your MySQL query statement below
select max(Salary) as SecondHighestSalary
from Employee where
Salary < (select max(Salary) from Employee)
# Write your MySQL query statement below
# Write your MySQL query statement below
select 
max(distinct salary) 
as secondhighestsalary 
from employee 
where salary < (select max(salary) from employee);
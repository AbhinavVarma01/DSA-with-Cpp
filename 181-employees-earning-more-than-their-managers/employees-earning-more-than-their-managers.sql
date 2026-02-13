# Write your MySQL query statement below
select e.name as Employee
from Employee e
INNER JOIN Employee m 
ON e.managerId = m.id
WHERE e.salary > m.salary
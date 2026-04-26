# Write your MySQL query statement below
select E.name, b.bonus 
from Employee as E
left join Bonus b
on E.empId = b.empId
where b.bonus < 1000 or b.bonus is NULL

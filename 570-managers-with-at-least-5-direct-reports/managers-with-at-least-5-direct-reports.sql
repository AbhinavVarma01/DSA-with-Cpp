# Write your MySQL query statement below
select name 
from Employee 
where Id in ( 
    SELECT managerid
    from Employee
    group by managerid
    having count(*) >= 5
);
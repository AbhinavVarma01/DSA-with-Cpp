# Write your MySQL query statement below
select email as Email 
from Person
GROUP by Email 
HAVING COUNT(Email) > 1;
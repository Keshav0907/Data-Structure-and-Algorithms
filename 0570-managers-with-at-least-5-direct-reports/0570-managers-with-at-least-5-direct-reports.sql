# Write your MySQL query statement below
SELECT name 
FROM Employee
WHERE id in (
SELECT managerId
FROM Employee
group by managerId
having count(id)>=5);
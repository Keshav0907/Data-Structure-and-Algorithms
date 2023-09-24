# Write your MySQL query statement below
SELECT w2.id 
FROM Weather w1 join Weather w2 ON DATEDIFF(w1.recordDate,w2.recordDate)=-1
where w2.temperature > w1.temperature;
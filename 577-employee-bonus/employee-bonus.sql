# Write your MySQL query statement below
SELECT a1.name, a2.bonus 
FROM Employee a1 
LEFT JOIN Bonus a2 ON a1.empId = a2.empId 
WHERE a2.bonus < 1000 OR a2.bonus IS NULL;
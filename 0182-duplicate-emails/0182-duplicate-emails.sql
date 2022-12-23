# Write your MySQL query statement below
SELECT DISTINCT T1.email as Email FROM Person T1, Person T2
WHERE T1.email = T2.email AND NOT T1.id = T2.id;

# Write your MySQL query statement below
SELECT DISTINCT T1.num as ConsecutiveNums FROM Logs T1, Logs T2, Logs T3
WHERE T1.id = T2.id - 1 AND T2.id - 1 = T3.id - 2 AND
T1.num = T2.num AND T2.num = T3.num;



# This will not work as multiple answers are possible :

# SELECT T1.num as ConsecutiveNums FROM Logs T1, Logs T2, Logs T3
# WHERE T1.id = T2.id - 1 AND T2.id - 1 = T3.id - 2 AND
# T1.num = T2.num AND T2.num = T3.num LIMIT 1;
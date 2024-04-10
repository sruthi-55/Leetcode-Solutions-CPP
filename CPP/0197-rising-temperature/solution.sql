SELECT today.id 
FROM Weather today, Weather yesterday
WHERE datediff(today.recordDate,yesterday.recordDate) = 1
AND today.temperature > yesterday.temperature



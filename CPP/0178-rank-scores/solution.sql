SELECT score, 
    (SELECT COUNT(DISTINCT score) 
     FROM Scores AS S1
     WHERE S1.score >= S.score) AS "rank" 
FROM Scores AS S 
ORDER BY score DESC;


SELECT 
    u.contest_id, 
    ROUND(COUNT(u.user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage 
FROM 
    Register u 
GROUP BY 
    u.contest_id 
ORDER BY 
    percentage DESC, 
    u.contest_id ASC;

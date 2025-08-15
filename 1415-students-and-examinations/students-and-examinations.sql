SELECT 
    a1.student_id, 
    a1.student_name, 
    a2.subject_name, 
    COUNT(e.subject_name) AS attended_exams
FROM Students a1
JOIN Subjects a2
LEFT JOIN Examinations e
    ON a1.student_id = e.student_id
    AND a2.subject_name = e.subject_name
GROUP BY 
    a1.student_id, 
    a1.student_name,
    a2.subject_name
ORDER BY 
    a1.student_id ASC, 
    a2.subject_name ASC;

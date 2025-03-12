SELECT 
    id, email, first_name, last_name
FROM
    developer_infos
WHERE
    skill_1 = 'python' OR skill_2 = 'python'
        OR skill_3 = 'python'
ORDER BY id ASC;
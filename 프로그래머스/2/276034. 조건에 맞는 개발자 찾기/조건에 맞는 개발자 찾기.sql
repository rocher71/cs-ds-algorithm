SELECT 
    developers.id,
    developers.email,
    developers.first_name,
    developers.last_name
FROM
    developers
WHERE
    (developers.skill_code & (SELECT 
            SUM(skillcodes.code)
        FROM
            skillcodes
        WHERE
            skillcodes.name = 'C#'
                OR skillcodes.name = 'python')) != 0
ORDER BY id ASC;
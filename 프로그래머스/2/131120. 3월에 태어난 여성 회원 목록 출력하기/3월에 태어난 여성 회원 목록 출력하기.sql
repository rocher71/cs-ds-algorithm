SELECT 
    member_id,
    member_name,
    gender,
    DATE_FORMAT(DATE_OF_BIRTH, '%Y-%m-%d') AS DATE_OF_BIRTH
FROM
    member_profile
WHERE
    MONTH(date_of_birth) = 3
        AND gender = 'W'
        AND tlno IS NOT NULL
ORDER BY member_id ASC;
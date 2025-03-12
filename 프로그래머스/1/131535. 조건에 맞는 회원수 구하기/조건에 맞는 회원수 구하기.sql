SELECT 
    COUNT(*) AS USERS
FROM
    user_info
WHERE
    YEAR(joined) = 2021
        AND age BETWEEN 20 AND 29;
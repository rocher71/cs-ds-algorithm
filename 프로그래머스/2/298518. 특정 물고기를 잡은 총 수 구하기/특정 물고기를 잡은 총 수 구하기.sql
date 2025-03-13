SELECT 
    COUNT(*) AS FISH_COUNT
FROM
    fish_info
WHERE
    fish_info.fish_type IN (SELECT 
            fish_type
        FROM
            fish_name_info
        WHERE
            fish_name = 'BASS'
                OR fish_name = 'SNAPPER')
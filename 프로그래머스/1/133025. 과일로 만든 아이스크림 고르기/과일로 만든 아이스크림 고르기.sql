SELECT DISTINCT
    first_half.flavor
FROM
    first_half,
    icecream_info
WHERE
    first_half.total_order > 3000
        AND first_half.flavor = icecream_info.flavor
        AND icecream_info.ingredient_type = 'fruit_based'
ORDER BY total_order DESC;
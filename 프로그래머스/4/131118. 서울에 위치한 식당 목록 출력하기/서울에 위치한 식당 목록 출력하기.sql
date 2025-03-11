SELECT 
    rest_id,
    rest_name,
    food_type,
    favorites,
    address,
    ROUND(AVG(RR.REVIEW_SCORE), 2) AS SCORE
FROM
    rest_info RI
        JOIN
    rest_review RR USING (rest_id)
WHERE
    address LIKE '서울%'
GROUP BY RI.REST_ID , RI.REST_NAME , RI.FOOD_TYPE , RI.FAVORITES , RI.ADDRESS
ORDER BY SCORE DESC , RI.FAVORITES DESC;

# select * from rest_review;
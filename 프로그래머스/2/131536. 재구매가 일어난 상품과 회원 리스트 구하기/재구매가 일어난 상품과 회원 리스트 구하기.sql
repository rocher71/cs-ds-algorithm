SELECT 
    user_id, product_id
FROM
    online_sale
GROUP BY USER_ID , PRODUCT_ID
HAVING COUNT(*) >= 2
ORDER BY user_id ASC , product_id DESC;
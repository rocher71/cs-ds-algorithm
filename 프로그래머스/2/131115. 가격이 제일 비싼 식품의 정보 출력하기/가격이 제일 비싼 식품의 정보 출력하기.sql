select product_id, product_name, product_cd, category, price
from (
    select *, rank() over(order by price desc) as ranking
    from food_product
) a
where a.ranking = 1

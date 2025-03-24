-- 코드를 입력하세요
SELECT date_format(sales_date, "%Y-%m-%d") as sales_date, product_id, null as user_id, sales_amount 
from offline_sale
where month(sales_date) = 3 and year(sales_date) = 2022

union all 
select date_format(sales_date, "%Y-%m-%d") as sales_date, product_id, user_id, sales_amount 
from online_sale
where month(sales_date) = 3 and year(sales_date) = 2022

order by sales_date, product_id, user_id
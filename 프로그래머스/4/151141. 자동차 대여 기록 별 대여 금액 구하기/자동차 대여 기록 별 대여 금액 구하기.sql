select d.history_id,
  FLOOR(
    CASE
      WHEN days >= 90 THEN daily_fee * days * (1 - dp_90.discount_rate / 100)
      WHEN days >= 30 THEN daily_fee * days * (1 - dp_30.discount_rate / 100)
      WHEN days >= 7  THEN daily_fee * days * (1 - dp_7.discount_rate / 100)
      ELSE daily_fee * days
    END
  ) AS FEE
from (
    select history_id,
        a.car_id, 
        datediff(end_date, start_date) + 1 as DAYS,
        car_type,
        daily_fee
    from car_rental_company_rental_history a
    join car_rental_company_car b on a.car_id = b.car_id
    where b.car_type = '트럭'
) d 
LEFT JOIN car_rental_company_discount_plan dp_7 
  ON dp_7.car_type = '트럭' AND dp_7.duration_type = '7일 이상'
LEFT JOIN car_rental_company_discount_plan dp_30 
  ON dp_30.car_type = '트럭' AND dp_30.duration_type = '30일 이상'
LEFT JOIN car_rental_company_discount_plan dp_90 
  ON dp_90.car_type = '트럭' AND dp_90.duration_type = '90일 이상'
order by FEE desc, history_id desc



select HISTORY_ID,
        CAR_ID, 
        date_format(start_date, '%Y-%m-%d') as START_DATE, 
        date_format(end_date, '%Y-%m-%d') as END_DATE,
        case
            when datediff(end_date, start_date) + 1 >= 30 then '장기 대여'
            else '단기 대여'
        end as RENT_TYPE
from car_rental_company_rental_history
where year(start_date) = 2022
    and month(start_date) = 9
order by history_id desc
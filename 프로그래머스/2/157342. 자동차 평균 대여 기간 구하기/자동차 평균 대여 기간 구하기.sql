select CAR_ID, round(avg(datediff(end_date, start_date) + 1), 1) as AVERAGE_DURATION
from car_rental_company_rental_history
group by car_id
having round(avg(datediff(end_date, start_date) + 1), 1) >= 7
order by AVERAGE_DURATION desc, car_id desc

# select *, datediff(end_date, start_date) as AVERAGE_DURATION
# from car_rental_company_rental_history
# order by car_id
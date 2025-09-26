select car_id,
case when
    sum(
        case
            when date('2022-10-16') >= start_date 
                and date('2022-10-16') <= end_date then 0
            else 1
        end
    ) = count(*) > 0 then '대여 가능'
    else '대여중'
end as AVAILABILITY
from car_rental_company_rental_history
group by car_id
order by car_id desc

# select *
# from car_rental_company_rental_history

# select car_id, 
#     min(start_date) over(partition by car_id) as min_start_date,
#     max(end_date) over(partition by car_id) as max_end_date
# from car_rental_company_rental_history
    
-- 코드를 입력하세요
# SELECT  *, floor(C.daily_fee * 30 * (100 - P.discount_rate)*0.01) as fee
select C.car_id, C.car_type, round(C.daily_fee * 30 * (100 - P.discount_rate)*0.01) as fee
from car_rental_company_car C
    join car_rental_company_rental_history H on C.car_id = H.car_id
    join CAR_RENTAL_COMPANY_DISCOUNT_PLAN P on C.car_type = P.car_type
    
where C.car_id not in (
    select car_id
    from car_rental_company_rental_history
    where end_date >= '2022-11-01' and start_date <= '2022-12-01')
    and P.duration_type = '30일 이상'
    
group by C.car_id
having (C.car_type = '세단' or C.car_type = 'SUV')
    and (fee >= 500000 and fee < 2000000)
ORDER BY FEE DESC, CAR_TYPE, CAR_ID DESC

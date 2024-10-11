-- 코드를 입력하세요
SELECT hour(datetime) as hour, count(hour(datetime)) from animal_outs
# select * from animal_outs
group by hour(datetime)
having hour >= 9 and hour < 20
order by hour

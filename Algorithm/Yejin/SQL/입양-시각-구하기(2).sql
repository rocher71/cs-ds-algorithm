set @hour = -1;

select (@hour := @hour + 1) as hour,
    (select count(hour(datetime))
    from animal_outs
    where hour(datetime) = @hour) as count
from animal_outs
where @hour < 23



# SELECT hour(datetime) as hour, count(hour(datetime))
# from animal_outs
# group by hour(datetime)
# order by hour

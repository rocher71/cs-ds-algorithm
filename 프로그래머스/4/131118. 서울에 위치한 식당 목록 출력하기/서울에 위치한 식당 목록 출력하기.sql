select i.rest_id, i.rest_name, i.food_type, i.favorites, i.address, round(avg(review_score), 2) as score
from rest_info i
join rest_review r on i.rest_id = r.rest_id
where address like "서울%"
group by i.rest_id
order by round(avg(review_score), 2) desc, favorites desc

# select * from rest_info

# select * from rest_review
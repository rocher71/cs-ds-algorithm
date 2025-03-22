select a.flavor
from first_half a
join icecream_info b on a.flavor = b.flavor
where b.ingredient_type = 'fruit_based'
group by a.flavor
having sum(total_order) > 3000
select factory_id, factory_name, address
from food_factory
where address like '강원%'
order by factory_id
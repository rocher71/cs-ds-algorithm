select c.item_id, item_name, rarity
from  (select b.item_id
    from item_info a
    join item_tree b on a.item_id = b.parent_item_id
    where rarity = 'RARE') c
join item_info d on c.item_id = d.item_id
order by c.item_id desc
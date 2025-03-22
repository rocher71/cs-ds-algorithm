select d.item_id, d.item_name, d.rarity
from item_info d
join (select b.item_id
    from item_info a
    join item_tree b on a.item_id = parent_item_id
    where rarity = 'rare') c on d.item_id = c.item_id
order by d.item_id desc
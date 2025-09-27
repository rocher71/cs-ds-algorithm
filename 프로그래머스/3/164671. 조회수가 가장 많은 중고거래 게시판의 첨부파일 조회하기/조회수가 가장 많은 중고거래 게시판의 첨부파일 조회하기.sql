select concat("/home/grep/src/", a.board_id, "/", file_id, file_name, file_ext) as FILE_PATH
from used_goods_file a
join (
    select b.board_id
    from used_goods_board b
    order by views desc
    limit 1
) c on a.board_id = c.board_id
order by file_id desc

# select *
# from used_goods_board
# order by views desc
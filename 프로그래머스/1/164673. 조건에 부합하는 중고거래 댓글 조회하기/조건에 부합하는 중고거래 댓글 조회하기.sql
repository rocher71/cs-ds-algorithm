SELECT 
    ugb.title,
    ugb.board_id,
    ugr.reply_id,
    ugr.writer_id,
    ugr.contents,
    date_format(ugr.created_date, "%Y-%m-%d") as created_date
FROM
    used_goods_board AS ugb
        JOIN
    used_goods_reply AS ugr ON (ugb.board_id = ugr.board_id)
WHERE
    YEAR(ugb.created_date) = 2022
        AND MONTH(ugb.created_date) = 10
ORDER BY ugr.created_date ASC , ugb.title ASC;
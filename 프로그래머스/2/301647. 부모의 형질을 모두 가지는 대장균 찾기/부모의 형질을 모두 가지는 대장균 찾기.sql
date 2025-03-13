SELECT 
    e1.id, e1.genotype, e2.genotype AS parent_genotype
FROM
    ecoli_data e1,
    ecoli_data e2
WHERE
    e1.parent_id = e2.id
        AND (e1.genotype & e2.genotype) = e2.genotype
ORDER BY id ASC;
SELECT 
    COUNT(*) as count
FROM
    ecoli_data
WHERE
    (((CONV(genotype, 10, 2) >> 1) & 1) != 1)
        AND (((CONV(genotype, 10, 2) & 1) = 1)
        OR (((CONV(genotype, 10, 2) >> 2) & 1) = 1));
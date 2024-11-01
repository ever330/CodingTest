-- 코드를 작성해주세요
SELECT COUNT(BIN(GENOTYPE)) AS COUNT FROM ECOLI_DATA
WHERE
    ((GENOTYPE & 4) > 0 = 1 ||
    (GENOTYPE & 1) > 0 = 1) &&
    (GENOTYPE & 2) > 0 = 0 ;
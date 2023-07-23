--
-- @lc app=leetcode.cn id=1527 lang=mysql
--
-- [1527] 患某种疾病的患者
--
-- @lc code=start
# Write your MySQL query statement below
SELECT
    patient_id,
    patient_name,
    conditions
FROM
    Patients
WHERE
    conditions LIKE '% DIAB1%' OR
    conditions LIKE 'DIAB1%'
ORDER BY
    patient_id;

-- @lc code=end
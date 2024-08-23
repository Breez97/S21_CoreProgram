SELECT
	pr1.name AS person_name1,
	pr2.name AS person_name2,
	pr1.address AS common_address
FROM
	person pr1
	JOIN person pr2 ON pr1.address = pr2.address
WHERE
	pr1.id > pr2.id;
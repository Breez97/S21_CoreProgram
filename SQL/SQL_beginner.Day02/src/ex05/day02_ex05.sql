SELECT
	pr.name
FROM
	person pr
WHERE
	gender = 'female'
	AND age > 25
ORDER BY
	name
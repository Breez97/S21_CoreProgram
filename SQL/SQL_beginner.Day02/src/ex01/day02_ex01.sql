SELECT
	missing_date :: date
FROM
	generate_series('2022-01-01' :: date, '2022-01-10', '1 day') missing_date
	LEFT JOIN (
		SELECT
			visit_date
		FROM
			person_visits
		WHERE
			person_id = 1
			OR person_id = 2
	) pv ON missing_date = pv.visit_date
WHERE
	visit_date IS NULL
ORDER BY
	visit_date;
WITH date_generator AS (
	SELECT
		generate_series('2022-01-01' :: date, '2022-01-10', '1 day') :: date AS missing_date
),
visited_persons AS (
	SELECT
		visit_date
	FROM
		person_visits
	WHERE
		person_id = 1
		OR person_id = 2
)
SELECT
	missing_date
FROM
	date_generator
	LEFT JOIN visited_persons vp ON missing_date = vp.visit_date
WHERE
	visit_date IS NULL
ORDER BY
	visit_date;
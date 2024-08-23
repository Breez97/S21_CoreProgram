SELECT
	pz.name AS pizzeria_name
FROM
	person_visits pv
	JOIN person ps ON ps.id = pv.person_id
	JOIN pizzeria pz ON pz.id = pv.pizzeria_id
	JOIN menu mn ON pz.id = mn.pizzeria_id
WHERE
	ps.name = 'Dmitriy'
	AND pv.visit_date = '2022-01-08'
	AND price < 800;
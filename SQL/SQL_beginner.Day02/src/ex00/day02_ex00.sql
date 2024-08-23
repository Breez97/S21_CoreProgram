SELECT
	pz.name,
	pz.rating
FROM
	pizzeria pz
	LEFT JOIN person_visits pv ON pv.pizzeria_id = pz.id
WHERE
	pv.pizzeria_id IS NULL;